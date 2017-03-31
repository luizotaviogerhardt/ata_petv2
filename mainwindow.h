#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "comissao.h"

class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void atualizar();


    std::vector <comissao>* comissoes;

    std::vector<comissao> getComissoes() const;
    void setComissoes(std::vector<comissao> *value);
};

#endif // MAINWINDOW_H
