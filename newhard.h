#ifndef NEWHARD_H
#define NEWHARD_H

#include <QDialog>
#include "chardware.h"
#include <QFileDialog>

namespace Ui {
class newhard;
}

class newhard : public QDialog
{
    Q_OBJECT

public:
    explicit newhard(QWidget *parent = 0);
    ~newhard();

private:
    Ui::newhard *ui;
    DataHW HW;
    cNeed Ned;
    cHardList<cCPU> ListCpu;
    cHardList<cVideoCard> ListVC;

signals:

    void TransInf(DataHW,int);
private slots:
    void on_toolButton_clicked();
    void on_buttonBox_accepted();
    void on_radioButton_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_5_clicked();
    void on_radioButton_3_clicked();
    void on_radioButton_4_clicked();
    void on_radioButton_6_clicked();

    void PrCSW(cHardList<cCPU>,cHardList<cVideoCard>);
};

#endif // NEWHARD_H
