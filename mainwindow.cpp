#include "mainwindow.h"
#include "itemview.h"
#include <QFile>
#include <QTextStream>
#include <QString>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <vector>
#include <QMessageBox>
#include <QRadioButton>
#include "comissao.h"
#include <QVector>
#include <QStringList>
#include <stdio.h>
#include <QDebug>
#include "itemTopico.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    comissoes = new std::vector<comissao>();

    /*Leitura base de dados*/

    QFile file("/home/gilmarllen/bd.ata");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    int id=0;
    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList strList=line.split("/");

        QStringList topicos = strList;
        topicos.pop_front();
        comissao cms(strList[0],id,topicos);
        comissoes->push_back(cms);
        id++;
    }
    file.close();

    atualizar();
}

void MainWindow::atualizar(){

    listWidget->clear();

    for (unsigned int i = 0; i < comissoes->size(); i++)
    {
        QListWidgetItem *item = new QListWidgetItem;
        item->setSizeHint(QSize(150, 80));
        //item->setBackgroundColor("");
        item->setFlags(item->flags() & Qt::ItemIsSelectable);
        listWidget->addItem(item);

        QString texto_caixa = (*comissoes)[i].getNome();
        ItemView *botao = new ItemView(texto_caixa,(*comissoes)[i].getId(),this);
        listWidget->setItemWidget(item, botao);

        if(!(*comissoes)[i].getAtivo())
            continue;

        QStringList topicos = (*comissoes)[i].getTopicos();
        for (int j = 0; j < topicos.size(); j++) {
            item = new QListWidgetItem;
            item->setSizeHint(QSize(150, 50));
            item->setBackgroundColor("green");
            item->setFlags(item->flags() & Qt::ItemIsSelectable);
            listWidget->addItem(item);

            texto_caixa = topicos[j];
            ItemTopico *topico = new ItemTopico(texto_caixa, this, i, j);
            listWidget->setItemWidget(item, topico);

            //connect(topico, &ItemTopico::on_lineEdit_textChanged, botao, &ItemView::_on_caixa_changed);
        }
    }

}
