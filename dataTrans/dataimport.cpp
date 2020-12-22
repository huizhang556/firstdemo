#include "dataimport.h"
#include "ui_dataimport.h"
#include "dataexport.h"
#include "database.h"
#include <QMessageBox>

dataImport::dataImport(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dataImport)
{
    ui->setupUi(this);
     this->setWindowTitle("数据导入");
//    this->setFixedSize(1010,760);//固定宽，高
    ui->splitter->setStretchFactor(0,4);
    ui->splitter->setStretchFactor(1,1);

    dataBase *dbWin2 = new dataBase;
    connect(ui->action_condb1,&QAction::triggered,[=]{
        dbWin2->show();
    });


    connect(ui->action_exp,&QAction::triggered,[=]{
        emit backtodtexport();
    });

    connect(ui->action_sfwexit,&QAction::triggered,[=]{
        QPushButton *okbtn1 = new QPushButton("确定");
        QPushButton *cancelbtn1 = new QPushButton("取消");
        QMessageBox *mymsgbox1 = new QMessageBox;

        mymsgbox1->setIcon(QMessageBox::Warning);
        mymsgbox1->setWindowTitle("提示");
        mymsgbox1->setText("是否退出软件？");
        mymsgbox1->addButton(okbtn1, QMessageBox::AcceptRole);
        mymsgbox1->addButton(cancelbtn1, QMessageBox::RejectRole);
        mymsgbox1->setDefaultButton(okbtn1);
        mymsgbox1->show();

        mymsgbox1->exec();//阻塞等待用户输入
        if (mymsgbox1->clickedButton()==okbtn1)//点击了OK按钮
        {
            this->close();
        }
        else{
            this->show();
        }
    });

}
dataImport::~dataImport()
{
    delete ui;
}
