#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "my_label.h"
#include "chardware.h"
#include "dialog_createcomp.h"
#include <QFileDialog>
#include "newhard.h"
#include "hardedit.h"



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


    void on_AddButton_clicked();



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

    void CreateCompOpen();

    void ClearInf();





    void on_RefreshButton_clicked();

    void CreateZbComp(infForCreate);

    void NewHardOpen();

    void NewHard(DataHW,int);

    void on_DelBut_clicked();

    void on_EditButton_clicked();

    void HWEdit(DataHW*);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_listWidget_currentRowChanged(int currentRow);

private:
    Ui::MainWindow *ui;
    cWareList<cCPU>  ListCPU;
    cWareList<cMotherBoard>  ListMB;
    cWareList<cOZU>  ListOZU;
    cWareList<cVideoCard>  ListVC;
    cWareList<cHardDrive> ListHD;
    cWareList<cSoftware> ListSW;
    cComputer * CurrentComp;
    QLabel * lbl[6];
    cQueueComp* ListComp;

signals:

    void TransSWList(cWareList<cSoftware>);

    void TransLists(cWareList<cCPU>,cWareList<cVideoCard>);

    void ChangeLair(int,DataHW*);





};

#endif // MAINWINDOW_H
