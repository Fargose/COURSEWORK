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
using namespace std;
//Інформація для створення апаратного забезпечення
struct DataHW
{
    int price;
    QString name;
    QString creator;
    int year;
    int cernel;
    float frequency;
    QString soket;
    QString GChip;
    int Cash;
    int Powerty;
    int maxmem;
    int canal_count;
    QString canal_type;
    int memory;
    int DirectX;
    float OpenGl;
    int Mfrequency;
    int Cfrequency;
    QString image;


};



//Базовий клас для апаратного забезпечення
class cHardware
{
protected:
    int price;
    int year;
    QString name;
    QString creator;
    int grade;
    QString image;
public:

    cHardware();
    virtual float getGrade() = 0;
    virtual void Show(QTableWidget*,int) = 0;
    QString GetName();
};

//Клас процесора
class cCPU:public cHardware
{
private:
    float frequency;
    int cernel;
    QString GChip;
    int Cash;
    int Powerty;
    QString soket;
public:
    cCPU();
    cCPU(DataHW*);
    float getGrade();
    void Show(QTableWidget*,int);
    void Show(QTextBrowser*,QLabel*);

};

class cOZU: public cHardware
{
private:
    QString canal_type;
    int memory;
    int frequency;
public:
    cOZU();
    cOZU(DataHW*);
    float getGrade();
    void Show(QTableWidget*,int);
};

class cMotherBoard:public cHardware
{
private:
    QString soket;
    int maxmem;
    int canal_count;
    QString canal_type;
public:
    cMotherBoard();
    cMotherBoard(DataHW*);
    float getGrade();
    void Show(QTableWidget*,int);

};

class cVideoCard:public cHardware
{
private:
    int DirectX;
    float OpenGl;
    int Mfrequency;
    int Cfrequency;
    float memory;
public:
    cVideoCard();
    cVideoCard(DataHW*);
    void Show(QTableWidget*,int);
    float getGrade();


};

struct DataComp
{
    cCPU CPU;
   // cOZU OZU;

};

//Список апаратного забезпечення
template <class T>
class cHardList
{
private:
    QList<T*> HList;
public:
    cHardList(){}
    void read(QString QS)
    {
        QFile FileM(QS);
        if(!FileM.open(QFile::ReadOnly | QFile::Text))
        {
            QMessageBox::information(0, "Information", "Не знайдено файл");
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
                DHW->soket = MyText.readLine();
                DHW->Powerty = MyText.readLine().toInt();
                DHW->GChip = MyText.readLine();
                DHW->Cash = MyText.readLine().toInt();
                DHW->frequency = MyText.readLine().toInt();
                DHW->cernel = MyText.readLine().toInt();
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
                DHW->soket = MyText.readLine();
                DHW->canal_count = MyText.readLine().toInt();
                DHW->canal_type = MyText.readLine();
                DHW->maxmem = MyText.readLine().toInt();
                 DHW->image = MyText.readLine();
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
                DHW->frequency = MyText.readLine().toInt();
                DHW->canal_type = MyText.readLine();
                DHW->memory = MyText.readLine().toInt();
                 DHW->image = MyText.readLine();
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
                    DHW->Cfrequency = MyText.readLine().toInt();
                    DHW->Mfrequency = MyText.readLine().toInt();
                    DHW->memory = MyText.readLine().toInt();
                    DHW->DirectX = MyText.readLine().toInt();
                    DHW->OpenGl = MyText.readLine().toFloat();
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
    void print(QTableWidget* QTW)
    {
        QTW->setRowCount(HList.size());
        int i = 0;
        foreach(T * HW,HList)
        {
            HW->Show(QTW,i++);
        }
    }
    void print(QListWidget* QLW)
    {
        foreach( T * item, HList ) {
            QListWidgetItem* listItem = new QListWidgetItem( item->GetName() );

            listItem->setFlags( Qt::ItemIsEditable | Qt::ItemIsEnabled );
            QLW->addItem( listItem );
        }
    }
    void ShowInf(int i,QTextBrowser* QTB,QLabel * QL)
    {
        HList[i]->Show(QTB,QL);
    }
};



//Клас комп'ютер
class cComputer
{
private:
    cCPU CPU;
    int grade;
    int price;
};


//Класс програмне забезпечення

class cSoftware
{
private:
    QString type;
    cComputer best;
    cComputer minimum;

};
#endif // CHARDWARE_H
