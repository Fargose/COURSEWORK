#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ListCPU.read("DB/CPU.txt");
    ListMB.read("DB/MBB.txt");
    ListMB.print(ui->listWidget);
    ListOZU.read("DB/OZU.txt");
    ListVC.read("DB/VC.txt");
    QPixmap MPX;
    MPX.load("Images/Comp.png");
    ui->compimage->setPixmap(MPX);
    ui->compimage->setScaledContents(true);
    CurrentComp = new cComputer();
    lbl[0] = ui->CpuImage;
    lbl[1] = ui->MBImage;
    lbl[2] = ui->VcImage;
    lbl[3] = ui->OzuImage;
    lbl[4] = ui->ozuimage2;
    connect(ui->MBImage,SIGNAL(clicked()),this,SLOT(on_MBClicked()));
    connect(ui->CpuImage,SIGNAL(clicked()),this,SLOT(on_CPU_Clicked()));
    connect(ui->VcImage,SIGNAL(clicked()),this,SLOT(on_VC_Clicked()));
    connect(ui->OzuImage,SIGNAL(clicked()),this,SLOT(on_OZU1_clicked()));
    connect(ui->ozuimage2,SIGNAL(clicked()),this,SLOT(on_OZU2_clicked()));
    ui->CpuImage->setToolTip("Відсутнє");
    ui->MBImage->setToolTip("Відсутнє");
    ui->VcImage->setToolTip("Відсутнє");
    ui->OzuImage->setToolTip("Відсутнє");
    ui->ozuimage2->setToolTip("Відсутнє");




}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    ui->ImageLabel->clear();
    ui->TextInfo->clear();
    if(index == 1)
    {
        ListCPU.print(ui->listWidget);
    }
    else if(index == 0)
    {
        ListMB.print(ui->listWidget);
    }
    else if(index == 2)
    {
        ListOZU.print(ui->listWidget);
    }
    else if(index == 3)
    {
        ListVC.print(ui->listWidget);;
    }
}

void MainWindow::on_listWidget_currentRowChanged(int currentRow)
{

    ui->ImageLabel->clear();
    ui->TextInfo->clear();
    if(ui->comboBox->currentIndex() == 1)
    {
          ListCPU.ShowInf(currentRow,ui->TextInfo,ui->ImageLabel);
    }
    else if(ui->comboBox->currentIndex() == 0)
    {
          ListMB.ShowInf(currentRow,ui->TextInfo,ui->ImageLabel);
    }
    else if(ui->comboBox->currentIndex() == 2)
    {
          ListOZU.ShowInf(currentRow,ui->TextInfo,ui->ImageLabel);
    }
    else if(ui->comboBox->currentIndex() == 3)
    {
         ListVC.ShowInf(currentRow,ui->TextInfo,ui->ImageLabel);
    }
}

void MainWindow::on_pushButton_clicked()
{
    if(ui->listWidget->currentRow() >=0)
    {
        if(ui->comboBox->currentIndex() == 1)
        {
            CurrentComp->SetCPU(ListCPU.getEl(ui->listWidget->currentRow()));
            CurrentComp->Show(lbl);
            ui->CpuImage->setToolTip(ListCPU.getEl(ui->listWidget->currentRow())->GetName());
        }
        else if(ui->comboBox->currentIndex() == 0)
        {
            CurrentComp->SetMB(ListMB.getEl(ui->listWidget->currentRow()));
            CurrentComp->Show(lbl);
            ui->MBImage->setToolTip(ListMB.getEl(ui->listWidget->currentRow())->GetName());
        }
        else if(ui->comboBox->currentIndex() == 2)
        {
            if(CurrentComp->SetOZU(ListOZU.getEl(ui->listWidget->currentRow())) == 0)
            {
                    ui->ozuimage2->setToolTip(ui->OzuImage->toolTip());
                   ui->OzuImage->setToolTip(ListOZU.getEl(ui->listWidget->currentRow())->GetName());
            }
            else
            {
               ui->OzuImage->setToolTip(ListOZU.getEl(ui->listWidget->currentRow())->GetName());
            }
            CurrentComp->Show(lbl);

        }
        else if(ui->comboBox->currentIndex() == 3)
        {
            CurrentComp->SetVC(ListVC.getEl(ui->listWidget->currentRow()));
            CurrentComp->Show(lbl);
            ui->VcImage->setToolTip(ListVC.getEl(ui->listWidget->currentRow())->GetName());
        }
    }
}


void MainWindow::on_MBClicked()
{
    if(CurrentComp->DelMB() == true)
    {
    ui->MBImage->setToolTip("Відсутнє");
    ui->ozuimage2->setToolTip("Відсутнє");
    ui->CpuImage->setToolTip("Відсутнє");
    ui->OzuImage->setToolTip("Відсутнє");
    ui->VcImage->setToolTip("Відсутнє");
    }
    CurrentComp->Show(lbl);

}

void MainWindow::on_CPU_Clicked()
{
    CurrentComp->DelCPU();
    CurrentComp->Show(lbl);
      ui->CpuImage->setToolTip("Відсутнє");
}

void MainWindow::on_VC_Clicked()
{
    CurrentComp->DelVC();
    CurrentComp->Show(lbl);
    ui->VcImage->setToolTip("Відсутнє");
}

void MainWindow::on_OZU1_clicked()
{
    CurrentComp->DelOZU(0);
    ui->OzuImage->setToolTip("Відсутнє");
    CurrentComp->Show(lbl);
}

void MainWindow::on_OZU2_clicked()
{
    CurrentComp->DelOZU(1);
    CurrentComp->Show(lbl);
    ui->ozuimage2->setToolTip("Відсутнє");
}
