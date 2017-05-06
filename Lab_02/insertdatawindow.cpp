#include "insertdatawindow.h"
#include "ui_insertdatawindow.h"
#include "IncidenceMatrix.h"
#include <iostream>

InsertDataWindow::InsertDataWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InsertDataWindow)
{
    ui->setupUi(this);
    ui->tableWidget->setRowCount(1);
    ui->tableWidget->setColumnCount(10);
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->horizontalHeader()->hide();
    ui->tableWidget->resizeColumnsToContents();
}

InsertDataWindow::~InsertDataWindow()
{
    delete ui;
}

void InsertDataWindow::on_Check_clicked()
{
    for(int i = 0;  ui->tableWidget->item(0,i) != 0; i++){
        IDWseq.push_back(((ui->tableWidget->item(0,i)->text()).toInt()));
    }
    if(checkIfSequenceIsGraphic(IDWseq)){
        ui->PBAccept->setEnabled(true);
    }
    else{
        IDWseq.clear();
        QMessageBox::information(0, "error","sekwencja nie tworzy ciagu graficznego");
    }
}
void InsertDataWindow::on_tableWidget_cellChanged(int row, int column)
{
    IDWseq.clear();
    ui->PBAccept->setEnabled(false);
}

std::vector<int> InsertDataWindow::on_PBAccept_clicked()
{
    this->close();
    return IDWseq;
}

void InsertDataWindow::on_PBAbort_clicked()
{
    IDWseq.clear();
    this->close();
}

void InsertDataWindow::on_PBHelp_clicked()
{
    QMessageBox::information(0,"Help info", "Please insert numbers in seperate cells to make sequence - then push check to validate data");
}

