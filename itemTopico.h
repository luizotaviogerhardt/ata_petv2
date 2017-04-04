#ifndef ITEMTOPICO_H
#define ITEMTOPICO_H

#include "ui_itemTopico.h"
#include "mainwindow.h"

class ItemTopico : public QWidget, private Ui::ItemTopico
{
    Q_OBJECT
    int id_comissao;
    int id_caixa;
    MainWindow* mw;

public:
    ItemTopico(QString &string, MainWindow* janela, int id_comissao, int id_caixa);
private slots:
    void on_lineEdit_textChanged(const QString &arg1);
    void on_button_responsaveis_clicked();
};

#endif // ITEMVIEW_H
