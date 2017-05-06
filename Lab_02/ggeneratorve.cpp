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

std::pair<int,int> GGeneratorVE::on_buttonBox_accepted()
{
    update();
    return std::pair<int,double>(this->ui->spinBox_2->value(),this->ui->spinBox->value());
}

void GGeneratorVE::on_buttonBox_rejected()
{
    this->close();
}


void GGeneratorVE::update(){
  int n = ui->spinBox_2->value();
  ui->spinBox->setMaximum(n * (n - 1) / 2);
}
