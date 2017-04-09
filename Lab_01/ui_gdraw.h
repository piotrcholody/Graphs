/********************************************************************************
** Form generated from reading UI file 'gdraw.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GDRAW_H
#define UI_GDRAW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gdraw
{
public:
    QAction *actionImportFile;
    QAction *actionHelp;
    QAction *actionStartDrawing;
    QAction *actionShowRepresentations;
    QAction *actionSaveGraph;
    QAction *actionGenerate;
    QAction *actionGenerate_Vert_Edges;
    QAction *actionImport_Adjascency;
    QAction *actionImportIncidenceT;
    QAction *actionImportAdjascency_List;
    QWidget *centralWidget;
    QGraphicsView *graphicsView;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QTableWidget *tableWidget;
    QTableWidget *tableWidget_2;
    QTableWidget *tableWidget_3;
    QMenuBar *menuBar;
    QMenu *menuGdraw;
    QMenu *menuSave;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Gdraw)
    {
        if (Gdraw->objectName().isEmpty())
            Gdraw->setObjectName(QStringLiteral("Gdraw"));
        Gdraw->resize(1295, 765);
        actionImportFile = new QAction(Gdraw);
        actionImportFile->setObjectName(QStringLiteral("actionImportFile"));
        actionHelp = new QAction(Gdraw);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionStartDrawing = new QAction(Gdraw);
        actionStartDrawing->setObjectName(QStringLiteral("actionStartDrawing"));
        actionStartDrawing->setEnabled(false);
        actionShowRepresentations = new QAction(Gdraw);
        actionShowRepresentations->setObjectName(QStringLiteral("actionShowRepresentations"));
        actionShowRepresentations->setEnabled(false);
        actionSaveGraph = new QAction(Gdraw);
        actionSaveGraph->setObjectName(QStringLiteral("actionSaveGraph"));
        actionSaveGraph->setEnabled(false);
        actionGenerate = new QAction(Gdraw);
        actionGenerate->setObjectName(QStringLiteral("actionGenerate"));
        actionGenerate_Vert_Edges = new QAction(Gdraw);
        actionGenerate_Vert_Edges->setObjectName(QStringLiteral("actionGenerate_Vert_Edges"));
        actionImport_Adjascency = new QAction(Gdraw);
        actionImport_Adjascency->setObjectName(QStringLiteral("actionImport_Adjascency"));
        actionImportIncidenceT = new QAction(Gdraw);
        actionImportIncidenceT->setObjectName(QStringLiteral("actionImportIncidenceT"));
        actionImportAdjascency_List = new QAction(Gdraw);
        actionImportAdjascency_List->setObjectName(QStringLiteral("actionImportAdjascency_List"));
        centralWidget = new QWidget(Gdraw);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setGeometry(QRect(10, 0, 641, 341));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(660, 0, 191, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(660, 340, 131, 17));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 340, 111, 17));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(660, 20, 621, 321));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setProperty("showDropIndicator", QVariant(true));
        tableWidget_2 = new QTableWidget(centralWidget);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(660, 360, 621, 331));
        tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget_3 = new QTableWidget(centralWidget);
        tableWidget_3->setObjectName(QStringLiteral("tableWidget_3"));
        tableWidget_3->setGeometry(QRect(10, 360, 641, 331));
        tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
        Gdraw->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Gdraw);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1295, 21));
        menuGdraw = new QMenu(menuBar);
        menuGdraw->setObjectName(QStringLiteral("menuGdraw"));
        menuSave = new QMenu(menuBar);
        menuSave->setObjectName(QStringLiteral("menuSave"));
        Gdraw->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Gdraw);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        Gdraw->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Gdraw);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        Gdraw->setStatusBar(statusBar);

        menuBar->addAction(menuGdraw->menuAction());
        menuBar->addAction(menuSave->menuAction());
        menuGdraw->addAction(actionImportFile);
        menuGdraw->addSeparator();
        menuGdraw->addAction(actionGenerate);
        menuGdraw->addAction(actionGenerate_Vert_Edges);
        menuGdraw->addSeparator();
        menuGdraw->addAction(actionShowRepresentations);
        menuGdraw->addAction(actionStartDrawing);
        menuGdraw->addSeparator();
        menuGdraw->addAction(actionHelp);
        menuSave->addAction(actionSaveGraph);

        retranslateUi(Gdraw);
        QObject::connect(actionStartDrawing, SIGNAL(triggered()), graphicsView, SLOT(repaint()));

        QMetaObject::connectSlotsByName(Gdraw);
    } // setupUi

    void retranslateUi(QMainWindow *Gdraw)
    {
        Gdraw->setWindowTitle(QApplication::translate("Gdraw", "Gdraw", 0));
        actionImportFile->setText(QApplication::translate("Gdraw", "&ImportFile", 0));
        actionHelp->setText(QApplication::translate("Gdraw", "&Help", 0));
        actionStartDrawing->setText(QApplication::translate("Gdraw", "S&tartDrawing", 0));
        actionShowRepresentations->setText(QApplication::translate("Gdraw", "&ShowRepresentations", 0));
        actionSaveGraph->setText(QApplication::translate("Gdraw", "&SaveGraph", 0));
        actionGenerate->setText(QApplication::translate("Gdraw", "&Generate", 0));
        actionGenerate_Vert_Edges->setText(QApplication::translate("Gdraw", "Generate (Vert/Edges)", 0));
        actionImport_Adjascency->setText(QApplication::translate("Gdraw", "ImportAdjascencyTab", 0));
        actionImportIncidenceT->setText(QApplication::translate("Gdraw", "ImportIncidenceTab", 0));
        actionImportAdjascency_List->setText(QApplication::translate("Gdraw", "ImportAdjascency List", 0));
        label->setText(QApplication::translate("Gdraw", "Adjacency matrix", 0));
        label_2->setText(QApplication::translate("Gdraw", "Incidence matrix", 0));
        label_3->setText(QApplication::translate("Gdraw", "Adjacency list", 0));
        menuGdraw->setTitle(QApplication::translate("Gdraw", "D&isplay", 0));
        menuSave->setTitle(QApplication::translate("Gdraw", "Sa&ve", 0));
    } // retranslateUi

};

namespace Ui {
    class Gdraw: public Ui_Gdraw {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GDRAW_H
