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


    void PrCSW(cHardList<cCPU>,cHardList<cVideoCard>);
    void ChangeLair(int,DataHW*);

    void on_buttonBox_accepted();

    void on_toolButton_clicked();

private:
    Ui::hardedit *ui;
    DataHW HW;
    cNeed Ned;
    cHardList<cCPU> ListCpu;
    cHardList<cVideoCard> ListVC;

signals:

    void TransHW(DataHW*);


};

#endif // HARDEDIT_H
