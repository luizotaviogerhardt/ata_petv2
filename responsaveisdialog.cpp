#include "responsaveisdialog.h"
#include "ui_responsaveisdialog.h"
#include <QString>
#include <QRadioButton>
#include <QWidget>
#include <QCheckBox>
#include "comissao.h"
#include <QMainWindow>
#include "mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <string>

const int NPET = 10;

responsaveisDialog::responsaveisDialog(QWidget *parent,MainWindow* mw, int idtopico,int idcomissao) :
    QDialog(parent),
    ui(new Ui::responsaveisDialog)
{
    ui->setupUi(this);
    this->window = mw;
    this->idtopico = idtopico;
    this->idcomissao = idcomissao;
    QString resps[NPET] = {"Lorenzo", "Gilmarllen", "Nicole", "Isabel", "Gustavo A.", "Luiz Otávio", "Luiz Antônio", "Felipe", "Douglas", "Rhuan"};   //Depois isso vai ser adicionado via DB.
    std::vector<comissao>* vetcom = window->comissoes;
    for (int j = 0; j < NPET; j++) {
        QListWidgetItem* item = new QListWidgetItem(resps[j], ui->listWidget);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setFlags(item->flags() & ~Qt::ItemIsSelectable);
        if((*vetcom)[idcomissao].eResponsavel(j,idtopico))
            item->setCheckState(Qt::Checked);
        else
         item->setCheckState(Qt::Unchecked);
        //item->setSizeHint(QSize(150, 50));
        //item->setBackgroundColor("green");
        //item->setFlags(item->flags() & Qt::ItemIsSelectable);
        ui->listWidget->addItem(item);

        //texto_caixa = topicos[j];

        //ui->listWidget->setItemWidget(item,chbox);

        //connect(topico, &ItemTopico::on_lineEdit_textChanged, botao, &ItemView::_on_caixa_changed);
    }

}

responsaveisDialog::~responsaveisDialog()
{
    delete ui;
}

void responsaveisDialog::on_pushButton_clicked()    // Cancelar
{
    this->close();
}

void responsaveisDialog::on_pushButton_2_clicked()  // OK
{
    std::vector<comissao>* vetcom = window->comissoes;
    int qnt=0;
    for(int i=0;i<NPET;i++)
    {
        if(ui->listWidget->item(i)->checkState())
        {
            //qWarning() << i << endl;
            (*vetcom)[idcomissao].insereResponsavel(i,idcomissao);
            qnt++;
        }
    }
    std::string mensagem = qnt + "petianos foram adicionados como responsaveis.";
    msgBox  = new QMessageBox();
    msgBox->setWindowTitle("Alterações Feitas");
    msgBox->setText(QString::number(qnt)+" petianos selecionados.");
    msgBox->show();
    this->close();
}
