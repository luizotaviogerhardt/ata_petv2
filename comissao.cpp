#include "comissao.h"
#include <QString>
#include <QStringList>


int comissao::getId() const
{
    return id;
}

void comissao::setId(int value)
{
    id = value;
}

QStringList comissao::getTopicos() const
{
    return topicos;
}

void comissao::setTopicos(const QStringList &value)
{
    topicos = value; 
}

bool comissao::getAtivo() const
{
    return ativo;
}

void comissao::setAtivo(bool value)
{
    ativo = value;
}

QString comissao::getNome() const
{
    return nome;
}

void comissao::setNome(const QString &value)
{
    nome = value;
}
comissao::comissao(QString &nome, int id, QStringList &topicos)
{
    this->nome = nome;
    this->id = id;
    this->topicos = topicos;
    this->ativo = false;
}

void comissao::setTopicoPosicao(int pos, const QString &value)
{
    this->topicos.replace(pos, value);
}

void comissao::insereResponsavel(int idresp, int idtopico)
{
    for(int i =0;i<resps_topico[idtopico].size();i++)
    {
        if(resps_topico[idtopico][i] == idresp)
            return;
    }
    resps_topico[idtopico].push_back(idresp);
}

bool comissao::eResponsavel(int idresp,int idtopico)
{
    for(int i =0;i<resps_topico[idtopico].size();i++)
    {
        if(resps_topico[idtopico][i] == idresp)
            return true;
    }
    return false;
}

comissao::~comissao()
{

}
