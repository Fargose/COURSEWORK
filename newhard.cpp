#include "newhard.h"
#include "ui_newhard.h"

newhard::newhard(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newhard)
{
    ui->setupUi(this);
    HW.image = "";
    ui->memtype->hide();
    ui->memtypel->hide();
    ui->canal_count->hide();
    ui->canal_countl->hide();
    ui->canal_type->hide();
    ui->canal_typel->hide();
    ui->pcxv->hide();
    ui->pcxx->hide();
    ui->pcxvl->hide();
    ui->pcxxl->hide();
    ui->DirectX->hide();
    ui->DirectXl->hide();
    ui->OpenGL->hide();
    ui->OpenGLl->hide();
    ui->memVc->hide();
    ui->MVcl->hide();
    ui->MFreq->hide();
    ui->Mfreql->hide();
    ui->CFreq->hide();
    ui->CFreql->hide();
    ui->memory->hide();
    ui->memoryl->hide();
    ui->maxmem->hide();
    ui->maxmemm->hide();
    ui->bestcpu->hide();
    ui->bestl->hide();
    ui->bestvc->hide();
    ui->BestOzu->hide();
    ui->mincpu->hide();
    ui->minozu->hide();
    ui->minvc->hide();
    ui->Minl->hide();
    ui->freq->setValidator(new QRegExpValidator(QRegExp("^([1-9][0-9]*|0)(\\.|,)[0-9]{2}"), this));
    ui->MFreq->setValidator(new QRegExpValidator(QRegExp("^([1-9][0-9]*|0)(\\.|,)[0-9]{2}"), this));
    ui->cash->setValidator(new QRegExpValidator(QRegExp("^([1-9][0-9]*|0)(\\.|,)[0-9]{2}"), this));
    ui->price->setValidator(new QRegExpValidator(QRegExp("^([1-9][0-9]*|0)(\\.|,)[0-9]{2}"), this));
    ui->CFreq->setValidator(new QRegExpValidator(QRegExp("^([1-9][0-9]*|0)(\\.|,)[0-9]{2}"), this));
    this->setWindowTitle("Додати елемент.");
}

newhard::~newhard()
{
    delete ui;
}

void newhard::on_toolButton_clicked()
{
    HW.image = QFileDialog::getOpenFileName(0, "Обрати зображення", "", "*.png *.jpg");
    ui->Imagel->setText(HW.image);


}

void newhard::on_buttonBox_accepted()
{
    HW.name = ui->name->text();
    if(HW.name == "")
    {
        QMessageBox::information(0,"Помилка заповнення.","Заповніть всі поля.");
        return;
    }
    if(HW.image == ""){
        HW.image = "Images/NoPhoto.jpg";
    }
    HW.creator = ui->creator->text();
    if(HW.creator == "")
    {
        QMessageBox::information(0,"Помилка заповнення.","Заповніть всі поля.");
        return;
    }
    HW.year = ui->year->currentText().toInt();
    HW.price = ui->price->text().toInt();
    if(HW.price == 0)
    {
        QMessageBox::information(0,"Помилка заповнення.","Заповніть всі поля.");
        return;
    }
    if(ui->radioButton->isChecked() == true)
    {
        if(ui->cash->text() == "")
        {
            QMessageBox::information(0,"Помилка заповнення.","Заповніть всі поля.");
            return;
        }
        HW.frequency =  ui->freq->currentText().toFloat();
        HW.soket = ui->soket->currentText();
        HW.Cash = ui->cash->text().toInt();
        HW.cernel = ui->cernel->currentText().toInt();
        HW.GChip = ui->graph->currentText();
        emit TransInf(HW,1);

    }
    else if(ui->radioButton_2->isChecked() == true)
    {

        HW.canal_count =  ui->canal_count->currentText().toInt();
        HW.soket = ui->soket->currentText();
        HW.canal_type= ui->canal_type->currentText();
        HW.maxmem = ui->maxmemm->currentText().toInt();

        HW.pcxx = ui->pcxx->currentText().toFloat();
        HW.pcxv = ui->pcxv->currentText().toInt();
        emit TransInf(HW,0);

    }
    else if(ui->radioButton_5->isChecked() == true)
    {

        HW.DirectX = ui->DirectX->currentText().toInt();
        HW.OpenGl = ui->OpenGL->currentText().toFloat();
        HW.Mfrequency = ui->MFreq->text().toInt();
        HW.Cfrequency = ui->CFreq->text().toInt();
        if(HW.Cfrequency == 0|| HW.Mfrequency == 0)
        {
            QMessageBox::information(0,"Помилка заповнення.","Заповніть всі поля.");
            return;
        }
        HW.memory = ui->memVc->currentText().toInt();

        HW.pcxx = ui->pcxx->currentText().toFloat();
        HW.pcxv = ui->pcxv->currentText().toFloat();
        emit TransInf(HW,3);

    }
    else if(ui->radioButton_3->isChecked() == true)
    {

        HW.canal_type=  ui->canal_type->currentText();
        HW.memory = ui->memory->currentText().toInt();
        HW.frequency= ui->freq->currentText().toInt();


        emit TransInf(HW,2);

    }
    else if(ui->radioButton_4->isChecked() == true)
    {

        HW.canal_type=  ui->memtype->currentText();
        HW.memory = ui->memory->currentText().toInt();



        emit TransInf(HW,4);

    }
    else if(ui->radioButton_6->isChecked() == true)
    {



        HW.bufcpub = ui->bestcpu->currentText();
            HW.maxmem = ui->BestOzu->currentText().toInt();
        HW.bufvcb = ui->bestvc->currentText();
          HW.bufcpum = ui->mincpu->currentText();
          HW.bufvcm = ui->minvc->currentText();
          HW.memory = ui->minozu->currentText().toInt();
        emit TransInf(HW,5);

    }
}

void newhard::on_radioButton_clicked()
{
    ui->maxmem->hide();
    ui->maxmemm->hide();
    ui->memtype->hide();
    ui->memtypel->hide();
    ui->soket->show();
    ui->soketl->show();
    ui->freq->show();
    ui->cash->show();
    ui->freql->show();
    ui->cashl->show();
    ui->graph->show();
    ui->grapl->show();
    ui->cernel->show();
    ui->cernell->show();
    ui->canal_count->hide();
    ui->canal_countl->hide();
    ui->canal_type->hide();
    ui->canal_typel->hide();
    ui->pcxv->hide();
    ui->pcxx->hide();
    ui->pcxvl->hide();
    ui->pcxxl->hide();
    ui->DirectX->hide();
    ui->DirectXl->hide();
    ui->OpenGL->hide();
    ui->OpenGLl->hide();
    ui->memVc->hide();
    ui->MVcl->hide();
    ui->MFreq->hide();
    ui->Mfreql->hide();
    ui->CFreq->hide();
    ui->CFreql->hide();
    ui->memory->hide();
    ui->memoryl->hide();
    ui->bestcpu->hide();
    ui->bestl->hide();
    ui->bestvc->hide();
    ui->BestOzu->hide();
    ui->mincpu->hide();
    ui->minozu->hide();
    ui->minvc->hide();
    ui->Minl->hide();
}

void newhard::on_radioButton_2_clicked()
{
    ui->maxmem->show();
    ui->maxmemm->show();
    ui->memtype->hide();
    ui->memtypel->hide();
    ui->soket->show();
    ui->soketl->show();
    ui->freq->hide();
    ui->cash->hide();
    ui->freql->hide();
    ui->cashl->hide();
    ui->graph->hide();
    ui->grapl->hide();
    ui->cernel->hide();
    ui->cernell->hide();
    ui->canal_count->show();
    ui->canal_countl->show();
    ui->canal_type->show();
    ui->canal_typel->show();
    ui->pcxv->show();
    ui->pcxx->show();
    ui->pcxvl->show();
    ui->pcxxl->show();
    ui->DirectX->hide();
    ui->DirectXl->hide();
    ui->OpenGL->hide();
    ui->OpenGLl->hide();
    ui->memVc->hide();
    ui->MVcl->hide();
    ui->MFreq->hide();
    ui->Mfreql->hide();
    ui->CFreq->hide();
    ui->CFreql->hide();
    ui->memory->hide();
    ui->memoryl->hide();
    ui->bestcpu->hide();
    ui->bestl->hide();
    ui->bestvc->hide();
    ui->BestOzu->hide();
    ui->mincpu->hide();
    ui->minozu->hide();
    ui->minvc->hide();
    ui->Minl->hide();

}

void newhard::on_radioButton_5_clicked()
{
    ui->maxmem->hide();
    ui->maxmemm->hide();
    ui->memtype->hide();
    ui->memtypel->hide();
    ui->soket->hide();
    ui->soketl->hide();
    ui->freq->hide();
    ui->cash->hide();
    ui->freql->hide();
    ui->cashl->hide();
    ui->graph->hide();
    ui->grapl->hide();
    ui->cernel->hide();
    ui->cernell->hide();
    ui->canal_count->hide();
    ui->canal_countl->hide();
    ui->canal_type->hide();
    ui->canal_typel->hide();
    ui->pcxv->show();
    ui->pcxx->show();
    ui->pcxvl->show();
    ui->pcxxl->show();
    ui->DirectX->show();
    ui->DirectXl->show();
    ui->OpenGL->show();
    ui->OpenGLl->show();
    ui->memVc->show();
    ui->MVcl->show();
    ui->MFreq->show();
    ui->Mfreql->show();
    ui->CFreq->show();
    ui->CFreql->show();
    ui->memory->hide();
    ui->memoryl->hide();
    ui->bestcpu->hide();
    ui->bestl->hide();
    ui->bestvc->hide();
    ui->BestOzu->hide();
    ui->mincpu->hide();
    ui->minozu->hide();
    ui->minvc->hide();
    ui->Minl->hide();
}

void newhard::on_radioButton_3_clicked()
{
    ui->maxmem->hide();
    ui->maxmemm->hide();
    ui->memtype->hide();
    ui->memtypel->hide();
    ui->soket->hide();
    ui->soketl->hide();
    ui->freq->show();
    ui->cash->hide();
    ui->freql->show();
    ui->cashl->hide();
    ui->graph->hide();
    ui->grapl->hide();
    ui->cernel->hide();
    ui->cernell->hide();
    ui->canal_count->hide();
    ui->canal_countl->hide();
    ui->canal_type->show();
    ui->canal_typel->show();
    ui->pcxv->hide();
    ui->pcxx->hide();
    ui->pcxvl->hide();
    ui->pcxxl->hide();
    ui->DirectX->hide();
    ui->DirectXl->hide();
    ui->OpenGL->hide();
    ui->OpenGLl->hide();
    ui->memVc->hide();
    ui->MVcl->hide();
    ui->MFreq->hide();
    ui->Mfreql->hide();
    ui->CFreq->hide();
    ui->CFreql->hide();
    ui->memory->show();
    ui->memoryl->show();
    ui->bestcpu->hide();
    ui->bestl->hide();
    ui->bestvc->hide();
    ui->BestOzu->hide();
    ui->mincpu->hide();
    ui->minozu->hide();
    ui->minvc->hide();
    ui->Minl->hide();
}

void newhard::on_radioButton_4_clicked()
{
    ui->maxmem->hide();
    ui->maxmemm->hide();
    ui->memtype->show();
    ui->memtypel->show();
    ui->soket->hide();
    ui->soketl->hide();
    ui->freq->hide();
    ui->cash->hide();
    ui->freql->hide();
    ui->cashl->hide();
    ui->graph->hide();
    ui->grapl->hide();
    ui->cernel->hide();
    ui->cernell->hide();
    ui->canal_count->hide();
    ui->canal_countl->hide();
    ui->canal_type->hide();
    ui->canal_typel->hide();
    ui->pcxv->hide();
    ui->pcxx->hide();
    ui->pcxvl->hide();
    ui->pcxxl->hide();
    ui->DirectX->hide();
    ui->DirectXl->hide();
    ui->OpenGL->hide();
    ui->OpenGLl->hide();
    ui->memVc->hide();
    ui->MVcl->hide();
    ui->MFreq->hide();
    ui->Mfreql->hide();
    ui->CFreq->hide();
    ui->CFreql->hide();
    ui->memory->show();
    ui->memoryl->show();
    ui->bestcpu->hide();
    ui->bestl->hide();
    ui->bestvc->hide();
    ui->BestOzu->hide();
    ui->mincpu->hide();
    ui->minozu->hide();
    ui->minvc->hide();
    ui->Minl->hide();
}

void newhard::on_radioButton_6_clicked()
{
    ui->maxmem->hide();
    ui->maxmemm->hide();
    ui->memtype->hide();
    ui->memtypel->hide();
    ui->soket->hide();
    ui->soketl->hide();
    ui->freq->hide();
    ui->cash->hide();
    ui->freql->hide();
    ui->cashl->hide();
    ui->graph->hide();
    ui->grapl->hide();
    ui->cernel->hide();
    ui->cernell->hide();
    ui->canal_count->hide();
    ui->canal_countl->hide();
    ui->canal_type->hide();
    ui->canal_typel->hide();
    ui->pcxv->hide();
    ui->pcxx->hide();
    ui->pcxvl->hide();
    ui->pcxxl->hide();
    ui->DirectX->hide();
    ui->DirectXl->hide();
    ui->OpenGL->hide();
    ui->OpenGLl->hide();
    ui->memVc->hide();
    ui->MVcl->hide();
    ui->MFreq->hide();
    ui->Mfreql->hide();
    ui->CFreq->hide();
    ui->CFreql->hide();
    ui->memory->hide();
    ui->memoryl->hide();
    ui->bestcpu->show();
    ui->bestl->show();
    ui->bestvc->show();
    ui->BestOzu->show();
    ui->mincpu->show();
    ui->minozu->show();
    ui->minvc->show();
    ui->Minl->show();
}

void newhard::PrCSW(cWareList<cCPU> chc, cWareList<cVideoCard> cvc)
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
