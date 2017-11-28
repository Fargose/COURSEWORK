#include "hardedit.h"
#include "ui_hardedit.h"

hardedit::hardedit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::hardedit)
{
    ui->setupUi(this);
    ui->price->setValidator(new QRegExpValidator(QRegExp("^([1-9][0-9]*|0)(\\.|,)[0-9]{2}"), this));
    ui->cash->setValidator(new QRegExpValidator(QRegExp("^([1-9][0-9]*|0)(\\.|,)[0-9]{2}"), this));
    ui->CFrequency->setValidator(new QRegExpValidator(QRegExp("^([1-9][0-9]*|0)(\\.|,)[0-9]{2}"), this));

    ui->MFrequency->setValidator(new QRegExpValidator(QRegExp("^([1-9][0-9]*|0)(\\.|,)[0-9]{2}"), this));
    ui->frequencyozu->setValidator(new QRegExpValidator(QRegExp("^([1-9][0-9]*|0)(\\.|,)[0-9]{2}"), this));
    this->setWindowTitle("Редагування елемента.");



}

hardedit::~hardedit()
{
    delete ui;

}

void hardedit::PrCSW(cHardList<cCPU> chc, cHardList<cVideoCard> cvc)
{
    ListCpu = chc;
    ListVC = cvc;
    for(int i = 0;i<ListCpu.getSize();i++)
    {
        ui->bestcpu->addItem(ListCpu.getEl(i)->GetName());
    }
    for(int i = 0;i<ListCpu.getSize();i++)
    {
        ui->mincpu->addItem(ListCpu.getEl(i)->GetName());
    }
    for(int i = 0;i<ListVC.getSize();i++)
    {
        ui->bestvc->addItem(ListVC.getEl(i)->GetName());
    }
    for(int i = 0;i<ListVC.getSize();i++)
    {
        ui->minvc->addItem(ListVC.getEl(i)->GetName());
    }
}

void hardedit::ChangeLair(int i,DataHW * _d)
{
    ui->stackedWidget->setCurrentIndex(i);
    ui->name->setText(_d->name);
    ui->creator->setText(_d->creator);
    ui->price->setText(QString::number(_d->price));
    QPixmap * PX =new QPixmap;
    PX->load(_d->image);
    ui->image_show->setScaledContents(true);
    ui->image_show->setPixmap(*PX);
    ui->year->setCurrentText(QString::number(_d->year));
    if(i == 0)
    {
        ui->canl_type_m->setCurrentText(_d->canal_type);
         ui->canal_countm->setCurrentText(QString::number(_d->canal_count));
          ui->maxmemm->setCurrentText(QString::number(_d->maxmem));
           ui->pcxxm->setCurrentText(QString::number(_d->pcxx));
           ui->pcxvm->setCurrentText(QString::number(_d->pcxv));
           ui->soketm->setCurrentText(_d->soket);
    }
    else if(i == 1)
    {

        ui->cash->setText(QString::number(_d->Cash));
        ui->GChip->setCurrentText(_d->GChip);
        ui->frequencyp->setCurrentText(QString::number(_d->frequency));
        ui->soketp->setCurrentText(_d->soket);
        ui->cernel->setCurrentText(QString::number(_d->cernel));
    }
    else if(i == 2)
    {
        ui->frequencyozu->setText(QString::number(_d->frequency));
        ui->memozu->setCurrentText(QString::number(_d->memory));
        ui->canltypeozu->setCurrentText(_d->canal_type);


    }
    else if(i == 3)
    {
        ui->pcxxv->setCurrentText(QString::number(_d->pcxx));
        ui->pcxvv->setCurrentText(QString::number(_d->pcxv));
        ui->CFrequency->setText(QString::number(_d->Cfrequency));
        ui->MFrequency->setText(QString::number(_d->Mfrequency));
        ui->memv->setCurrentText(QString::number(_d->memory));
        ui->DirectX->setCurrentText(QString::number(_d->DirectX));
        ui->OpenGL->setCurrentText(QString::number(_d->OpenGl));

    }
    else if(i == 4)
    {

   ui->memhd->setCurrentText(QString::number(_d->memory));
   ui->canal_typehd->setCurrentText(_d->canal_type);

    }
    else if(i == 5)
    {

   ui->bestcpu->setCurrentText(_d->bufcpub);
   ui->bestozu->setCurrentText(QString::number(_d->maxmem));
   ui->bestvc->setCurrentText((_d->bufvcb));
   ui->mincpu->setCurrentText(_d->bufcpum);
   ui->minozu->setCurrentText(QString::number(_d->memory));
   ui->minvc->setCurrentText((_d->bufvcm));
   ui->image_show->setGeometry(ui->image_show->x(),ui->image_show->y(),140,180);


    }

    HW.image = _d->image;


}


void hardedit::on_buttonBox_accepted()
{
    HW.name = ui->name->text();
    if(HW.name =="")
    {
        HW.name = "No name";
    }
    HW.creator = ui->creator->text();
    if(HW.creator == "")
    {
        HW.creator = "Невідомо";
    }
    HW.year = ui->year->currentText().toInt();
    HW.price = ui->price->text().toInt();
    if(ui->stackedWidget->currentIndex() == 0)
    {
        HW.canal_type = ui->canl_type_m->currentText();
         HW.canal_count = ui->canal_countm->currentText().toInt();
          HW.soket = ui->soketm->currentText();
          HW.pcxx = ui->pcxxm->currentText().toInt();
          HW.pcxv = ui->pcxvm->currentText().toFloat();
          HW.maxmem = ui->maxmemm->currentText().toInt();
    }
   else if(ui->stackedWidget->currentIndex() == 1)
    {
        HW.soket = ui->soketp->currentText();
        HW.cernel = ui->cernel->currentText().toInt();
        HW.Cash = ui->cash->text().toInt();
        HW.GChip = ui->GChip->currentText();
        HW.frequency = ui->frequencyp->currentText().toInt();
    }
    else if(ui->stackedWidget->currentIndex() == 2)
     {
         HW.frequency = ui->frequencyozu->text().toInt();
         HW.memory = ui->memozu->currentText().toInt();
         HW.canal_type = ui->canltypeozu->currentText();
     }
    else if(ui->stackedWidget->currentIndex() == 3)
    {
        HW.pcxx = ui->pcxxv->currentText().toInt();
        HW.pcxv = ui->pcxvv->currentText().toFloat();
        HW.Cfrequency = ui->CFrequency->text().toInt();
        HW.memory = ui->memv->currentText().toInt();
        HW.DirectX = ui->DirectX->currentText().toInt();
        HW.OpenGl = ui->OpenGL->currentText().toFloat();
        HW.Mfrequency = ui->MFrequency->text().toInt();

    }
    else if(ui->stackedWidget->currentIndex() == 4)
    {
      HW.memory = ui->memhd->currentText().toInt();
       HW.canal_type = ui->canal_typehd->currentText();

    }
    else if(ui->stackedWidget->currentIndex() == 5)
    {

    HW.bufcpub = ui->bestcpu->currentText();
    HW.bufvcb = ui->bestvc->currentText();
     HW.maxmem = ui->bestozu->currentText().toInt();
     HW.bufcpum = ui->mincpu->currentText();
     HW.bufvcm = ui->minvc->currentText();
      HW.memory = ui->minozu->currentText().toInt();



    }
    emit TransHW(&HW);
}

void hardedit::on_toolButton_clicked()
{
    HW.image = QFileDialog::getOpenFileName(0, "Обрати зображення", "", "*.png *.jpg");
    QPixmap * PX =new QPixmap;
    PX->load(HW.image);
    ui->image_show->setScaledContents(true);
    ui->image_show->setPixmap(*PX);
}
