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
      //ItemView.label->setText(string);
}

void ItemView::on_nome_clicked()
{
    qWarning() << "CLICOU ESSA POHA";

    std::vector<comissao> vetcom = mw->getComissoes();

    bool atual = vetcom[id].getAtivo();


    qWarning() << vetcom[id].getNome() << endl;
    QString a = "sdefinas";
    vetcom[id].setNome(a);
    vetcom[id].setAtivo(!atual);
    qWarning() << vetcom[id].getNome() << " " << vetcom[id].getAtivo() << endl;




    mw->atualizar();

}
