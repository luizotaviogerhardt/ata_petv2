#include "responsaveis.h"
#include "ui_responsaveis.h"
#include <QString>
#include <QRadioButton>

responsaveis::responsaveis(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::responsaveis)
{
    ui->setupUi(this);

    QString resps[12] = {"Lorenzo", "Gilmarllen", "Nicole", "Isabel", "Gustavo A.", "Luiz Otávio", "Luiz Antônio", "Felipe", "Douglas", "Rhuan"};

    for (int j = 0; j < 10; j++) {
        QListWidgetItem* item = new QListWidgetItem;
        //item->setSizeHint(QSize(150, 50));
        //item->setBackgroundColor("green");
        //item->setFlags(item->flags() & Qt::ItemIsSelectable);
        ui->listWidget->addItem(item);

        //texto_caixa = topicos[j];
        QRadioButton *botao = new QRadioButton(resps[j]);
        listWidget->setItemWidget(item, botao);

        //connect(topico, &ItemTopico::on_lineEdit_textChanged, botao, &ItemView::_on_caixa_changed);
    }

}

responsaveis::~responsaveis()
{
    delete ui;
}
