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

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);


    QFile file("/home/luizotavio/bd.ata");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QTextStream in(&file);

    std::vector <comissao> comissoes;

    int id=1;
    while (!in.atEnd())
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

    for (int i = 0; i < 20; ++i) {
        QListWidgetItem *item = new QListWidgetItem;
        item->setSizeHint(QSize(150, 80));
        listWidget->addItem(item);
        listWidget->setItemWidget(item, new ItemView);
    }
}
