#include "itemTopico.h"


ItemTopico::ItemTopico(QString &string)
{
      setupUi(this);
      this->lineEdit->setText(string);
      this->lineEdit->setCursorPosition(0);
      //ItemView.label->setText(string);
}
