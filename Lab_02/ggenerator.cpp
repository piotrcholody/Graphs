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

std::pair<int, double> GGenerator::on_buttonBox_accepted()
{
    return std::pair<int,double>(this->ui->spinBox->value(),this->ui->doubleSpinBox->value());
}

void GGenerator::on_buttonBox_rejected()
{
    this->close();
}

