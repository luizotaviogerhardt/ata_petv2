#include "itemTopico.h"
#include <QDebug>
#include "responsaveis.h"


ItemTopico::ItemTopico(QString &string, MainWindow *janela, int id_comissao, int id_caixa)
{
      setupUi(this);

      this->mw = janela;
      this->id_caixa = id_caixa;
      this->id_comissao = id_comissao;

      this->lineEdit->setText(string);
      this->lineEdit->setCursorPosition(0);

      QPixmap pix("/home/gilmarllen/sign_check.png");
      this->check_img->setPixmap(pix);
}

void ItemTopico::on_lineEdit_textChanged(const QString &arg1)
{
    std::vector<comissao>* vetcom = mw->comissoes;
    (*vetcom)[id_comissao].setTopicoPosicao(id_caixa, arg1);
}

void ItemTopico::on_button_responsaveis_clicked()
{
    responsaveis resp;
    resp.setModal(true);
    resp.exec();
}
