/********************************************************************************
** Form generated from reading UI file 'graphdraw2.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHDRAW2_H
#define UI_GRAPHDRAW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphDraw2
{
public:
    QAction *actionImport_Graph;
    QAction *actionSave_Graph;
    QAction *actionGenerate_Vert_Edge;
    QAction *actionFrom_vertices_probability;
    QAction *actionFrom_k_regularity;
    QWidget *centralWidget;
    QGraphicsView *GVDraw;
    QPushButton *PBEulerian;
    QPushButton *PBHamiltonianC;
    QPushButton *PBRandomize;
    QPushButton *PBInsertData;
    QPushButton *PBDraw;
    QPushButton *PBConsistentSubG;
    QPushButton *PBEuler;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuGenerate_Graph;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *GraphDraw2)
    {
        if (GraphDraw2->objectName().isEmpty())
            GraphDraw2->setObjectName(QStringLiteral("GraphDraw2"));
        GraphDraw2->setEnabled(true);
        GraphDraw2->resize(616, 426);
        GraphDraw2->setAcceptDrops(false);
        actionImport_Graph = new QAction(GraphDraw2);
        actionImport_Graph->setObjectName(QStringLiteral("actionImport_Graph"));
        actionSave_Graph = new QAction(GraphDraw2);
        actionSave_Graph->setObjectName(QStringLiteral("actionSave_Graph"));
        actionGenerate_Vert_Edge = new QAction(GraphDraw2);
        actionGenerate_Vert_Edge->setObjectName(QStringLiteral("actionGenerate_Vert_Edge"));
        actionFrom_vertices_probability = new QAction(GraphDraw2);
        actionFrom_vertices_probability->setObjectName(QStringLiteral("actionFrom_vertices_probability"));
        actionFrom_k_regularity = new QAction(GraphDraw2);
        actionFrom_k_regularity->setObjectName(QStringLiteral("actionFrom_k_regularity"));
        centralWidget = new QWidget(GraphDraw2);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        GVDraw = new QGraphicsView(centralWidget);
        GVDraw->setObjectName(QStringLiteral("GVDraw"));
        GVDraw->setGeometry(QRect(200, 0, 411, 361));
        PBEulerian = new QPushButton(centralWidget);
        PBEulerian->setObjectName(QStringLiteral("PBEulerian"));
        PBEulerian->setEnabled(false);
        PBEulerian->setGeometry(QRect(30, 160, 141, 51));
        PBHamiltonianC = new QPushButton(centralWidget);
        PBHamiltonianC->setObjectName(QStringLiteral("PBHamiltonianC"));
        PBHamiltonianC->setEnabled(false);
        PBHamiltonianC->setGeometry(QRect(30, 210, 141, 51));
        PBRandomize = new QPushButton(centralWidget);
        PBRandomize->setObjectName(QStringLiteral("PBRandomize"));
        PBRandomize->setEnabled(false);
        PBRandomize->setGeometry(QRect(30, 260, 141, 51));
        PBInsertData = new QPushButton(centralWidget);
        PBInsertData->setObjectName(QStringLiteral("PBInsertData"));
        PBInsertData->setGeometry(QRect(30, 10, 141, 51));
        PBDraw = new QPushButton(centralWidget);
        PBDraw->setObjectName(QStringLiteral("PBDraw"));
        PBDraw->setEnabled(false);
        PBDraw->setGeometry(QRect(30, 60, 141, 51));
        PBConsistentSubG = new QPushButton(centralWidget);
        PBConsistentSubG->setObjectName(QStringLiteral("PBConsistentSubG"));
        PBConsistentSubG->setEnabled(false);
        PBConsistentSubG->setGeometry(QRect(30, 110, 141, 51));
        PBEuler = new QPushButton(centralWidget);
        PBEuler->setObjectName(QStringLiteral("PBEuler"));
        PBEuler->setGeometry(QRect(30, 310, 141, 51));
        GraphDraw2->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GraphDraw2);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 616, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuGenerate_Graph = new QMenu(menuFile);
        menuGenerate_Graph->setObjectName(QStringLiteral("menuGenerate_Graph"));
        GraphDraw2->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GraphDraw2);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        GraphDraw2->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GraphDraw2);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        GraphDraw2->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(menuGenerate_Graph->menuAction());
        menuGenerate_Graph->addSeparator();
        menuGenerate_Graph->addAction(actionGenerate_Vert_Edge);
        menuGenerate_Graph->addAction(actionFrom_vertices_probability);
        menuGenerate_Graph->addAction(actionFrom_k_regularity);

        retranslateUi(GraphDraw2);

        QMetaObject::connectSlotsByName(GraphDraw2);
    } // setupUi

    void retranslateUi(QMainWindow *GraphDraw2)
    {
        GraphDraw2->setWindowTitle(QApplication::translate("GraphDraw2", "GraphDraw2", 0));
        actionImport_Graph->setText(QApplication::translate("GraphDraw2", "Import Graph", 0));
        actionSave_Graph->setText(QApplication::translate("GraphDraw2", "Save Graph", 0));
        actionGenerate_Vert_Edge->setText(QApplication::translate("GraphDraw2", "from vertices/edges", 0));
        actionFrom_vertices_probability->setText(QApplication::translate("GraphDraw2", "from vertices/probability", 0));
        actionFrom_k_regularity->setText(QApplication::translate("GraphDraw2", "from k-regularity", 0));
        PBEulerian->setText(QApplication::translate("GraphDraw2", "Eulerian circle", 0));
        PBHamiltonianC->setText(QApplication::translate("GraphDraw2", "Hamiltonian circle", 0));
        PBRandomize->setText(QApplication::translate("GraphDraw2", "Randomize", 0));
        PBInsertData->setText(QApplication::translate("GraphDraw2", "Insert data", 0));
        PBDraw->setText(QApplication::translate("GraphDraw2", "Draw", 0));
        PBConsistentSubG->setText(QApplication::translate("GraphDraw2", "Consistent subgraph", 0));
        PBEuler->setText(QApplication::translate("GraphDraw2", "Random euler graph", 0));
        menuFile->setTitle(QApplication::translate("GraphDraw2", "File", 0));
        menuGenerate_Graph->setTitle(QApplication::translate("GraphDraw2", "Generate Graph", 0));
    } // retranslateUi

};

namespace Ui {
    class GraphDraw2: public Ui_GraphDraw2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHDRAW2_H
