#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "chardware.h"
#include <QPixmap>

cHardList<cCPU> ListCPU;
cHardList<cMotherBoard> ListMB;
cHardList<cOZU> ListOZU;
cHardList<cVideoCard> ListVC;
QTableWidget * CurrentWidget;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    CurrentWidget = ui->TableCpu;
//    ui->TableMB->hide();
//    ui->TableOzu->hide();
//    ui->VCTable->hide();
   ListCPU.read("D:/Kursova/FerumChecker/DB/CPU.txt");
   ListCPU.print(ui->listWidget);
//    ListCPU.print(ui->TableCpu);
//    ListMB.read("D:/Kursova/FerumChecker/DB/MBB.txt");
//    ListMB.print(ui->TableMB);
//    ListOZU.read("D:/Kursova/FerumChecker/DB/OZU.txt");
//    ListOZU.print(ui->TableOzu);
//    ListVC.read("D:/Kursova/FerumChecker/DB/VC.txt");
//    ListVC.print(ui->VCTable);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_StartButton_clicked()
{




}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
//    if(index == 0)
//    {
//        CurrentWidget->hide();
//        CurrentWidget = ui->TableCpu;
//        CurrentWidget->show();
//    }
//    else if(index == 1)
//    {
//        CurrentWidget->hide();
//        CurrentWidget = ui->TableMB;
//        CurrentWidget->show();
//    }
//    else if(index == 2)
//    {
//        CurrentWidget->hide();
//        CurrentWidget = ui->TableOzu;
//        CurrentWidget->show();
//    }
//    else if(index == 3)
//    {
//        CurrentWidget->hide();
//        CurrentWidget = ui->VCTable;
//        CurrentWidget->show();
//    }
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{
    ListCPU.ShowInf(currentRow,ui->TextInfo,ui->label);;
}
