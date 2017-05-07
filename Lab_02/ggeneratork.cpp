#include "ggeneratork.h"
#include "ui_ggeneratork.h"
#include <utility>
#include <iostream>

GGeneratork::GGeneratork(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GGeneratork)
{
    ui->setupUi(this);
}

GGeneratork::~GGeneratork()
{
    delete ui;
}

std::pair<int, int> GGeneratork::returnFunc()
{
  return values;
}

void GGeneratork::on_buttonBox_accepted()
{
    values = std::make_pair(this->ui->spinBox->value(),this->ui->spinBox_2->value());
    this->close();
}

void GGeneratork::on_buttonBox_rejected()
{
    values = std::make_pair(-100,-100);
    this->close();
}

void GGeneratork::update(){
  int n = ui->spinBox->value();
  ui->spinBox_2->setMaximum(n - 1);
}
