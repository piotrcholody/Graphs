#include "gdraw.h"
#include "graph.h"
#include "ui_gdraw.h"
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <string>
#include <sstream>
#include <vector>
#include <QtGui>

Gdraw::Gdraw(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Gdraw),
    curr_graph(0),
    gf(0)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    scene->setBackgroundBrush(Qt::lightGray);
    QMainWindow::showMaximized();

     tabW = ui->tableWidget;
     tabW2 = ui->tableWidget_2;
     tabW3 = ui->tableWidget_3;

     curr_graph=new ConnectionMatrix<int>();
     gf=new GrafRysuj(scene,150);
}
Gdraw::~Gdraw()
{
  delete ui;
  delete gf;
  delete curr_graph;
}

void Gdraw::on_actionStartDrawing_triggered(){
  try{
    gf->rysuj(curr_graph);
  }
    catch(std::exception& e){
      QMessageBox::information(0, "error",e.what());
    }
}

void Gdraw::on_actionImportFile_triggered()
{
    QString directory=QFileDialog::getOpenFileName(this,tr("Select file to import"),"/home/","*.graf");
    try{
      curr_graph->open(directory.toStdString());
      QMessageBox::information(0,"success","File loaded properly \n Ready to draw");
      ui->actionShowRepresentations->setEnabled(true);
      ui->actionStartDrawing->setEnabled(true);
      ui->actionSaveGraph->setEnabled(true);
    }
    catch(std::exception& e){
      QMessageBox::information(0, "error",e.what());
    }
}

void Gdraw::on_actionHelp_triggered()
{
    QMessageBox::information(0,"Help info","Import your file or create graph, and click - Start drawing. \nFormat: every connection in the new line - numbers of vertices in pair.");
}

void Gdraw::on_actionShowRepresentations_triggered()
{
    try{
    int min_width = 22; // minimalna szerokość komórki
    int min_height = 18; // minimalna wysokość komórki
    int slider_width = 28; //szerokość suwaka

    QStringList tabH;
    std::vector< std::vector<int> > tab = this->curr_graph->getMatrix();
    int n = this->curr_graph->getN();
    this->tabW->setColumnCount(n);
    this->tabW->setRowCount(n);
    for(int i = 0; i < n; i++){
            std::stringstream strs;
            strs << i;
            std::string temp_str = strs.str();
            tabH << temp_str.c_str();
        }
        tabW->setHorizontalHeaderLabels(tabH);
        tabW->setVerticalHeaderLabels(tabH);

    int tmp_width = (tabW->width()-slider_width)/n;
    int tmp_height = (tabW->height()-slider_width)/n;
    for(int i = 0; i < n; i++){
        tabW->setColumnWidth(i,(tmp_width>min_width) ? tmp_width : min_width);
        tabW->setRowHeight(i,(tmp_height>min_height) ? tmp_height : min_height);
        for(int j = 0; j < n; j++){
            if(tab[i][j])
                tabW->setItem(i, j, new QTableWidgetItem("1"));
            else
                tabW->setItem(i, j, new QTableWidgetItem("0"));
        }
    }

/*********Macierz Incydencji*********/
    IncidenceMatrix* matrix = new IncidenceMatrix(*curr_graph);
    int l = matrix->getL();
    n = matrix->getN();
    if (l)
    {
        QStringList tabHn, tabHl;
        int** tab2 = matrix->getMatrix();
        this->tabW2->setColumnCount(l);
        this->tabW2->setRowCount(n);
        for(int i=0; i<l; i++)
        {
            std::stringstream strs;
            strs << i;
            std::string temp_str = strs.str();
            tabHl << temp_str.c_str();
        }
        tabW2->setHorizontalHeaderLabels(tabHl);
        for(int i=0; i<n; i++)
        {
            std::stringstream strs;
            strs << i;
            std::string temp_str = strs.str();
            tabHn << temp_str.c_str();
        }
        tabW2->setVerticalHeaderLabels(tabHn);

        tmp_width = (tabW2->width()-slider_width)/l;
        tmp_height = (tabW2->height()-slider_width)/n;
        for(int i=0; i<n; i++)
        {
            tabW2->setRowHeight(i,(tmp_height>min_height) ? tmp_height : min_height);
            for(int j=0; j<l; j++)
            {
                tabW2->setColumnWidth(j,(tmp_width>min_width) ? tmp_width : min_width);
                if(tab2[i][j])
                    tabW2->setItem(i, j, new QTableWidgetItem("1"));
                else
                    tabW2->setItem(i, j, new QTableWidgetItem("0"));
            }
        }
    }
    else
    {
        tabW2->clear();
    }
    delete matrix;

/*********Lista Sąsiedztwa*********/

    IncidenceMatrix* matrix2 = new IncidenceMatrix(*curr_graph);
    AdjacencyList* list = new AdjacencyList(*matrix2);
    std::vector< std::vector<int> > tab3 = list->getMatrix();
    int maxL = list->maxL();
    if (maxL)
    {
        tabW3->clear();
        QStringList tabHn, tabHl;
        std::vector< std::vector<int> > tab3 = list->getMatrix();
        this->tabW3->setColumnCount(maxL);
        this->tabW3->setRowCount(n);
        for(int i=1; i<=maxL; i++)
        {
            std::stringstream strs;
            strs << i;
            std::string temp_str = strs.str();
            tabHl << temp_str.c_str();
        }
        tabW3->setHorizontalHeaderLabels(tabHl);
        for(int i=0; i<n; i++)
        {
            std::stringstream strs;
            strs << i;
            std::string temp_str = strs.str();
            tabHn << temp_str.c_str();
        }
        tabW3->setVerticalHeaderLabels(tabHn);

        tmp_width = (tabW3->width()-slider_width)/maxL;
        tmp_height = (tabW3->height()-slider_width)/n;
        for(int i=0; i<n; i++)
        {
            tabW3->setRowHeight(i,(tmp_height>min_height) ? tmp_height : min_height);
            for(unsigned int j=1; j<tab3[i].size(); j++)
            {
                tabW3->setColumnWidth(j,(tmp_width>min_width) ? tmp_width : min_width);
                QString s = QString::number(tab3[i].at(j));
                tabW3->setItem(i, j - 1, new QTableWidgetItem(s));
            }
        }
    }
    else
    {
        tabW3->clear();
    }
    delete list;
    delete matrix2;

  }
    catch(std::exception& e){
      QMessageBox::information(0, "error",e.what());
    }
}

void Gdraw::on_actionSaveGraph_triggered()
{
  QString directory=QFileDialog::getSaveFileName(this,"Zapis","/home/","*.graf");
   try{
    curr_graph->save(directory.toStdString());
  }
  catch(std::exception& e){
    QMessageBox::information(0, "error",e.what());
  }
}

void Gdraw::on_actionGenerate_triggered()
{
    GGenerator gen;
    gen.setModal(true);
    gen.exec();
    std::pair<int,double> values = gen.on_buttonBox_accepted();
    try{
     this->curr_graph->probGraph(values.first,values.second);
      ui->actionShowRepresentations->setEnabled(true);
      ui->actionStartDrawing->setEnabled(true);
      ui->actionSaveGraph->setEnabled(true);
    }
    catch(std::exception& e){
      QMessageBox::information(0, "error",e.what());
    }

}

void Gdraw::on_actionGenerate_Vert_Edges_triggered()
{
    GGeneratorVE gen;
    gen.setModal(true);
    gen.exec();
    std::pair<int,int> ve_count = gen.on_buttonBox_accepted();
    try{
        this->curr_graph->edgeGraph(ve_count.first,ve_count.second);
        ui->actionShowRepresentations->setEnabled(true);
        ui->actionStartDrawing->setEnabled(true);
        ui->actionSaveGraph->setEnabled(true);
    }
    catch(std::exception& e){
      QMessageBox::information(0, "error",e.what());
    }
}
