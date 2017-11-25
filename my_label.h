#ifndef MY_LABEL_H
#define MY_LABEL_H

#include <QObject>
#include <QWidget>
#include<QLabel>
#include <QMouseEvent>

class my_label : public QLabel
{
public:
    Q_OBJECT
signals :
    void clicked();
    void double_clicked();
public:
    my_label();
    void mousePressEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);

    using QLabel::QLabel;
};

#endif // MY_LABEL_H
