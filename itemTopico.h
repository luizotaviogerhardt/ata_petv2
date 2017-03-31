#ifndef ITEMTOPICO_H
#define ITEMTOPICO_H

#include "ui_itemTopico.h"

class ItemTopico : public QWidget, private Ui::ItemTopico
{
    Q_OBJECT

public:
    ItemTopico(QString &string);
};

#endif // ITEMVIEW_H
