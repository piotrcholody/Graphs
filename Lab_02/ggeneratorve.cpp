#include "ggeneratorve.h"
#include "ui_ggeneratorve.h"
#include <utility>

GGeneratorVE::GGeneratorVE(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GGeneratorVE)
{
    ui->setupUi(this);
}

GGeneratorVE::~GGeneratorVE()
{
    delete ui;
}

std::pair<int,int> GGeneratorVE::returnFunc()
{
    //update();
    return values;
}

void GGeneratorVE::on_buttonBox_accepted()
{
    values = std::make_pair(this->ui->spinBox_2->value(),this->ui->spinBox->value());
    this->close();
}

void GGeneratorVE::on_buttonBox_rejected()
{
    values = std::make_pair(-100,-100);
    this->close();
}


void GGeneratorVE::update(){
  int n = ui->spinBox_2->value();
  ui->spinBox->setMaximum(n * (n - 1) / 2);
}
