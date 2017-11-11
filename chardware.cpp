#include "chardware.h"

cHardware::cHardware()
{

}

QString cHardware::GetName()
{
    return name;
}

cCPU::cCPU()
{

}

cCPU::cCPU(DataHW * _d)
{
    name = _d->name;
    price = _d->price;
    frequency = _d->frequency;
    creator = _d->creator;
    year = _d->year;
    cernel = _d->cernel;
    soket = _d->soket;
    Cash = _d->Cash;
    GChip = _d->GChip;
    Powerty = _d->Powerty;
    image = _d->image;
}

float cCPU::getGrade()
{
    return 5;
}

void cCPU::Show(QTableWidget * QTW, int i)
{
        QTableWidgetItem * qtw = new QTableWidgetItem(name);
        QTW->setItem(i,0,qtw);
        qtw = new QTableWidgetItem(QString::number(price) +" $");
        QTW->setItem(i,1,qtw);
        qtw = new QTableWidgetItem(creator);
        QTW->setItem(i,2,qtw);
        qtw = new QTableWidgetItem(QString::number(year));
        QTW->setItem(i,3,qtw);
        qtw = new QTableWidgetItem(soket);
        QTW->setItem(i,4,qtw);
        qtw = new QTableWidgetItem(QString::number(Powerty));
        QTW->setItem(i,5,qtw);
        qtw = new QTableWidgetItem(GChip);
        QTW->setItem(i,6,qtw);
        qtw = new QTableWidgetItem(QString::number(Cash)+ "Mb");
        QTW->setItem(i,7,qtw);
        qtw = new QTableWidgetItem(QString::number(frequency)+ " GHz");
        QTW->setItem(i,8,qtw);
        qtw = new QTableWidgetItem(QString::number(cernel));
        QTW->setItem(i,9,qtw);
}

void cCPU::Show(QTextBrowser * QTB, QLabel * QL)
{
    QTB->clear();
    QTB->append("Назва: " + name);
    QTB->append("Ціна: " + QString::number(price));
    QTB->append("Виробник: " + creator);
    QTB->append("Рік виробництва: " + QString::number(year));
    QTB->append("Сокет: " + soket);
    QTB->append("Питома потужність: " + QString::number(Powerty));
    QTB->append("Графічний чіп: " + GChip) ;
    QTB->append("Обсяг кешу: " + QString::number(Cash));
    QTB->append("Частота: " + QString::number(frequency));
    QTB->append("Кількість ядер: " + QString::number(cernel));
    QPixmap MyPix(image);
    QL->setScaledContents(true);
    QL->setPixmap(MyPix);

}


cMotherBoard::cMotherBoard()
{

}

cMotherBoard::cMotherBoard(DataHW * _d)
{
    name = _d->name;
    price = _d->price;
    creator = _d->creator;
    year = _d->year;
    soket = _d->soket;
    maxmem = _d->maxmem;
    canal_count = _d->canal_count;
    canal_type = _d->canal_type;
      image = _d->image;

}

float cMotherBoard::getGrade()
{
    return 5;

}

void cMotherBoard::Show(QTableWidget * QTW, int i)
{
    QTableWidgetItem * qtw = new QTableWidgetItem(name);
    QTW->setItem(i,0,qtw);
    qtw = new QTableWidgetItem(QString::number(price) +" $");
    QTW->setItem(i,1,qtw);
    qtw = new QTableWidgetItem(creator);
    QTW->setItem(i,3,qtw);
    qtw = new QTableWidgetItem(QString::number(year));
    QTW->setItem(i,2,qtw);
    qtw = new QTableWidgetItem(soket);
    QTW->setItem(i,4,qtw);
    qtw = new QTableWidgetItem(QString::number(canal_count));
    QTW->setItem(i,5,qtw);
    qtw = new QTableWidgetItem(canal_type);
    QTW->setItem(i,6,qtw);
    qtw = new QTableWidgetItem(QString::number(maxmem) + "Gb");
    QTW->setItem(i,7,qtw);
}

cOZU::cOZU()
{

}

cOZU::cOZU(DataHW * _d)
{

    name = _d->name;
    price = _d->price;
    creator = _d->creator;
    year = _d->year;
    memory = _d->memory;
    frequency= _d->frequency;
    canal_type = _d->canal_type;
      image = _d->image;

}

float cOZU::getGrade()
{
    return 5;
}

void cOZU::Show(QTableWidget * QTW, int i)
{
    QTableWidgetItem * qtw = new QTableWidgetItem(name);
    QTW->setItem(i,0,qtw);
    qtw = new QTableWidgetItem(QString::number(price) +" $");
    QTW->setItem(i,1,qtw);
    qtw = new QTableWidgetItem(creator);
    QTW->setItem(i,3,qtw);
    qtw = new QTableWidgetItem(QString::number(year));
    QTW->setItem(i,2,qtw);
    qtw = new QTableWidgetItem(QString::number(frequency) + "MGz");
    QTW->setItem(i,4,qtw);
    qtw = new QTableWidgetItem(canal_type);
    QTW->setItem(i,5,qtw);
    qtw = new QTableWidgetItem(QString::number(memory) + "Gb");
    QTW->setItem(i,6,qtw);
}

cVideoCard::cVideoCard()
{

}

cVideoCard::cVideoCard(DataHW * _d)
{
    name = _d->name;
    price = _d->price;
    creator = _d->creator;
    year = _d->year;
    memory = _d->memory;
    Cfrequency= _d->Cfrequency;
    Mfrequency = _d->Mfrequency;
    DirectX = _d->DirectX;
    OpenGl = _d->OpenGl;
      image = _d->image;
}

void cVideoCard::Show(QTableWidget * QTW, int i)
{
    QTableWidgetItem * qtw = new QTableWidgetItem(name);
    QTW->setItem(i,0,qtw);
    qtw = new QTableWidgetItem(QString::number(price) +" $");
    QTW->setItem(i,1,qtw);
    qtw = new QTableWidgetItem(creator);
    QTW->setItem(i,3,qtw);
    qtw = new QTableWidgetItem(QString::number(year));
    QTW->setItem(i,2,qtw);
    qtw = new QTableWidgetItem(QString::number(Cfrequency) + "MGz");
    QTW->setItem(i,4,qtw);
    qtw = new QTableWidgetItem(QString::number(Mfrequency) + "MGz");
    QTW->setItem(i,5,qtw);
    QString buf;
    if(memory >=8)
    {
        buf = "Mb";
    }
    else
    {
        buf = "Gb";
    }
    qtw = new QTableWidgetItem(QString::number(memory) + buf);
    QTW->setItem(i,6,qtw);
    qtw = new QTableWidgetItem(QString::number(DirectX));
    QTW->setItem(i,7,qtw);
    qtw = new QTableWidgetItem(QString::number(OpenGl));
    QTW->setItem(i,8,qtw);
}

float cVideoCard::getGrade()
{
    return 5;
}
