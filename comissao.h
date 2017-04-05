#ifndef COMISSAO_H
#define COMISSAO_H

const int TAM = 100;

#include <QString>
#include <vector>
#include <QStringList>
#include <QVector>

class comissao
{
    QString nome;
    int id;
    QStringList topicos;
    std::vector<int> resps_topico[TAM];
    bool ativo;

public:
    comissao(QString &nome, int id, QStringList &topicos);
    ~comissao();
    QString getNome() const;
    void setNome(const QString &value);
    int getId() const;
    void setId(int value);
    QStringList getTopicos() const;
    void setTopicos(const QStringList &value);
    bool getAtivo() const;
    void setAtivo(bool value);
    void setTopicoPosicao(int pos, const QString &value);
    void insereResponsavel(int idresp,int idtopico);
    bool eResponsavel(int idresp,int idtopico);

};

#endif // COMISSAO_H
