#ifndef GRAPHDRAW2_H
#define GRAPHDRAW2_H

#include <QMainWindow>
#include <vector>
#include "grafrysuj.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFileDialog>
#include "IncidenceMatrix.h"

namespace Ui {
class GraphDraw2;
}

class GraphDraw2 : public QMainWindow
{
    Q_OBJECT

public:
    friend class IncidenceMatrix;
    explicit GraphDraw2(QWidget *parent = 0);
    ~GraphDraw2();

private slots:

    void on_PBInsertData_clicked();

    void on_PBEulerian_clicked();

    void on_PBHamiltonianC_clicked();

    void on_PBRandomize_clicked();

    void on_PBDraw_clicked();

    void on_PBConsistentSubG_clicked();

    void on_actionGenerate_Vert_Edge_triggered();

    void on_actionFrom_vertices_probability_triggered();

    void on_actionFrom_k_regularity_triggered();

private:
    Ui::GraphDraw2 *ui;
    QGraphicsScene* scene;
    IncidenceMatrix* gGraf;
    GrafRysuj* gRysuj;
    std::vector<int> gSvec;
};

#endif // GRAPHDRAW2_H
