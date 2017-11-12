#include "chardware.h"


cHardware::cHardware()
{

}

QString cHardware::GetName()
{
    return name;
}

QString cHardware::GetImage()
{
    return image;
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
    image = _d->image;
}

float cCPU::getGrade()
{
    return 5;
}



void cCPU::Show(QTextBrowser * QTB, QLabel * QL)
{
    QTB->clear();
    QTB->append("Назва: " + name);
    QTB->append("Ціна: " + QString::number(price) + " $");
    QTB->append("Виробник: " + creator);
    QTB->append("Рік виробництва: " + QString::number(year));
    QTB->append("Сокет: " + soket);
    QTB->append("Графічний чіп: " + GChip) ;
    QTB->append("Обсяг кешу: " + QString::number(Cash) + " Mb");
    QTB->append("Частота: " + QString::number(frequency) + " GHz");
    QTB->append("Кількість ядер: " + QString::number(cernel));
    QPixmap MyPix;
    if(!MyPix.load(image))
    {
        image = "Images/NoPhoto.jpg";
        MyPix.load(image);
    }
    QL->setScaledContents(true);
    QL->setPixmap(MyPix);

}

QString cCPU::GetSoket()
{
    return soket;
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
      pcxv = _d->pcxv;
      pcxx  = _d->pcxx;

}

float cMotherBoard::getGrade()
{
    return 5;

}

void cMotherBoard::Show(QTextBrowser * QTB, QLabel * QL)
{
    QTB->clear();
    QTB->append("Назва: " + name);
    QTB->append("Ціна: " + QString::number(price) + " $");
    QTB->append("Виробник: " + creator);
    QTB->append("Рік виробництва: " + QString::number(year));
    QTB->append("Сокет процесора " + soket);
    QTB->append("Тип каналів памя'ті:: " + canal_type);
    QTB->append("Кількість каналів памя'ті: " +QString::number(canal_count));
    QTB->append("Максимальний обсяг памя'ті: " +QString::number(maxmem) + " Gb");
    QTB->append("Слот: PCiE " +QString::number(pcxv) + ".0 x" + QString::number(pcxx));
  QPixmap MyPix;
  if(!MyPix.load(image))
  {
      image = "Images/NoPhoto.jpg";
      MyPix.load(image);
  }
    QL->setScaledContents(true);
    QL->setPixmap(MyPix);
}

int cMotherBoard::GetCardPr()
{
    int x = 0;
    x = pow(2.0,((int)pcxv+1)+PowTwo(pcxx));
    return x;
}

QString cMotherBoard::GetSoket()
{
    return soket;
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

void cOZU::Show(QTextBrowser * QTB, QLabel * QL)
{
    QTB->clear();
    QTB->append("Назва: " + name);
    QTB->append("Ціна: " + QString::number(price) + " $");
    QTB->append("Виробник: " + creator);
    QTB->append("Рік виробництва: " + QString::number(year));
    QTB->append("Частота пам'яті: " + QString::number(frequency) + " MHz");
    QTB->append("Тип памя'ті: " + canal_type);
    QTB->append("Обсяг памя'ті: " +QString::number(memory) + " Gb");
    QPixmap MyPix;
    if(!MyPix.load(image))
    {
        image = "Images/NoPhoto.jpg";
        MyPix.load(image);
    }
    QL->setScaledContents(true);
    QL->setPixmap(MyPix);
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
      pcxv = _d->pcxv;
      pcxx = _d->pcxx;
}



float cVideoCard::getGrade()
{
    return 5;
}

void cVideoCard::Show(QTextBrowser * QTB, QLabel * QL)
{
    QTB->clear();
    QTB->append("Назва: " + name);
    QTB->append("Ціна: " + QString::number(price) + " $");
    QTB->append("Виробник: " + creator);
    QTB->append("Рік виробництва: " + QString::number(year));
    QTB->append("Інтерфейс: PCiE " +QString::number(pcxv) + ".0 x" + QString::number(pcxx));
    QTB->append("Частота пам'яті: " + QString::number(Mfrequency) + " MGz");
    QTB->append("Частота ядра: " + QString::number(Cfrequency) +" MGz" );
    QTB->append("Обсяг памя'ті: " +QString::number(memory) + " Gb");
    QTB->append("Підтримка DirectX " +QString::number(DirectX));
    QTB->append("Підтримка OpenGL " +QString::number(OpenGl));
    QPixmap MyPix;
    if(!MyPix.load(image))
    {
        image = "Images/NoPhoto.jpg";
        MyPix.load(image);
    }
    QL->setScaledContents(true);
    QL->setPixmap(MyPix);
}

int cVideoCard::GetCardPr()
{
    int x = 0;
    x = pow(2.0,((int)pcxv+1)+PowTwo(pcxx));
    return x;
}



cComputer::cComputer()
{
    CPU = NULL;
    OZU[0] = NULL;
    OZU[1] = NULL;
    MB = NULL;
    VC = NULL;


}

cComputer::cComputer(DataComp * _d)
{
    CPU = _d->CPU;
    OZU[1] = _d->OZU[1];
    OZU[0] = _d->OZU[0];
    MB = _d->MB;
    VC = _d->VC;
}

void cComputer::SetCPU(cCPU * _CPU)
{

    if(MB == NULL)
    {
        QMessageBox::information(0, "Information", "Встановіть материнську плату для додавання інших елементів.");
    }
    else
    {
        if(_CPU->GetSoket() != MB->GetSoket())
        {
             QMessageBox::information(0, "Information", "Не вдається установити процесор. Сокет материської плати відрізняється від процесора.");
        }
        else
        {
            CPU = _CPU;
        }
    }

}

int cComputer::SetOZU(cOZU * _OZU)
{

    if(MB == NULL)
    {
        QMessageBox::information(0, "Information", "Встановіть материнську плату для додавання інших елементів.");

    }
    else if(OZU[0] != NULL)
    {
    OZU[1] = OZU[0];
    OZU[0] = _OZU;
    return 0;
    }
    else
    {
        OZU[0] = _OZU;
        return 1;
    }
    return -1;
}

void cComputer::SetMB(cMotherBoard * _MB)
{


    MB=_MB;

}

void cComputer::SetVC(cVideoCard * _VC)
{
    if(MB == NULL)
    {
         QMessageBox::information(0, "Information", "Встановіть материнську плату для додавання інших елементів.");
    }
    else
    {
        if(MB->GetCardPr() < _VC->GetCardPr())
        {
               QMessageBox::information(0, "Information", "Пропускна властивість материнської слота материнської плати менша за інтерфейс відеокарти. Можлива робота не в повну силу.");

        }
        VC =_VC;
    }
}

void cComputer::DelCPU()
{
    CPU = NULL;
}

void cComputer::DelOZU(int i)
{
    OZU[i] = NULL;
}

bool cComputer::DelMB()
{
    QMessageBox* pmbx =
                        new QMessageBox("Усунути материнську плату?",
                        "Ви бажаєте усунути материнську плату. Це усуне всі інші компоненти збірки. Бажаєте продовжити?",
                        QMessageBox::Information,
                        QMessageBox::Yes,
                        QMessageBox::No,
                        QMessageBox::Cancel | QMessageBox::Escape);
    int n = pmbx->exec();
    delete pmbx;
    if (n == QMessageBox::Yes)
    {
        MB = NULL;
        CPU=NULL;
        OZU[0] = NULL;
        VC = NULL;
        OZU[1] = NULL;
        return true;
    }
    else
    {
        return false;
    }

}

void cComputer::DelVC()
{
    VC = NULL;
}

void cComputer::Show(QLabel * _lab[] )
{
    if(CPU!=NULL)
    {
        QPixmap MyPix;
        if(!MyPix.load(CPU->GetImage()))
        {

            MyPix.load("Images/NoPhoto.jpg");
        }
        _lab[0]->setScaledContents(true);
        _lab[0]->setPixmap(MyPix);

    }
    else
    {
         QPixmap MyPix;
         MyPix.load("");
         _lab[0]->setScaledContents(true);
         _lab[0]->setPixmap(MyPix);
    }
    if(MB!=NULL)
    {
        QPixmap MyPix;
        if(!MyPix.load(MB->GetImage()))
        {

            MyPix.load("Images/NoPhoto.jpg");
        }
        _lab[1]->setScaledContents(true);
        _lab[1]->setPixmap(MyPix);
    }
    else
    {
         QPixmap MyPix;
         MyPix.load("");
         _lab[1]->setScaledContents(true);
         _lab[1]->setPixmap(MyPix);
    }
    if(VC!=NULL)
    {
        QPixmap MyPix;
        if(!MyPix.load(VC->GetImage()))
        {

            MyPix.load("Images/NoPhoto.jpg");
        }
        _lab[2]->setScaledContents(true);
        _lab[2]->setPixmap(MyPix);
    }
    else
    {
         QPixmap MyPix;
         MyPix.load("");
         _lab[2]->setScaledContents(true);
         _lab[2]->setPixmap(MyPix);
    }
    if(OZU[0]!=NULL)
    {
        QPixmap MyPix;
        if(!MyPix.load(OZU[0]->GetImage()))
        {

            MyPix.load("Images/NoPhoto.jpg");
        }
        _lab[3]->setScaledContents(true);
        _lab[3]->setPixmap(MyPix);
    }
    else
    {
         QPixmap MyPix;
         MyPix.load("");
         _lab[3]->setScaledContents(true);
         _lab[3]->setPixmap(MyPix);
    }
    if(OZU[1]!=NULL)
    {
        QPixmap MyPix;
        if(!MyPix.load(OZU[1]->GetImage()))
        {

            MyPix.load("Images/NoPhoto.jpg");
        }
        _lab[4]->setScaledContents(true);
        _lab[4]->setPixmap(MyPix);
    }
    else
    {
         QPixmap MyPix;
         MyPix.load("");
         _lab[4]->setScaledContents(true);
         _lab[4]->setPixmap(MyPix);
    }
}

int PowTwo(int n)
{
    int pow = 0;
    for(int i = 1;i<n;i*=2)
    {
        pow++;
    }
    return pow;
}
