#ifndef DIALOG_CREATECOMP_H
#define DIALOG_CREATECOMP_H

#include <QDialog>

#include "chardware.h"
#include <QLabel>
#include <QPixmap>
struct infForCreate
{
    int frequency;
    int memozu;
    int mem;
    int VMem;
    int price;

};

namespace Ui {
class Dialog_CreateComp;
}

class Dialog_CreateComp : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_CreateComp(QWidget *parent = 0);
    ~Dialog_CreateComp();

private slots:


    void on_checkPrice_clicked(bool checked);

    void on_checkPI_clicked(bool checked);

    void on_buttonBox_accepted();

    void PrCSW(cWareList<cSoftware>);

    void on_PICmb_activated(int index);


private:
    Ui::Dialog_CreateComp *ui;
    cWareList<cSoftware> ListSW;
    infForCreate inffc;
signals:
    void TransInf(infForCreate);

};

#endif // DIALOG_CREATECOMP_H
