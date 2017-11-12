#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "my_label.h"
#include "chardware.h"

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

    void on_listWidget_currentRowChanged(int currentRow);

    void on_pushButton_clicked();



    void on_MBClicked();

    void on_CPU_Clicked();

    void on_VC_Clicked();

    void on_OZU1_clicked();

    void on_OZU2_clicked();


private:
    Ui::MainWindow *ui;
    cHardList<cCPU>  ListCPU;
    cHardList<cMotherBoard>  ListMB;
    cHardList<cOZU>  ListOZU;
    cHardList<cVideoCard>  ListVC;
    cComputer * CurrentComp;
    QLabel * lbl[5];
};

#endif // MAINWINDOW_H
