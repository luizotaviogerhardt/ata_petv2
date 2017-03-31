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

     //qDebug() << "IOHROSAHIORHA" << endl;
   // qWarning() << "IOHROSAHIORHA" << endl;


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
        comissoes.push_back(cms);
        id++;
    }

    file.close();

    atualizar();



/*    (int i =0; i <comissoes.size();i++)
    {
        QListWidgetItem *item = new QListWidgetItem;
        item = listWidget->currentItem();
        item->setText(comissoes[i].getNome());
    }*/



    //ui->scrollContents->setContentsMargins(0,0,0,0);
    atualizar();

}

void MainWindow::atualizar(){

    listWidget->clear();

    for (unsigned int i = 0; i < comissoes.size(); i++) {
        QListWidgetItem *item = new QListWidgetItem;
        item->setSizeHint(QSize(150, 80));
        listWidget->addItem(item);
        QString teste = comissoes[i].getNome();
        ItemView *botao = new ItemView(teste,comissoes[i].getId(),this);
        listWidget->setItemWidget(item, botao);

        if(!comissoes[i].getAtivo())
            continue;

        QStringList topicos = comissoes[i].getTopicos();
        for (int i = 0; i < topicos.size(); i++) {
            QListWidgetItem *item = new QListWidgetItem;
            item->setSizeHint(QSize(150, 80));
            listWidget->addItem(item);
            QString teste = topicos[i];
            ItemTopico *topico = new ItemTopico(teste);
            listWidget->setItemWidget(item, topico);


        }



    }

}

std::vector<comissao> MainWindow::getComissoes() const
{
    return comissoes;
}

void MainWindow::setComissoes(const std::vector<comissao> &value)
{
    comissoes = value;
}
