#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("FerumChecker 1.1");
    ListCPU.read("DB/CPU.txt");
    ListMB.read("DB/MBB.txt");
    ListMB.print(ui->listWidget);
    ListOZU.read("DB/OZU.txt");
    ListVC.read("DB/VC.txt");
    ListHW.read("DB/HW.txt");
    ListSW.read("DB/SW.txt");
    for(int i = 0;i < ListSW.getSize();i++)
    {
        if(!ListSW.getEl(i)->Verification(ListCPU,ListVC))
        {
            ListSW.DeleteIn(i);
            i--;
        }
    }
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
    lbl[5] = ui->HWImage;
    connect(ui->MBImage,SIGNAL(double_clicked()),this,SLOT(on_MBClicked()));
    connect(ui->MBImage,SIGNAL(clicked()),this,SLOT(on_MBCh()));
    connect(ui->CpuImage,SIGNAL(double_clicked()),this,SLOT(on_CPU_Clicked()));
    connect(ui->CpuImage,SIGNAL(clicked()),this,SLOT(on_CPUCh()));
    connect(ui->VcImage,SIGNAL(double_clicked()),this,SLOT(on_VC_Clicked()));
    connect(ui->VcImage,SIGNAL(clicked()),this,SLOT(on_VCCh()));
    connect(ui->OzuImage,SIGNAL(double_clicked()),this,SLOT(on_OZU1_clicked()));
    connect(ui->OzuImage,SIGNAL(clicked()),this,SLOT(on_OZU1Ch()));
    connect(ui->ozuimage2,SIGNAL(double_clicked()),this,SLOT(on_OZU2_clicked()));
    connect(ui->ozuimage2,SIGNAL(clicked()),this,SLOT(on_OZU2Ch()));
    connect(ui->HWImage,SIGNAL(double_clicked()),this,SLOT(on_HW_clicked()));
    connect(ui->HWImage,SIGNAL(clicked()),this,SLOT(on_HWCh()));

    ui->CpuImage->setToolTip("Відсутнє");
    ui->MBImage->setToolTip("Відсутнє");
    ui->VcImage->setToolTip("Відсутнє");
    ui->OzuImage->setToolTip("Відсутнє");
    ui->ozuimage2->setToolTip("Відсутнє");
    ui->HWImage->setToolTip("Відсутнє");
    ui->listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    CurrentComp->Show(ui->CompInformation);
    ui->CompMenu->addAction("&Підібрати компютер",this,SLOT(OpenCrComSl()));







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
        ui->pushButton->setText("Додати");
        ui->MinLabel->setText("");
        ui->BestLabel->setText("");
        ui->CheckResLabl->setText("");
        ui->SettingsLabel->setText("");
        ui->SettingsLabelNumber->setText("");
        ui->CheckResNum->setText("");

    }
    else if(index == 0)
    {
        ListMB.print(ui->listWidget);
        ui->pushButton->setText("Додати");
        ui->MinLabel->setText("");
        ui->BestLabel->setText("");
        ui->CheckResLabl->setText("");
        ui->SettingsLabel->setText("");
        ui->SettingsLabelNumber->setText("");
        ui->CheckResNum->setText("");

    }
    else if(index == 2)
    {
        ListOZU.print(ui->listWidget);
        ui->pushButton->setText("Додати");
        ui->MinLabel->setText("");
        ui->BestLabel->setText("");
        ui->CheckResLabl->setText("");
        ui->SettingsLabel->setText("");
        ui->SettingsLabelNumber->setText("");
        ui->CheckResNum->setText("");

    }
    else if(index == 3)
    {
        ListVC.print(ui->listWidget);
        ui->pushButton->setText("Додати");
        ui->MinLabel->setText("");
        ui->BestLabel->setText("");
        ui->CheckResLabl->setText("");
        ui->SettingsLabel->setText("");
        ui->SettingsLabelNumber->setText("");
        ui->CheckResNum->setText("");

    }
    else if(index == 4)
    {
        ListHW.print(ui->listWidget);
        ui->pushButton->setText("Додати");
        ui->MinLabel->setText("");
        ui->BestLabel->setText("");
        ui->CheckResLabl->setText("");
        ui->SettingsLabel->setText("");
        ui->SettingsLabelNumber->setText("");
        ui->CheckResNum->setText("");

    }
    else if(index == 5)
    {
        ListSW.print(ui->listWidget);
        ui->pushButton->setText("Перевірити");
        ui->MinLabel->setText("Мінімальні вимоги");
        ui->BestLabel->setText("Рекомендовані вимоги");
        ui->CheckResLabl->setText("Cумісність: ");
        ui->SettingsLabel->setText("Рекомендовані налаштування: ");



    }
    ui->BestLabel->setStyleSheet("color:black");
    ui->MinLabel->setStyleSheet("color:black");
    ui->SettingsLabelNumber->setStyleSheet("color:black");
    ui->CheckResNum->setStyleSheet("color:black");
}



void MainWindow::on_pushButton_clicked()
{
    if(ui->listWidget->currentRow() >=0)
    {
        if(ui->comboBox->currentIndex() == 1)
        {
            if(CurrentComp->SetCPU(ListCPU.getEl(ui->listWidget->currentRow())) == true)
            {

            CurrentComp->Show(lbl);
            ui->CpuImage->setToolTip(ListCPU.getEl(ui->listWidget->currentRow())->GetName());

            }
        }
        else if(ui->comboBox->currentIndex() == 0)
        {
            CurrentComp->SetMB(ListMB.getEl(ui->listWidget->currentRow()));

            CurrentComp->Show(lbl);
            ui->MBImage->setToolTip(ListMB.getEl(ui->listWidget->currentRow())->GetName());

        }
        else if(ui->comboBox->currentIndex() == 2)
        {
            int bb = CurrentComp->SetOZU(ListOZU.getEl(ui->listWidget->currentRow()));
            if(bb == 0)
            {

                    ui->ozuimage2->setToolTip(ui->OzuImage->toolTip());
                   ui->OzuImage->setToolTip(ListOZU.getEl(ui->listWidget->currentRow())->GetName());

            }
            else if(bb == 1)
            {


               ui->OzuImage->setToolTip(ListOZU.getEl(ui->listWidget->currentRow())->GetName());
            }
            CurrentComp->Show(lbl);

        }
        else if(ui->comboBox->currentIndex() == 3)
        {

            if(CurrentComp->SetVC(ListVC.getEl(ui->listWidget->currentRow())) == true)
            {

            CurrentComp->Show(lbl);
            ui->VcImage->setToolTip(ListVC.getEl(ui->listWidget->currentRow())->GetName());

            }
        }
        else if(ui->comboBox->currentIndex() == 4)
        {
            if(CurrentComp->SetHW(ListHW.getEl(ui->listWidget->currentRow())) == true)
            {

            CurrentComp->Show(lbl);
            ui->HWImage->setToolTip(ListHW.getEl(ui->listWidget->currentRow())->GetName());

            }
        }
        else if(ui->comboBox->currentIndex() == 5)
        {
            int _rs = CurrentComp->CheckSoftware(ListSW.getEl(ui->listWidget->currentRow()));
           if(_rs != -1)
           {
           if(_rs >= 95)
           {
               ui->BestLabel->setStyleSheet("color:green");
               ui->MinLabel->setStyleSheet("color:green");
               ui->SettingsLabelNumber->setText("Максимальні");
               ui->SettingsLabelNumber->setStyleSheet("color:green");
               ui->CheckResNum->setStyleSheet("color:green");


           }
           if(_rs >= 70 && _rs < 95)
           {
               ui->BestLabel->setStyleSheet("color:orange)");
               ui->MinLabel->setStyleSheet("color:green");
               ui->SettingsLabelNumber->setText("Високі");
               ui->SettingsLabelNumber->setStyleSheet("color:green");
               ui->CheckResNum->setStyleSheet("color:green");


           }
           if(_rs >= 50 && _rs < 70)
           {
               ui->BestLabel->setStyleSheet("color:orange");
               ui->MinLabel->setStyleSheet("color:orange");
               ui->SettingsLabelNumber->setText("Середні");
               ui->SettingsLabelNumber->setStyleSheet("color:orange");
               ui->CheckResNum->setStyleSheet("color:yellow");

           }
           if(_rs >= 35 && _rs < 50)
           {
               ui->BestLabel->setStyleSheet("color:red");
               ui->MinLabel->setStyleSheet("color:orange");
               ui->SettingsLabelNumber->setText("Низькі");
               ui->SettingsLabelNumber->setStyleSheet("color:orange");
               ui->CheckResNum->setStyleSheet("color:orange");

           }
           if(_rs < 35)
           {
               ui->BestLabel->setStyleSheet("color:red");
               ui->MinLabel->setStyleSheet("color:red");
               ui->SettingsLabelNumber->setText("Мінімальні\\ПЗ не запуститься");
               ui->SettingsLabelNumber->setStyleSheet("color:red");
               ui->CheckResNum->setStyleSheet("color:red");

           }
           ui->CheckResNum->setText(QString::number(_rs)+"%");
           }

        }
    }
       CurrentComp->Show(ui->CompInformation);
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
    ui->HWImage->setToolTip("Відсутнє");
    }
    CurrentComp->Show(lbl);

       CurrentComp->Show(ui->CompInformation);

}

void MainWindow::on_CPU_Clicked()
{
    CurrentComp->DelCPU();
    CurrentComp->Show(lbl);
      ui->CpuImage->setToolTip("Відсутнє");

         CurrentComp->Show(ui->CompInformation);
}

void MainWindow::on_VC_Clicked()
{
    CurrentComp->DelVC();
    CurrentComp->Show(lbl);
    ui->VcImage->setToolTip("Відсутнє");

          CurrentComp->Show(ui->CompInformation);
}

void MainWindow::on_OZU1_clicked()
{
    CurrentComp->DelOZU(0);
    ui->OzuImage->setToolTip("Відсутнє");
    CurrentComp->Show(lbl);

          CurrentComp->Show(ui->CompInformation);
}

void MainWindow::on_OZU2_clicked()
{
    CurrentComp->DelOZU(1);
    CurrentComp->Show(lbl);
    ui->ozuimage2->setToolTip("Відсутнє");

          CurrentComp->Show(ui->CompInformation);
}

void MainWindow::on_HW_clicked()
{
    CurrentComp->DelHW();
    CurrentComp->Show(lbl);
    ui->HWImage->setToolTip("Відсутнє");

       CurrentComp->Show(ui->CompInformation);

}

void MainWindow::on_MBCh()
{
    if(CurrentComp->GetMB())
    {
       CurrentComp->GetMB()->Show(ui->TextInfo,ui->ImageLabel);CurrentComp->Show(ui->CompInformation);
       ui->BestLabel->setStyleSheet("color:black");
       ui->MinLabel->setStyleSheet("color:black");
       ui->SettingsLabelNumber->setStyleSheet("color:black");
       ui->CheckResNum->setStyleSheet("color:black");
       ui->MinLabel->setText("");
       ui->BestLabel->setText("");
       ui->CheckResLabl->setText("");
       ui->SettingsLabel->setText("");
       ui->SettingsLabelNumber->setText("");
       ui->CheckResNum->setText("");

    }
    ui->pushButton->setEnabled(false);

}

void MainWindow::on_CPUCh()
{
    if(CurrentComp->GetCpu())
    {
       CurrentComp->GetCpu()->Show(ui->TextInfo,ui->ImageLabel);
       CurrentComp->Show(ui->CompInformation);
       ui->BestLabel->setStyleSheet("color:black");
       ui->MinLabel->setStyleSheet("color:black");
       ui->SettingsLabelNumber->setStyleSheet("color:black");
       ui->CheckResNum->setStyleSheet("color:black");
       ui->MinLabel->setText("");
       ui->BestLabel->setText("");
       ui->CheckResLabl->setText("");
       ui->SettingsLabel->setText("");
       ui->SettingsLabelNumber->setText("");
       ui->CheckResNum->setText("");
    }
    ui->pushButton->setEnabled(false);

}

void MainWindow::on_VCCh()
{
    if(CurrentComp->GetVC())
    {
       CurrentComp->GetVC()->Show(ui->TextInfo,ui->ImageLabel);
       CurrentComp->Show(ui->CompInformation);
       ui->BestLabel->setStyleSheet("color:black");
       ui->MinLabel->setStyleSheet("color:black");
       ui->SettingsLabelNumber->setStyleSheet("color:black");
       ui->CheckResNum->setStyleSheet("color:black");
       ui->MinLabel->setText("");
       ui->BestLabel->setText("");
       ui->CheckResLabl->setText("");
       ui->SettingsLabel->setText("");
       ui->SettingsLabelNumber->setText("");
       ui->CheckResNum->setText("");
    }
    ui->pushButton->setEnabled(false);

}

void MainWindow::on_OZU1Ch()
{
    if(CurrentComp->GetOZU(0))
    {
       CurrentComp->GetOZU(0)->Show(ui->TextInfo,ui->ImageLabel);
       CurrentComp->Show(ui->CompInformation);
       ui->BestLabel->setStyleSheet("color:black");
       ui->MinLabel->setStyleSheet("color:black");
       ui->SettingsLabelNumber->setStyleSheet("color:black");
       ui->CheckResNum->setStyleSheet("color:black");
       ui->MinLabel->setText("");
       ui->BestLabel->setText("");
       ui->CheckResLabl->setText("");
       ui->SettingsLabel->setText("");
       ui->SettingsLabelNumber->setText("");
       ui->CheckResNum->setText("");
    }
    ui->pushButton->setEnabled(false);

}
void MainWindow::on_OZU2Ch()
{
    if(CurrentComp->GetOZU(1))
    {
       CurrentComp->GetOZU(1)->Show(ui->TextInfo,ui->ImageLabel);
       CurrentComp->Show(ui->CompInformation);
       ui->BestLabel->setStyleSheet("color:black");
       ui->MinLabel->setStyleSheet("color:black");
       ui->SettingsLabelNumber->setStyleSheet("color:black");
       ui->CheckResNum->setStyleSheet("color:black");
       ui->MinLabel->setText("");
       ui->BestLabel->setText("");
       ui->CheckResLabl->setText("");
       ui->SettingsLabel->setText("");
       ui->SettingsLabelNumber->setText("");
       ui->CheckResNum->setText("");
    }
    ui->pushButton->setEnabled(false);

}

void MainWindow::on_HWCh()
{
    if(CurrentComp->GetHW())
    {
       CurrentComp->GetHW()->Show(ui->TextInfo,ui->ImageLabel);

       CurrentComp->Show(ui->CompInformation);
       ui->BestLabel->setStyleSheet("color:black");
       ui->MinLabel->setStyleSheet("color:black");
       ui->SettingsLabelNumber->setStyleSheet("color:black");
       ui->CheckResNum->setStyleSheet("color:black");
       ui->MinLabel->setText("");
       ui->BestLabel->setText("");
       ui->CheckResLabl->setText("");
       ui->SettingsLabel->setText("");
       ui->SettingsLabelNumber->setText("");
       ui->CheckResNum->setText("");
    }
    ui->pushButton->setEnabled(false);

}

void MainWindow::on_listWidget_pressed(const QModelIndex &index)
{
    ui->pushButton->setEnabled(true);
    ui->ImageLabel->clear();
    ui->TextInfo->clear();
    if(ui->comboBox->currentIndex() == 1)
    {
          ListCPU.ShowInf(index.row(),ui->TextInfo,ui->ImageLabel);
    }
    else if(ui->comboBox->currentIndex() == 0)
    {
          ListMB.ShowInf(index.row(),ui->TextInfo,ui->ImageLabel);
    }
    else if(ui->comboBox->currentIndex() == 2)
    {
          ListOZU.ShowInf(index.row(),ui->TextInfo,ui->ImageLabel);
    }
    else if(ui->comboBox->currentIndex() == 3)
    {
         ListVC.ShowInf(index.row(),ui->TextInfo,ui->ImageLabel);
    }
    else if(ui->comboBox->currentIndex() == 4)
    {
         ListHW.ShowInf(index.row(),ui->TextInfo,ui->ImageLabel);
    }
    else if(ui->comboBox->currentIndex() == 5)
    {
         ListSW.ShowInf(index.row(),ui->TextInfo,ui->ImageLabel);
         ui->MinLabel->setText("Мінімальні вимоги");
         ui->BestLabel->setText("Рекомендовані вимоги");
         ui->CheckResLabl->setText("Cумісність: ");
         ui->SettingsLabel->setText("Рекомендовані налаштування: ");
    }
}

void MainWindow::OpenCrComSl()
{
    Dialog_CreateComp * DL = new Dialog_CreateComp;
    DL->exec();
}





void MainWindow::on_RefreshButton_clicked()
{
    ListCPU.Clear();
    ListMB.Clear();
    ListOZU.Clear();
    ListVC.Clear();
    ListHW.Clear();
    ListSW.Clear();
    ListCPU.read("DB/CPU.txt");
    ListMB.read("DB/MBB.txt");
    ListMB.print(ui->listWidget);
    ListOZU.read("DB/OZU.txt");
    ListVC.read("DB/VC.txt");
    ListHW.read("DB/HW.txt");
    ListSW.read("DB/SW.txt");

    for(int i = 0;i < ListSW.getSize();i++)
    {
        if(!ListSW.getEl(i)->Verification(ListCPU,ListVC))
        {
            ListSW.DeleteIn(i);
            i--;
        }
    }
    ui->comboBox->setCurrentIndex(0);
    ui->ImageLabel->clear();
    ui->TextInfo->clear();

}
