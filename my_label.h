#ifndef MY_LABEL_H
#define MY_LABEL_H

#include <QObject>
#include <QWidget>
#include<QLabel>

class my_label : public QLabel
{
public:
    Q_OBJECT
signals :
    void clicked();
public:
    my_label();
    void mousePressEvent(QMouseEvent* event);

    using QLabel::QLabel;
};

#endif // MY_LABEL_H
