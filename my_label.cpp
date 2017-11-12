#include "my_label.h"

my_label::my_label()
{

}

void my_label::mousePressEvent(QMouseEvent *event)
{
  emit clicked();
}
