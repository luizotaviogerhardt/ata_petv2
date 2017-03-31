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
    mw->getComissoes()[id].setAtivo(!(mw->getComissoes()[id].getAtivo()));
    mw->atualizar();

}
