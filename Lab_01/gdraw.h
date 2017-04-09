#ifndef GDRAW_H
#define GDRAW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QTableWidget>
#include <QListWidget>
#include <vector>
#include <graph.h>
#include <ggenerator.h>
#include <ggeneratorve.h>
#include <grafrysuj.h>
#include <iostream>
#include <utility>

namespace Ui {
class Gdraw;
}

class Gdraw : public QMainWindow
{
    Q_OBJECT

public:
    explicit Gdraw(QWidget *parent = 0);
    ~Gdraw();

private slots:
    void on_actionStartDrawing_triggered();

    void on_actionImportFile_triggered();

    void on_actionHelp_triggered();

    void on_actionShowRepresentations_triggered();

    void on_actionSaveGraph_triggered();

    void on_actionGenerate_triggered();

    void on_actionGenerate_Vert_Edges_triggered();
/*
    void on_actionImport_Adjascency_triggered();

    void on_actionImportIncidenceT_triggered();

    void on_actionImportAdjascency_List_triggered();
*/
private:
    Ui::Gdraw *ui;
    std::vector<int>* v_ptr;
    QGraphicsScene* scene;
    QGraphicsRectItem* rect;
    QGraphicsLineItem* line;
    QTableWidget* tabW;
    QTableWidget* tabW2;
    QTableWidget* tabW3;

    ConnectionMatrix<int> *curr_graph = NULL;
    GrafRysuj *gf;
};

#endif // GDRAW_H
