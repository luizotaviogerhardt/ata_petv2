#ifndef COMISSAO_H
#define COMISSAO_H

#include <QString>
#include <vector>
#include <QStringList>
#include <QVector>

class comissao
{
    QString nome;
    int id;
    QStringList topicos;
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
};

#endif // COMISSAO_H
