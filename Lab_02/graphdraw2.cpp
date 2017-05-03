#include "graphdraw2.h"
#include "ui_graphdraw2.h"
#include "euler.h"
#include "regGraphGen.h"
#include "hamiltonian.h"
#include "insertdatawindow.h"
#include "ggenerator.h"
#include "ggeneratorve.h"
#include "ggeneratork.h"
GraphDraw2::GraphDraw2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphDraw2),
    gGraf(0),
    gRysuj(0)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->GVDraw->setScene(scene);
    scene->setBackgroundBrush(Qt::lightGray);

    gRysuj = new GrafRysuj(scene, 150);
    gGraf = new IncidenceMatrix;
    gGraf = nullptr;
}

GraphDraw2::~GraphDraw2()
{
    delete scene;
    delete ui;
    delete gGraf;
    delete gRysuj;
}

void GraphDraw2::on_PBInsertData_clicked()
{
    InsertDataWindow gIDW;
    gSvec.clear();
    gIDW.setModal(true);
    gIDW.exec();
    IncidenceMatrix* matrix = NULL;
    gSvec = gIDW.on_PBAccept_clicked();
    if(!gSvec.empty()){
        delete gGraf;
        IncidenceMatrix* matrix = new IncidenceMatrix(gSvec);
        this->gGraf = matrix;
        ui->PBDraw->setEnabled(true);
        ui->PBEulerian->setEnabled(true);
        ui->PBRandomize->setEnabled(true);
        ui->PBHamiltonianC->setEnabled(true);
        ui->PBConsistentSubG->setEnabled(true);
    }
    delete matrix;

}
void GraphDraw2::on_PBEulerian_clicked()
{
    if(!gGraf->getL())
        QMessageBox::information(0, "error","graf nie jest eulerowski");
    else
        if(isUndirectedEulerGraph(*gGraf) == 2){
            if(gGraf->getL() > 0)
                gRysuj->rysujEuler(findCycleInUndirectedEuler(*gGraf), gGraf->getN());
        }
        else if(isUndirectedEulerGraph(*gGraf) == 1)
            QMessageBox::information(0, "error","graf jest poleulerowski");
        else if(isUndirectedEulerGraph(*gGraf) == 0)
            QMessageBox::information(0, "error","graf nie jest eulerowski");
}

void GraphDraw2::on_PBHamiltonianC_clicked()
{
    std::vector<int> vec = findHamiltionianGraph(*gGraf);
     if(!vec.empty()) {
         if(vec[vec.size() - 1] == -1)
             QMessageBox::information(0, "error","graf jest polhamiltonowski");
         else
             gRysuj->rysujHamilton(vec);
     }
     else
         QMessageBox::information(0, "error","graf nie jest hamiltonowski");
}
/*
void GraphDraw2::on_PBRandomize_clicked()
{
    gGraf->generujGrafRand();
}
*/
void GraphDraw2::on_PBDraw_clicked()
{
    AdjacencyList* list = new AdjacencyList(*gGraf);
    ConnectionMatrix<int>* lista = new ConnectionMatrix<int>(*list);
    gRysuj->rysuj(lista);
    delete list;
    delete lista;
}

void GraphDraw2::on_PBConsistentSubG_clicked()
{
    std::vector <int> tmp = findTheLargestConnectedComponent(*gGraf);
    for (auto it = tmp.begin(); it != tmp.end(); ++it) {
        std::cout << tmp[*it] << std::endl;
    }
    tmp.push_back(tmp[0]);
    AdjacencyList* list = new AdjacencyList(*gGraf);
    ConnectionMatrix<int>* lista = new ConnectionMatrix<int>(*list);
    gRysuj->rysujSkladowa(lista, tmp);
    delete list;
    delete lista;
}

void GraphDraw2::on_actionGenerate_Vert_Edge_triggered()
{
    GGeneratorVE gen;
    gen.setModal(true);
    gen.exec();
    std::pair<int,int> ve_count = gen.on_buttonBox_accepted();
    ConnectionMatrix<int> *testCM = NULL;
    IncidenceMatrix* matrix = NULL;
    try{
        testCM = new ConnectionMatrix<int>();
        testCM->edgeGraph(ve_count.first,ve_count.second);
        IncidenceMatrix* matrix = new IncidenceMatrix(*testCM);
        delete gGraf;
        this->gGraf = matrix;
        ui->PBDraw->setEnabled(true);
        ui->PBEulerian->setEnabled(true);
        ui->PBRandomize->setEnabled(true);
        ui->PBHamiltonianC->setEnabled(true);
        ui->PBConsistentSubG->setEnabled(true);
    }
    catch(std::exception& e){
          QMessageBox::information(0, "error",e.what());
    }
    delete testCM;
    delete matrix;
}


void GraphDraw2::on_actionFrom_vertices_probability_triggered()
{
    GGenerator gen;
    gen.setModal(true);
    gen.exec();
    std::pair<int,double> values = gen.on_buttonBox_accepted();
    ConnectionMatrix<int> *testCM = NULL;
    IncidenceMatrix* matrix = NULL;
    try{
        testCM = new ConnectionMatrix<int>();
        testCM->probGraph(values.first,values.second);
        delete gGraf;
        IncidenceMatrix* matrix = new IncidenceMatrix(*testCM);
        this->gGraf = matrix;
        ui->PBDraw->setEnabled(true);
        ui->PBEulerian->setEnabled(true);
        ui->PBRandomize->setEnabled(true);
        ui->PBHamiltonianC->setEnabled(true);
        ui->PBConsistentSubG->setEnabled(true);
    }
    catch(std::exception& e){
          QMessageBox::information(0, "error",e.what());
    }
    delete testCM;
    delete matrix;
}

void GraphDraw2::on_actionFrom_k_regularity_triggered()
{
    GGeneratork gen;
    gen.setModal(true);
    gen.exec();
    std::pair<int,int> values = gen.on_buttonBox_accepted();
    gSvec.clear();
    for(int i=0; i<values.first; i++)
        gSvec.push_back(values.second);
    try{
        if(gSvec.empty())
            throw std::runtime_error("nie wpisano wartosci k");
        delete gGraf;
        gGraf = &regGraphGen(values.first, values.second);
        ui->PBDraw->setEnabled(true);
        ui->PBEulerian->setEnabled(true);
        ui->PBRandomize->setEnabled(true);
        ui->PBHamiltonianC->setEnabled(true);
        ui->PBConsistentSubG->setEnabled(true);
    }
    catch(std::exception& e){
          QMessageBox::information(0, "error",e.what());
        }
}

