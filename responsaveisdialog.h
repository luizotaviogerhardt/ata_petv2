#ifndef RESPONSAVEISDIALOG_H
#define RESPONSAVEISDIALOG_H

#include <QDialog>
#include <QMainWindow>
#include "mainwindow.h"
#include <QMessageBox>

namespace Ui {
class responsaveisDialog;
}

class responsaveisDialog : public QDialog
{
    Q_OBJECT
    MainWindow* window;
    int idtopico;
    int idcomissao;
    QMessageBox* msgBox;

public:
    explicit responsaveisDialog(QWidget *parent = 0, MainWindow *mw = 0, int idtopico = 0, int idcomissao = 0);
    ~responsaveisDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::responsaveisDialog *ui;
};

#endif // RESPONSAVEISDIALOG_H
