#ifndef ITEMVIEW_H
#define ITEMVIEW_H

#include "ui_itemview.h"
#include <vector>
#include "comissao.h"
#include "mainwindow.h"

class ItemView : public QWidget, private Ui::ItemView
{
    Q_OBJECT
    int id;
    MainWindow* mw;

public:
    explicit ItemView(QWidget *parent = 0);
    ItemView(QString &string, int id, MainWindow *janela);

private slots:
    void on_nome_clicked();
    void on_pushButton_clicked();
};

#endif // ITEMVIEW_H
