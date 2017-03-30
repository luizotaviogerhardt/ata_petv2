#include "itemview.h"

ItemView::ItemView(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}


ItemView::ItemView(QString &string)
{
      this->label->setText(string);
}

void ItemView::setLabel(QString &string)
{
     this->label->setText(string);
}
