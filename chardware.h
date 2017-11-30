#ifndef CHARDWARE_H
#define CHARDWARE_H
#include <QString>
#include <QTableWidget>
#include <iostream>
#include <list>
#include <QFile>
#include <QTextStream>
#include <QErrorMessage>
#include <QMessageBox>
#include <QList>
#include <QTextBrowser>
#include <QLabel>
#include <QPixmap>
#include <QListWidget>
#include <QListWidgetItem>
#include <QtAlgorithms>
#include <QPushButton>

using namespace std;

int PowTwo(int);


//Інформація для створення апаратного забезпечення
struct DataHW
{
    int price;
    QString name;
    QString creator;
    QString type;
    int year;
    int cernel;
    float frequency;
    QString soket;
    QString GChip;
    int Cash;
    int maxmem;
    int canal_count;
    QString canal_type;
    int memory;
    int DirectX;
    float OpenGl;
    int Mfrequency;
    int Cfrequency;
    QString image;
    float pcxv;
    int pcxx;
    QString bufcpub;
    QString bufcpum;
    QString bufvcm;
    QString bufvcb;


};



//Базовий клас для апаратного та програмного забезпечення
class cWare
{
protected:
    int price;
    int year;
    QString name;
    QString creator;
    QString image;
public:

    cWare();
    virtual void Show(QTextBrowser*,QLabel*) = 0;
    virtual void setData(DataHW*) = 0;
    virtual DataHW *GetData() =0;
    virtual void PrintTF(QTextStream&) = 0;
    QString GetName();
    int GetPrice();
    QString GetImage();
    int GetYear();
};

//Клас процесора
class cCPU:public cWare
{
private:
    float frequency;
    int cernel;
    QString GChip;
    int Cash;
    QString soket;
public:
    cCPU();
    cCPU(DataHW*);
    int getFrequency();
    void setData(DataHW*);
    DataHW* GetData();
    void Show(QTextBrowser*,QLabel*);
    QString GetSoket();
    void PrintTF(QTextStream&);
    int GetCernel();



};

//Клас ОЗУ
class cOZU: public cWare
{
private:
    QString canal_type;
    int memory;
    int frequency;
public:
    cOZU();
    cOZU(DataHW*);
    void setData(DataHW*);
    DataHW* GetData();
    void Show(QTextBrowser*,QLabel*);
    int GetMemory();
    void PrintTF(QTextStream&);


};

//Клас материнської плати
class cMotherBoard:public cWare
{
private:
    QString soket;
    int maxmem;
    int canal_count;
    QString canal_type;
    float pcxv;
    int pcxx;
public:
    cMotherBoard();
    cMotherBoard(DataHW*);
    void setData(DataHW*);

    DataHW *GetData();
    void Show(QTextBrowser*,QLabel*);
    int GetCardPr();
    QString GetSoket();
    void PrintTF(QTextStream&);




};


//Клас відеокарти
class cVideoCard:public cWare
{
private:
    int DirectX;
    float OpenGl;
    int Mfrequency;
    int Cfrequency;
    float memory;
    float pcxv;
    int pcxx;
public:
    cVideoCard();
    cVideoCard(DataHW*);
    int GetMem();

    DataHW* GetData();
    void Show(QTextBrowser*,QLabel*);
    int GetCardPr();
    void PrintTF(QTextStream&);
    void setData(DataHW*);



};

//Клас жорсткого диску
class cHardDrive:public cWare
{
private:
    int memory;
    QString canal_type;
public:
    cHardDrive();
    cHardDrive(DataHW*);
    int GetMem();

    DataHW* GetData();
    void Show(QTextBrowser*,QLabel*);
    void PrintTF(QTextStream&);
    void setData(DataHW*);


};




//Структура системних вимог
struct cNeed
{
public:
    QString CPUbuf;
    QString VCBuf;
    cCPU* CPU;
    cVideoCard* VC;
    int memory;


};

//Список апаратного забезпечення
template <class T>
class cWareList
{
private:
    QList<T*> HList;
public:
    cWareList(){}
    void read(QString QS)
    {
        QFile FileM(QS);
        if(!FileM.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::information(0, "Information", "Не знайдено файл " + QS);
            return;
        }
        QTextStream MyText(&FileM);

        if(MyText.readLine().compare("CPU") == 0)
        {
            while(!MyText.atEnd())
            {
                DataHW * DHW = new DataHW();
                DHW->name = MyText.readLine();
                DHW->price = MyText.readLine().toInt();

                DHW->creator = MyText.readLine();
                DHW->year = MyText.readLine().toInt();
                if(DHW->price <=0 || DHW->year <=0)
                {   QMessageBox::information(0,"Помилка зчитування CPU.","Файл зчитано не повністю");

                    return; }
                DHW->soket = MyText.readLine();
                DHW->GChip = MyText.readLine();
                DHW->Cash = MyText.readLine().toInt();
                DHW->frequency = MyText.readLine().toInt();
                DHW->cernel = MyText.readLine().toInt();
                if(DHW->frequency <=0 || DHW->Cash <=0 || DHW->cernel <=0)
                {   QMessageBox::information(0,"Помилка зчитування CPU.","Файл зчитано не повністю");

                    return; }
                DHW->image = MyText.readLine();
                T *  NT = new T(DHW);
                HList << NT;
            }

        }

        MyText.seek(0);
        if(MyText.readLine().compare("MB") == 0)
        {
            while(!MyText.atEnd())
            {
                DataHW * DHW = new DataHW();
                DHW->name = MyText.readLine();
                DHW->price = MyText.readLine().toInt();

                DHW->creator = MyText.readLine();
                DHW->year = MyText.readLine().toInt();
                if(DHW->price <=0 || DHW->year <=0)
                {   QMessageBox::information(0,"Помилка зчитування MB.","Файл зчитано не повністю");

                    return; }
                DHW->soket = MyText.readLine();
                DHW->canal_count = MyText.readLine().toInt();
                DHW->canal_type = MyText.readLine();
                DHW->maxmem = MyText.readLine().toInt();
                DHW->pcxv = MyText.readLine().toFloat();
                DHW->pcxx = MyText.readLine().toInt();
                DHW->image = MyText.readLine();
                if(DHW->pcxx <=0 || DHW->pcxv <=0 || DHW->maxmem <=0 || DHW->canal_count <=0)
                {   QMessageBox::information(0,"Помилка зчитування MB.","Файл зчитано не повністю");

                    return; }
                T *  NT = new T(DHW);
                HList << NT;
            }
        }
        MyText.seek(0);
        if(MyText.readLine().compare("OZU") == 0)
        {
            while(!MyText.atEnd())
            {
                DataHW * DHW = new DataHW();
                DHW->name = MyText.readLine();
                DHW->price = MyText.readLine().toInt();

                DHW->creator = MyText.readLine();
                DHW->year = MyText.readLine().toInt();
                if(DHW->price <=0 || DHW->year <=0)
                {   QMessageBox::information(0,"Помилка зчитування OZU.","Файл зчитано не повністю");

                    return; }
                DHW->frequency = MyText.readLine().toInt();
                DHW->canal_type = MyText.readLine();
                DHW->memory = MyText.readLine().toInt();
                DHW->image = MyText.readLine();
                if(DHW->frequency <=0 || DHW->memory <=0)
                {   QMessageBox::information(0,"Помилка зчитування OZU.","Файл зчитано не повністю");

                    return; }
                T *  NT = new T(DHW);
                HList << NT;
            }
        }
        MyText.seek(0);
        if(MyText.readLine().compare("VC") == 0)
        {
            while(!MyText.atEnd())
            {
                DataHW * DHW = new DataHW();
                DHW->name = MyText.readLine();
                DHW->price = MyText.readLine().toInt();

                DHW->creator = MyText.readLine();
                DHW->year = MyText.readLine().toInt();
                if(DHW->price <=0 || DHW->year <=0)
                {   QMessageBox::information(0,"Помилка зчитування VC.","Файл зчитано не повністю");

                    return; }
                DHW->Cfrequency = MyText.readLine().toInt();
                DHW->Mfrequency = MyText.readLine().toInt();
                DHW->memory = MyText.readLine().toInt();
                DHW->DirectX = MyText.readLine().toInt();
                DHW->OpenGl = MyText.readLine().toFloat();
                DHW->pcxv = MyText.readLine().toFloat();
                DHW->pcxx = MyText.readLine().toInt();
                DHW->image = MyText.readLine();
                if(DHW->pcxx <=0 || DHW->pcxv <=0 || DHW->memory <=0 || DHW->OpenGl <=0 || DHW->DirectX <= 0 || DHW->Mfrequency <= 0 || DHW->Cfrequency <=0)
                {   QMessageBox::information(0,"Помилка зчитування VC.","Файл зчитано не повністю");

                    return; }
                T *  NT = new T(DHW);
                HList << NT;
            }
        }
        MyText.seek(0);
        if(MyText.readLine().compare("HW") == 0)
        {
            while(!MyText.atEnd())
            {
                DataHW * DHW = new DataHW();
                DHW->name = MyText.readLine();
                DHW->price = MyText.readLine().toInt();

                DHW->creator = MyText.readLine();
                DHW->year = MyText.readLine().toInt();
                if(DHW->price <=0 || DHW->year <=0)
                {   QMessageBox::information(0,"Помилка зчитування HW.","Файл зчитано не повністю");

                    return; }
                DHW->memory = MyText.readLine().toInt();
                DHW->canal_type = MyText.readLine();
                if(DHW->memory <=0)
                {   QMessageBox::information(0,"Помилка зчитування HW.","Файл зчитано не повністю");

                    return; }
                DHW->image = MyText.readLine();
                T *  NT = new T(DHW);
                HList << NT;
            }
        }
        MyText.seek(0);
        if(MyText.readLine().compare("SW") == 0)
        {
            while(!MyText.atEnd())
            {
                DataHW * DHW = new DataHW();

                DHW->name = MyText.readLine();
                DHW->price = MyText.readLine().toInt();

                DHW->creator = MyText.readLine();
                DHW->year = MyText.readLine().toInt();
                if(DHW->price <=0 || DHW->year <=0)
                {   QMessageBox::information(0,"Помилка зчитування SW.","Файл зчитано не повністю");

                    return; }
                DHW->bufcpum = MyText.readLine();
                DHW->bufvcm = MyText.readLine();
                DHW->memory= MyText.readLine().toInt();
                DHW->bufcpub = MyText.readLine();
                DHW->bufvcb = MyText.readLine();
                DHW->maxmem= MyText.readLine().toInt();
                DHW->image = MyText.readLine();
                T *  NT = new T(DHW);
                HList << NT;
            }
        }

        MyText.seek(0);
        MyText.flush();
        FileM.flush();
        FileM.close();

    }
    void print(QListWidget* QLW)
    {
        QLW->clear();
        foreach( T * item, HList ) {
            QListWidgetItem* listItem = new QListWidgetItem( item->GetName() );

            listItem->setFlags( Qt::ItemIsEditable | Qt::ItemIsEnabled );
            QLW->addItem( listItem );
        }
    }
    void ShowInf(int i,QTextBrowser* QTB,QLabel * QL)
    {
        if( i < HList.size() && i >= 0)
        {
            HList[i]->Show(QTB,QL);
        }
        else
        {
            return;
        }
    }
    T* getEl(int i)
    {
        return HList[i];
    }
    int getSize()
    {
        return HList.size();
    }
    void DeleteIn(int i)
    {
        HList.removeAt(i);
    }
    void Clear()
    {
        HList.clear();
    }
    void Add(T* t)
    {
        HList << t;
    }
    void PrintTF(QString QS,int n)
    {


        QFile FileM(QS);
        if(!FileM.open(QFile::WriteOnly | QFile::Text))
        {
            QMessageBox::information(0, "Information", "Не знайдено файл");
            return;
        }
        QTextStream MyText(&FileM);
        switch(n)
        {
        case 0:MyText << "MB";break;
        case 1:MyText << "CPU";break;
        case 2:MyText << "OZU";break;
        case 3:MyText << "VC";break;
        case 4:MyText << "HW";break;
        case 5:MyText << "SW";break;
        }
        for(int i = 0;i < HList.size();i++)
        {
            MyText << endl;
            HList[i]->PrintTF(MyText);
        }


        MyText.seek(0);
        MyText.flush();
        FileM.flush();
        FileM.close();

    }

};



//Класс програмне забезпечення

class cSoftware:public cWare
{
private:

    cNeed  best;
    cNeed  minimum;
public:

    cSoftware();
    cSoftware(DataHW*);
    cNeed* getBest();
    DataHW* GetData();
    cNeed* getMin();
    void Show(QTextBrowser*,QLabel*);
    bool Verification(cWareList<cCPU>,cWareList<cVideoCard>);
    void PrintTF(QTextStream&);
    void setData(DataHW*);


};

//Клас комп'ютер
class cComputer
{
private:
    cCPU *CPU;
    cOZU *OZU[2];
    cMotherBoard * MB;
    cVideoCard * VC;
    cHardDrive * HD;
    float grade;
    int price;
    int memozu;

public:
    cComputer();

    cComputer operator = (cComputer);

    bool SetCPU(cCPU*);
    int SetOZU(cOZU*);
    bool SetMB(cMotherBoard*);
    bool SetMB(cMotherBoard*,int);
    bool SetVC(cVideoCard*);
    bool SetHW(cHardDrive*);
    void DelCPU();
    void DelOZU(int);
    bool DelMB();
    void DelVC();
    void DelHW();
    void Show(QTextBrowser*);
    void Show(QLabel*[5]);
    int GetPrice();
    int GetMemOzu();
    bool IsFull();
    cCPU* GetCpu();
    cMotherBoard* GetMB();
    cVideoCard* GetVC();
    cHardDrive *GetHW();
    cOZU* GetOZU(int);
    int CheckSoftware(cSoftware*);


};

//Клас черга комп'ютерів

class cQueueComp
{
private:
    int iterator;
    QList<cComputer> list;
public:
    cQueueComp();
    cQueueComp(cComputer);
    void Add(cComputer);
    cComputer *GoBack(QPushButton*);
    cComputer *GoForward(QPushButton*);

};




#endif // CHARDWARE_H
