#include "ggeneratork.h"
#include "ui_ggeneratork.h"


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

std::pair<int, int> GGeneratork::on_buttonBox_accepted()
{
  return std::pair<int,int>(this->ui->spinBox->value(),this->ui->spinBox_2->value());
}

void GGeneratork::update(){
  int n = ui->spinBox->value();
  ui->spinBox_2->setMaximum(n - 1);
}
