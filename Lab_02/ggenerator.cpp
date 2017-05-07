#include "ggenerator.h"
#include "ui_ggenerator.h"
#include <utility>
#include <iostream>

GGenerator::GGenerator(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GGenerator)
{
    ui->setupUi(this);
}

GGenerator::~GGenerator()
{
    delete ui;
}

std::pair<int, double> GGenerator::returnFunc()
{
    return values; //std::pair<int,double>(this->ui->spinBox->value(),this->ui->doubleSpinBox->value());
}

void GGenerator::on_buttonBox_accepted()
{
    values = std::make_pair(this->ui->spinBox->value(),this->ui->doubleSpinBox->value());
    this->close();
}

void GGenerator::on_buttonBox_rejected()
{
    values = std::make_pair(-100,-100);
    this->close();
}

