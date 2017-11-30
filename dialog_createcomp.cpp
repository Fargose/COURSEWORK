#include "dialog_createcomp.h"
#include "ui_dialog_createcomp.h"


Dialog_CreateComp::Dialog_CreateComp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_CreateComp)
{
    ui->setupUi(this);
    this->setWindowTitle("Підібрати комп'ютер");
        ui->lineEdit->setValidator(new QRegExpValidator(QRegExp("^([1-9][0-9]*|0)(\\.|,)[0-9]{2}"), this));



}

Dialog_CreateComp::~Dialog_CreateComp()
{
    delete ui;


}



void Dialog_CreateComp::on_checkPrice_clicked(bool checked)
{
    if(!checked)
    {
        ui->FreqCmb->setEnabled(false);
        ui->OZUCmb->setEnabled(false);
        ui->HDCmb->setEnabled(false);
        ui->VMemCB->setEnabled(false);
        ui->lineEdit->setEnabled(false);
    }
    else
    {
        if(ui->checkPI->checkState() == Qt::Checked)
        {
            ui->lineEdit->setEnabled(true);
        }
        else
        {
            ui->FreqCmb->setEnabled(true);
            ui->OZUCmb->setEnabled(true);
            ui->HDCmb->setEnabled(true);
            ui->VMemCB->setEnabled(true);
            ui->lineEdit->setEnabled(true);
        }
    }
}

void Dialog_CreateComp::on_checkPI_clicked(bool checked)
{
    if(!checked && ui->checkPrice->checkState() == Qt::Checked)
    {
        ui->PICmb->setEnabled(false);
        ui->label_6->clear();
        ui->FreqCmb->setEnabled(true);
        ui->OZUCmb->setEnabled(true);
        ui->HDCmb->setEnabled(true);
        ui->VMemCB->setEnabled(true);

    }
    else
    {
        ui->PICmb->setEnabled(true);
        ui->FreqCmb->setEnabled(false);
        ui->OZUCmb->setEnabled(false);
        ui->HDCmb->setEnabled(false);
        ui->VMemCB->setEnabled(false);
        QPixmap MyPix;
        if(!MyPix.load(ListSW.getEl(ui->PICmb->currentIndex())->GetImage()))
        {

            MyPix.load("Images/NoPhoto.jpg");
        }
        ui->label_6->setScaledContents(true);
        ui->label_6->setPixmap(MyPix);
    }
    if(!checked)
    {
        ui->PICmb->setEnabled(false);
        ui->label_6->clear();
    }
}

void Dialog_CreateComp::on_buttonBox_accepted()
{
    if(ui->checkPI->checkState() == Qt::Checked && !(ui->checkPrice->checkState() == Qt::Checked) )
    {
        inffc.price = -1;
        inffc.frequency = ListSW.getEl(ui->PICmb->currentIndex())->getBest()->CPU->getFrequency();
        inffc.VMem = ListSW.getEl(ui->PICmb->currentIndex())->getBest()->VC->GetMem();
        inffc.mem = 512;
        inffc.memozu = ListSW.getEl(ui->PICmb->currentIndex())->getBest()->memory;
    }
    else if(ui->checkPI->checkState() == Qt::Checked && ui->checkPrice->checkState() == Qt::Checked )
    {
        inffc.price = ui->lineEdit->text().toInt();
        inffc.frequency = ListSW.getEl(ui->PICmb->currentIndex())->getBest()->CPU->getFrequency();
        inffc.VMem = ListSW.getEl(ui->PICmb->currentIndex())->getBest()->VC->GetMem();
        inffc.mem = 512;
        inffc.memozu = ListSW.getEl(ui->PICmb->currentIndex())->getBest()->memory;
    }
    else if(!(ui->checkPI->checkState() == Qt::Checked) && (ui->checkPrice->checkState() == Qt::Checked ))
    {
        inffc.price = ui->lineEdit->text().toInt();
        inffc.frequency = ui->FreqCmb->currentText().toInt();
        inffc.VMem = ui->VMemCB->currentText().toInt();
        inffc.mem = ui->HDCmb->currentText().toInt();
        inffc.memozu =ui->OZUCmb->currentText().toInt();
    }
    emit TransInf(inffc);
}

void Dialog_CreateComp::PrCSW(cWareList<cSoftware> _list)
{
    ListSW = _list;
    for(int i = 0;i<ListSW.getSize();i++)
    {
        ui->PICmb->addItem(ListSW.getEl(i)->GetName());
    }
}

void Dialog_CreateComp::on_PICmb_activated(int index)
{
    QPixmap MyPix;
    if(!MyPix.load(ListSW.getEl(index)->GetImage()))
    {

        MyPix.load("Images/NoPhoto.jpg");
    }
    ui->label_6->setScaledContents(true);
    ui->label_6->setPixmap(MyPix);

}
