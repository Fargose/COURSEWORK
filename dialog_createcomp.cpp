#include "dialog_createcomp.h"
#include "ui_dialog_createcomp.h"

Dialog_CreateComp::Dialog_CreateComp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_CreateComp)
{
    ui->setupUi(this);
}

Dialog_CreateComp::~Dialog_CreateComp()
{
    delete ui;
}
