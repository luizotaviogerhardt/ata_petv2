#ifndef RESPONSAVEIS_H
#define RESPONSAVEIS_H

#include <QWidget>
#include <QDialog>

namespace Ui {
class responsaveis;
}

class responsaveis : public QWidget
{
    Q_OBJECT

public:
    explicit responsaveis(QWidget *parent = 0);
    ~responsaveis();

private:
    Ui::responsaveis *ui;
};

#endif // RESPONSAVEIS_H
