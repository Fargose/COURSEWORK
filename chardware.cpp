#include "chardware.h"

using namespace std;

cHardware::cHardware()
{

}

QString cHardware::GetName()
{
    return name;
}

int cHardware::GetPrice()
{
    return price;
}

QString cHardware::GetImage()
{
    return image;
}

int cHardware::GetYear()
{
    return year;
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

int cCPU::getFrequency()
{
    return (int)frequency;
}

void cCPU::setData(DataHW *_d)
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

DataHW *cCPU::GetData()
{
   DataHW * HW = new DataHW;
   HW->name = name;
   HW->price = price;
   HW->creator = creator;
   HW->year = year;
   HW->image = image;
   HW->soket = soket;
   HW->cernel = cernel;

   HW->Cash = Cash;

   HW->GChip = GChip;
   HW->frequency = frequency;
   return HW;

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
    QL->setGeometry(580,QL->y(),400,300);
    QL->setPixmap(MyPix);

}

QString cCPU::GetSoket()
{
    return soket;
}

void cCPU::PrintTF(QTextStream  &QTS)
{
    QTS << name << endl;
    QTS << price << endl;
    QTS << creator << endl;
    QTS << year << endl;
    QTS << soket << endl;
    QTS << GChip << endl;
    QTS << Cash << endl;
    QTS << frequency << endl;
    QTS << cernel << endl;
    QTS << image;
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

void cMotherBoard::setData(DataHW * _d)
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



DataHW *cMotherBoard::GetData()
{
    DataHW * HW = new DataHW;
    HW->name = name;
    HW->price = price;
    HW->creator = creator;
    HW->year = year;
    HW->image = image;
    HW->soket = soket;
    HW->maxmem = maxmem;

    HW->canal_type = canal_type;
    HW->canal_count = canal_count;
    HW->pcxv = pcxv;
    HW->pcxx  = pcxx;

    return HW;

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
    QL->setGeometry(580,QL->y(),400,300);
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

void cMotherBoard::PrintTF(QTextStream &QTS)
{
    QTS << name << endl;
    QTS << price << endl;
    QTS << creator << endl;
    QTS << year << endl;
    QTS << soket << endl;
    QTS << canal_count << endl;
    QTS << canal_type << endl;

    QTS << maxmem << endl;
    QTS << pcxv << endl;
    QTS << pcxx << endl;
    QTS << image;
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

void cOZU::setData(DataHW * _d)
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


DataHW *cOZU::GetData()
{
    DataHW * HW = new DataHW;
    HW->name = name;
    HW->price = price;
    HW->creator = creator;
    HW->year = year;
    HW->image = image;
    HW->memory = memory;


    HW->canal_type = canal_type;


    HW->frequency = frequency;
    return HW;
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
    QL->setGeometry(580,QL->y(),400,300);
    QL->setPixmap(MyPix);
}

int cOZU::GetMemory()
{
    return memory;
}

void cOZU::PrintTF(QTextStream &QTS)
{
    QTS << name << endl;
    QTS << price << endl;
    QTS << creator << endl;
    QTS << year << endl;
    QTS << frequency << endl;
    QTS << canal_type << endl;
    QTS << memory << endl;

    QTS << image;
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

int cVideoCard::GetMem()
{
    return (int)memory;

}





DataHW *cVideoCard::GetData()
{
    DataHW * HW = new DataHW;
    HW->name = name;
    HW->price = price;
    HW->creator = creator;
    HW->year = year;
    HW->image = image;
    HW->DirectX = DirectX;
    HW->OpenGl = OpenGl;
    HW->memory= memory;

    HW->Cfrequency = Cfrequency;
    HW->Mfrequency= Mfrequency;
    HW->pcxv = pcxv;
    HW->pcxx  = pcxx;

    return HW;
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
    QL->setGeometry(580,QL->y(),400,300);
    QL->setPixmap(MyPix);
}

int cVideoCard::GetCardPr()
{
    int x = 0;
    x = pow(2.0,((int)pcxv+1)+PowTwo(pcxx));
    return x;
}

void cVideoCard::PrintTF(QTextStream &QTS)
{

        QTS << name << endl;
        QTS << price << endl;
        QTS << creator << endl;
        QTS << year << endl;
        QTS << Cfrequency << endl;
        QTS << Mfrequency<< endl;
         QTS << memory << endl;
          QTS << DirectX<< endl;
             QTS << OpenGl<< endl;
        QTS << pcxv<< endl;
        QTS << pcxx << endl;



        QTS << image;


}

void cVideoCard::setData(DataHW * _d)
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



cComputer::cComputer()
{
    CPU = NULL;
    OZU[0] = NULL;
    OZU[1] = NULL;
    MB = NULL;
    VC = NULL;
    HD = NULL;
    memozu = 0;
    price = 0;


}

cComputer::cComputer(DataComp * _d)
{
    CPU = _d->CPU;
    OZU[1] = _d->OZU[1];
    OZU[0] = _d->OZU[0];
    memozu = OZU[0]->GetMemory() + OZU[1]->GetMemory();
    MB = _d->MB;
    VC = _d->VC;
    HD = _d->HW;

}

cComputer cComputer::operator =(cComputer _C)
{
    CPU = _C.GetCpu();
    VC = _C.GetVC();
    OZU[0] = _C.GetOZU(0);
    OZU[1] = _C.GetOZU(1);
    MB = _C.GetMB();
    HD = _C.GetHW();
    price = _C.GetPrice();
    memozu = _C.GetMemOzu();
}

bool cComputer::SetCPU(cCPU * _CPU)
{

    if(MB == NULL)
    {
        QMessageBox::information(0, "Information", "Встановіть материнську плату для додавання інших елементів.");
        return false;
    }
    else
    {
        if(_CPU->GetSoket() != MB->GetSoket())
        {
            QMessageBox::information(0, "Information", "Не вдається установити процесор. Сокет материської плати відрізняється від процесора.");
            return false;
        }
        else
        {
            if(CPU==NULL)
                CPU = _CPU;
            else
                price-=CPU->GetPrice();
            CPU = _CPU;
            price+=_CPU->GetPrice();

            return true;
        }
    }

}

int cComputer::SetOZU(cOZU * _OZU)
{

    if(MB == NULL)
    {
        QMessageBox::information(0, "Information", "Встановіть материнську плату для додавання інших елементів.");

    }
    else if(OZU[0] != NULL && OZU[1] == NULL)
    {
        OZU[1] = OZU[0];
        OZU[0] = _OZU;
        price+=_OZU->GetPrice();
        memozu+=_OZU->GetMemory();
        return 0;
    }
    else if(OZU[0] != NULL && OZU[1] != NULL)
    {
        price-=OZU[0]->GetPrice();
        memozu-=OZU[0]->GetMemory();
        OZU[1] = OZU[0];
        OZU[0] = _OZU;
        price+=_OZU->GetPrice();
        memozu+=_OZU->GetMemory();
        return 0;
    }
    else
    {
        price+=_OZU->GetPrice();
        memozu+=_OZU->GetMemory();
        OZU[0] = _OZU;
        return 1;
    }
    return -1;
}

bool cComputer::SetMB(cMotherBoard * _MB)
{

    if(MB!=NULL)
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
            if(MB!=NULL)
            {
                price-=MB->GetPrice();
            }
            MB = NULL;
            if(CPU!=NULL)
            {
                price-=CPU->GetPrice();
            }
            CPU=NULL;
            if(OZU[0]!=NULL)
            {
                price-=OZU[0]->GetPrice();
            }
            OZU[0] = NULL;
            if(VC!=NULL)
            {
                price-=VC->GetPrice();
            }
            VC = NULL;
            if(OZU[1]!=NULL)
            {
                price-=OZU[1]->GetPrice();
            }
            OZU[1] = NULL;
            if(HD != NULL)
            {
                price-=HD->GetPrice();
            }
            HD = NULL;
            memozu = 0;


            MB=_MB;

            price+=MB->GetPrice();
        }

    }
    else
    {
        MB=_MB;

        price+=MB->GetPrice();
    }
}

bool cComputer::SetMB(cMotherBoard * _MB, int)
{
    if(MB!=NULL)
    {
        price-=MB->GetPrice();
    }
    MB = NULL;
    MB=_MB;

    price+=MB->GetPrice();
}

bool cComputer::SetVC(cVideoCard * _VC)
{
    if(MB == NULL)
    {
        QMessageBox::information(0, "Information", "Встановіть материнську плату для додавання інших елементів.");
        return false;
    }
    else
    {
        if(MB->GetCardPr() < _VC->GetCardPr())
        {
            QMessageBox::information(0, "Information", "Пропускна властивість материнської слота материнської плати менша за інтерфейс відеокарти. Можлива робота не в повну силу.");

        }
        if(VC!=NULL)
        {
            price-=VC->GetPrice();
        }
        VC =_VC;
        price+=VC->GetPrice();
        return true;
    }
}

bool cComputer::SetHW(cHardDrive * _HW)
{
    if(MB == NULL)
    {
        QMessageBox::information(0, "Information", "Встановіть материнську плату для додавання інших елементів.");
        return false;
    }
    else
    {
        if(HD!=NULL)
        {
            price-=HD->GetPrice();
        }
        HD = _HW;
        price+=HD->GetPrice();
        return true;
    }
}

void cComputer::DelCPU()
{
    if(CPU!=NULL)
        price-=CPU->GetPrice();
    CPU = NULL;
}

void cComputer::DelOZU(int i)
{
    if(OZU[i]!=NULL)
        price-=OZU[i]->GetPrice();
    memozu-=OZU[i]->GetMemory();
    OZU[i] = NULL;
}

bool cComputer::DelMB()
{
    if(MB!=NULL)
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
            if(MB!=NULL)
            {
                price-=MB->GetPrice();
            }
            MB = NULL;
            if(CPU!=NULL)
            {
                price-=CPU->GetPrice();
            }
            CPU=NULL;
            if(OZU[0]!=NULL)
            {
                price-=OZU[0]->GetPrice();
            }
            OZU[0] = NULL;
            if(VC!=NULL)
            {
                price-=VC->GetPrice();
            }
            VC = NULL;
            if(OZU[1]!=NULL)
            {
                price-=OZU[1]->GetPrice();
            }
            OZU[1] = NULL;
            if(HD != NULL)
            {
                price-=HD->GetPrice();
            }
            HD = NULL;
            memozu = 0;
            return true;
        }
        else
        {
            return false;
        }
    }
    return false;

}

void cComputer::DelVC()
{
    if(VC!=NULL)
    {
        price-=VC->GetPrice();
    }
    VC = NULL;
}

void cComputer::DelHW()
{if(VC!=NULL)
    {
        price-=HD->GetPrice();
    }
    HD =NULL;
}

void cComputer::Show(QTextBrowser * QTB)
{
    QTB->clear();
    if(CPU!=NULL)
    {
        QTB->append("Процесор: " + CPU->GetName());
    }
    else
    {
        QTB->append("Процесор: - " );
    }
    if(VC!=NULL)
    {
        QTB->append("Відеокарта: " + VC->GetName());
    }
    else
    {
        QTB->append("Відеокарта: - " );
    }
    QTB->append("ОЗУ: " + QString::number(memozu) + " Gb");
    QTB->append("Ціна: " + QString::number(price) + "$");

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
    if(HD !=NULL)
    {
        QPixmap MyPix;
        if(!MyPix.load(HD->GetImage()))
        {

            MyPix.load("Images/NoPhoto.jpg");
        }
        _lab[5]->setScaledContents(true);
        _lab[5]->setPixmap(MyPix);
    }
    else
    {
        QPixmap MyPix;
        MyPix.load("");
        _lab[5]->setScaledContents(true);
        _lab[5]->setPixmap(MyPix);
    }
}

int cComputer::GetPrice()
{
    return price;
}

int cComputer::GetMemOzu()
{
    return memozu;
}

bool cComputer::IsFull()
{
    if(CPU==NULL)
        return false;
    if(MB == NULL)
        return false;
    if(OZU[0] == NULL && OZU[1] == NULL)
        return false;
    if(VC == NULL)
        return false;
    if(HD == NULL)
        return false;
    return true;
}



cCPU *cComputer::GetCpu()
{
    return CPU;
}

cMotherBoard *cComputer::GetMB()
{
    return MB;
}

cVideoCard *cComputer::GetVC()
{
    return VC;
}

cHardDrive *cComputer::GetHW()
{
    return HD;
}

cOZU *cComputer::GetOZU(int i)
{
    return OZU[i];
}

int cComputer::CheckSoftware(cSoftware *_SW)
{
    if(IsFull() == false)
    {
        QMessageBox::information(0,"Збірка не повна!","Додайте до збірки елементи, яких не вистачає, щоб перевірити ПЗ.");
        return -1;
    }
    cNeed * _best = _SW->getBest();
    cNeed * _min = _SW->getMin();
    QString ResStr = "";


    double counter = 0;
    double res = 0;
    if(_min->CPU->GetYear() > CPU->GetYear())
    {

        ResStr+="Процесор (" +CPU->GetName() + ") слабший за мінімально потрібний (" + _min->CPU->GetName() + ")\n";
        counter++;
    }
    if(_min->VC->GetYear() > VC->GetYear())
    {

        ResStr+="Відеокарта (" +VC->GetName() + ") слабша за мінімально потрібну (" + _min->VC->GetName() + ")\n";
        counter++;
    }
    if(_min->memory > memozu)
    {

        ResStr+="Недостатньо ОЗУ: " + QString::number(memozu) + " Gb у наявності, " + QString::number(_min->memory)+"Gb мінімально потрібні" " \n";
        counter++;
    }
    if(counter > 0)
    {
        QMessageBox::information(0,"Виявлено проблеми!", ResStr);
    }
    if(counter == 3)
    {
        return 0;
    }
    if(_best->CPU->GetName() == CPU->GetName() || _best->CPU->GetYear() <= CPU->GetYear())
    {
        res+=30/(1 +counter/2);
    }
    if(_best->VC->GetName() == VC->GetName() || _best->VC->GetYear() <= VC->GetYear())
    {
        res+=60/(1 +counter/2);
    }
    if(_best->memory <= memozu)
    {
        res+=10/(1 + counter/2);
    }
    if(_best->CPU->GetYear()  > CPU->GetYear() && _min->CPU->GetYear() <= CPU->GetYear())
    {
        res+=30/(1 +counter/2 + (_best->CPU->GetYear()  - CPU->GetYear()));
    }
    if(_best->VC->GetYear()  > VC->GetYear() && _min->VC->GetYear() <= VC->GetYear())
    {
        res+=60/(1 +counter/2 + (_best->VC->GetYear()  - VC->GetYear()));
    }
    if(_best->memory > memozu && memozu >= _min->memory)
    {
        res+=10/(1 +counter/2 + (_best->memory - memozu));
    }
    return (int)res;


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

cHardDrive::cHardDrive(DataHW * _d)
{
    name = _d->name;
    price = _d->price;
    year = _d->year;
    creator = _d->creator;
    memory = _d->memory;
    image =_d->image;
    canal_type = _d->canal_type;
}

int cHardDrive::GetMem()
{
    return memory;
}



DataHW *cHardDrive::GetData()
{
    DataHW * HW = new DataHW;
    HW->name = name;
    HW->price = price;
    HW->creator = creator;
    HW->year = year;
    HW->image = image;
    HW->canal_type = canal_type;
    HW->memory = memory;
}

void cHardDrive::Show(QTextBrowser * QTB, QLabel *QL)
{
    QTB->clear();
    QTB->append("Назва: " + name);
    QTB->append("Ціна: " + QString::number(price) + " $");
    QTB->append("Виробник: " + creator);
    QTB->append("Рік виробництва: " + QString::number(year));
    QTB->append("Обсяг памя'ті: " +QString::number(memory) + " Gb");
    QTB->append("Тип пам'яті "  + canal_type);
    QPixmap MyPix;
    if(!MyPix.load(image))
    {
        image = "Images/NoPhoto.jpg";
        MyPix.load(image);
    }
    QL->setScaledContents(true);
    QL->setGeometry(580,QL->y(),400,300);
    QL->setPixmap(MyPix);
}

void cHardDrive::PrintTF(QTextStream  &QTS)
{

    QTS << name << endl;
    QTS << price << endl;
    QTS << creator << endl;
    QTS << year << endl;

    QTS << memory << endl;
    QTS << canal_type<< endl;


    QTS << image;
}

void cHardDrive::setData(DataHW * _d)
{
    name = _d->name;
    price = _d->price;
    year = _d->year;
    creator = _d->creator;
    memory = _d->memory;
    image =_d->image;
    canal_type = _d->canal_type;
}

cSoftware::cSoftware()
{

}



cSoftware::cSoftware(DataHW * _d)
{
    name = _d->name;

    year = _d->year;
    creator = _d->creator;
    best.CPUbuf = _d->bufcpub;
    best.memory = _d->maxmem;
    best.VCBuf = _d->bufvcb;
    minimum.CPUbuf = _d->bufcpum;
    minimum.VCBuf = _d->bufvcm;
    minimum.memory = _d->memory;
    price = _d->price;
    image = _d->image;
}

QString cSoftware::GetName()
{
    return name;
}

QString cSoftware::GetImage()
{
    return image;
}

cNeed *cSoftware::getBest()
{
    return &best;
}

DataHW *cSoftware::GetData()
{
    DataHW * HW = new DataHW;
    HW->name = name;
    HW->price = price;
    HW->creator = creator;
    HW->year = year;
    HW->image = image;
    HW->bufcpub = best.CPUbuf;
    HW->memory = minimum.memory;
    HW->maxmem = best.memory;
    HW->bufvcb = best.VCBuf;
    HW->bufvcm = minimum.VCBuf;
    HW->bufcpum = minimum.CPUbuf;
    return HW;

}

cNeed *cSoftware::getMin()
{
    return &minimum;
}

void cSoftware::Show(QTextBrowser * QTB, QLabel *QL)
{
    QTB->clear();
    QTB->append("Назва: " + name);
    QTB->append("Ціна: " + QString::number(price) + " $");
    QTB->append("Розробник: " + creator);
    QTB->append("Рік виробництва: " + QString::number(year));
    QTB->append("Мінімальні вимоги: ");
    QTB->append("Процесор: " + minimum.CPU->GetName());
    QTB->append("Відеокарта: " + minimum.VC->GetName());
    QTB->append("ОЗУ: " + QString::number(minimum.memory) + " Gb");
    QTB->append("Рекомендовані вимоги: ");
    QTB->append("Процесор: " + best.CPU->GetName());
    QTB->append("Відеокарта: " + best.VC->GetName());
    QTB->append("ОЗУ: " + QString::number(best.memory) + " Gb");
    QPixmap MyPix;
    if(!MyPix.load(image))
    {
        image = "Images/NoPhoto.jpg";
        MyPix.load(image);
    }
    QL->setScaledContents(true);
    QL->setGeometry(580,QL->y(),300,400);
    QL->setPixmap(MyPix);
}

bool cSoftware::Verification(cHardList<cCPU> cpuList, cHardList<cVideoCard> vList)
{
    for(int i = 0;i<cpuList.getSize();i++)
    {
        if(minimum.CPUbuf == cpuList.getEl(i)->GetName())
        {
            minimum.CPU = cpuList.getEl(i);
            break;
        }
        if(minimum.CPUbuf != cpuList.getEl(i)->GetName() && i == cpuList.getSize()-1)
        {
            QMessageBox::information(0,"Помилка веріфікації","В каталозі немає забезпечення за назвою " + minimum.CPUbuf + ". Програмне забезпечення вилучено.");
            return false;
        }
    }
    for(int i = 0;i<cpuList.getSize();i++)
    {
        if(best.CPUbuf == cpuList.getEl(i)->GetName())
        {
            best.CPU = cpuList.getEl(i);
            break;
        }
        if((best.CPUbuf != cpuList.getEl(i)->GetName()) && (i == cpuList.getSize()-1))
        {
            QMessageBox::information(0,"Помилка веріфікації","В каталозі немає забезпечення за назвою " + best.CPUbuf + ". Програмне забезпечення вилучено: " + name);
            return false;
        }
    }
    for(int i = 0;i<vList.getSize();i++)
    {
        if(best.VCBuf == vList.getEl(i)->GetName())
        {
            best.VC = vList.getEl(i);
            break;
        }
        if(best.VCBuf != vList.getEl(i)->GetName() && i == vList.getSize()-1)
        {
            QMessageBox::information(0,"Помилка веріфікації","В каталозі немає забезпечення за назвою " + best.VCBuf + ". Програмне забезпечення вилучено:" + name);
            return false;
        }
    }
    for(int i = 0;i<vList.getSize();i++)
    {
        if(minimum.VCBuf == vList.getEl(i)->GetName())
        {
            minimum.VC = vList.getEl(i);
            break;
        }
        if(minimum.VCBuf != vList.getEl(i)->GetName() && i == vList.getSize()-1)
        {
            QMessageBox::information(0,"Помилка веріфікації","В каталозі немає забезпечення за назвою " + minimum.VCBuf + ". Програмне забезпечення вилучено:" + name);
            return false;
        }
    }
    return true;
}

void cSoftware::PrintTF(QTextStream & QTS)
{
    QTS << name << endl;
    QTS << price << endl;
    QTS << creator << endl;
    QTS << year << endl;
    QTS << minimum.CPUbuf << endl;
    QTS << minimum.VCBuf << endl;

    QTS << minimum.memory << endl;
    QTS << best.CPUbuf << endl;
    QTS << best.VCBuf<< endl;

    QTS << best.memory << endl;






    QTS << image;
}

void cSoftware::setData(DataHW * _d)
{
    name = _d->name;
    type = _d->type;
    year = _d->year;
    creator = _d->creator;
    best.CPUbuf = _d->bufcpub;
    best.memory = _d->maxmem;
    best.VCBuf = _d->bufvcb;
    minimum.CPUbuf = _d->bufcpum;
    minimum.VCBuf = _d->bufvcm;
    minimum.memory = _d->memory;
    price = _d->price;
    image = _d->image;
}






cQueueComp::cQueueComp()
{

}

cQueueComp::cQueueComp(cComputer Cmp)
{
     iterator = 0;
     list.push_back(Cmp);
}

void cQueueComp::Add(cComputer  Cmp)
{
    if(list.size() > 10)
    {
        list.insert(iterator+1,Cmp);
        iterator++;
        list.pop_front();
//        for(int i = iterator + 1;i<list.size();i++)
//        {
//            list.removeAt(i);
//        }


    }
    else
    {
        list.insert(iterator+1,Cmp);
        iterator++;
//        for(int i = iterator + 1;i<list.size();i++)
//        {
//            list.removeAt(i);
//        }
    }
}

cComputer * cQueueComp::GoBack(QPushButton*QTB)
{
    if((iterator - 2) < 0)
    {
        QTB->setEnabled(false);
    }
    if(iterator - 1 >= 0)
    {

        cComputer *C = new cComputer;
        C = &list[--iterator];
        return C;

    }
    else return NULL;
}

cComputer* cQueueComp::GoForward(QPushButton*QTB)
{
    if(iterator + 2 >= list.size())
    {
        QTB->setEnabled(false);
    }
    if(iterator + 1 < list.size())
    {
        cComputer* C = new cComputer;
        C = &list[++iterator];
        return C;
    }

    else return NULL;
}
