#ifndef HARDEDIT_H
#define HARDEDIT_H

#include <QDialog>
#include "chardware.h"
#include <QPixmap>
#include <QFileDialog>


namespace Ui {
class hardedit;
}

class hardedit : public QDialog
{
    Q_OBJECT

public:
    explicit hardedit(QWidget *parent = 0);
    ~hardedit();

private slots:


    void PrCSW(cWareList<cCPU>,cWareList<cVideoCard>);
    void ChangeLair(int,DataHW*);

    void on_buttonBox_accepted();

    void on_toolButton_clicked();

private:
    Ui::hardedit *ui;
    DataHW HW;
    cNeed Ned;
    cWareList<cCPU> ListCpu;
    cWareList<cVideoCard> ListVC;

signals:

    void TransHW(DataHW*);


};

#endif // HARDEDIT_H
