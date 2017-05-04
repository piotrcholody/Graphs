#include "randomize.h"
#include "ui_randomize.h"
#include <utility>
#include <iostream>

Randomize::Randomize(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Randomize)
{
    ui->setupUi(this);
}

Randomize::~Randomize()
{
    delete ui;
}

int Randomize::on_buttonBox_accepted()
{
  return int(this->ui->spinBox->value());
}
