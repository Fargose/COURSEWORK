#ifndef DIALOG_CREATECOMP_H
#define DIALOG_CREATECOMP_H

#include <QDialog>

namespace Ui {
class Dialog_CreateComp;
}

class Dialog_CreateComp : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_CreateComp(QWidget *parent = 0);
    ~Dialog_CreateComp();

private:
    Ui::Dialog_CreateComp *ui;
};

#endif // DIALOG_CREATECOMP_H
