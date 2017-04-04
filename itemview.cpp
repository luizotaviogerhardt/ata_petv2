#include "itemview.h"
#include <vector>
#include <QDebug>
#include "comissao.h"

ItemView::ItemView(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
}


ItemView::ItemView(QString &string, int id, MainWindow *janela)
{
      setupUi(this);

      this->nome->setText(string);
      this->id = id;
      this->mw = janela;
      this->nome->setStyleSheet("background-color:gray;");
}

void ItemView::on_nome_clicked()
{
    std::vector<comissao>* vetcom = mw->comissoes;
    bool atual = (*vetcom)[id].getAtivo();
    (*vetcom)[id].setAtivo(!atual);
    mw->atualizar();
}

void ItemView::on_pushButton_clicked()
{
    std::vector<comissao>* vetcom = mw->comissoes;
    QStringList topicos = (*vetcom)[id].getTopicos();

    if(topicos[topicos.size()-1] == "")
    {
        //this->pushButton->setDisabled(true);
        return;
    }

    //this->pushButton->setDisabled(false);

    (*vetcom)[id].setTopicos(topicos+="");

    mw->atualizar();
}
