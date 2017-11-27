#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "my_label.h"
#include "chardware.h"
#include "dialog_createcomp.h"
#include <QFileDialog>
#include "newhard.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_comboBox_currentIndexChanged(int index);


    void on_pushButton_clicked();



    void on_MBClicked();

    void on_CPU_Clicked();

    void on_VC_Clicked();

    void on_OZU1_clicked();

    void on_OZU2_clicked();

    void on_HW_clicked();

    void on_MBCh();

    void on_CPUCh();

    void on_VCCh();

    void on_OZU1Ch();

    void on_OZU2Ch();

    void on_HWCh();


    void on_listWidget_pressed(const QModelIndex &index);

    void OpenCrComSl();

    void ClearInf();





    void on_RefreshButton_clicked();

    void CreateZbComp(infForCreate);

    void NewHardOpen();

    void NewHard(DataHW,int);

    void on_DelBut_clicked();

private:
    Ui::MainWindow *ui;
    cHardList<cCPU>  ListCPU;
    cHardList<cMotherBoard>  ListMB;
    cHardList<cOZU>  ListOZU;
    cHardList<cVideoCard>  ListVC;
    cHardList<cHardDrive> ListHD;
    cHardList<cSoftware> ListSW;
    cComputer * CurrentComp;
    QLabel * lbl[6];

signals:

    void SWList(cHardList<cSoftware>);

    void Lists(cHardList<cCPU>,cHardList<cVideoCard>);



};

#endif // MAINWINDOW_H
