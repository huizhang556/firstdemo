#ifndef DATAIMPORT_H
#define DATAIMPORT_H

#include <QMainWindow>

namespace Ui {
class dataImport;
}

class dataImport : public QMainWindow
{
    Q_OBJECT

public:
    explicit dataImport(QWidget *parent = 0);
    ~dataImport();

private:
    Ui::dataImport *ui;
signals:
    void backtodtexport();//数据导出发出的信号

};

#endif // DATAIMPORT_H
