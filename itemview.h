#ifndef ITEMVIEW_H
#define ITEMVIEW_H

#include "ui_itemview.h"

class ItemView : public QWidget, private Ui::ItemView
{
    Q_OBJECT

public:
    explicit ItemView(QWidget *parent = 0);
};

#endif // ITEMVIEW_H
