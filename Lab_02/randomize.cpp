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

int Randomize::returnFunc()
{
    return values;
  //return int(this->ui->spinBox->value());
}

void Randomize::on_buttonBox_accepted()
{
    values = int(this->ui->spinBox->value());
    this->close();
}

void Randomize::on_buttonBox_rejected()
{
    values = -100;
    this->close();
}
