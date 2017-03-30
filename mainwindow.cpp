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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);

    for (int i = 0; i < 20; ++i) {
        QListWidgetItem *item = new QListWidgetItem;
        item->setSizeHint(QSize(150, 80));
        listWidget->addItem(item);
        QString teste = "sfoaihfsao";
        ItemView *botao = new ItemView();
        listWidget->setItemWidget(item, botao);             //Sets the widget to be displayed in the given item. This function should only be used to display static content in the place of a list widget item. If you want to display custom dynamic content or implement a custom editor widget, use QListView and subclass QItemDelegate instead.
    }


    QFile file("/home/luizotavio/bd.ata");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);

    int id=1;
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

    /*for(int i =0; i <comissoes.size();i++)
    {
        QListWidgetItem *item = new QListWidgetItem;
        item = listWidget->currentItem();
        item->setText(comissoes[i].getNome());
    }*/



    //ui->scrollContents->setContentsMargins(0,0,0,0);


}
