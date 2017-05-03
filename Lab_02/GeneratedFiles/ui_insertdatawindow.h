/********************************************************************************
** Form generated from reading UI file 'insertdatawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSERTDATAWINDOW_H
#define UI_INSERTDATAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InsertDataWindow
{
public:
    QPushButton *Check;
    QSplitter *splitter;
    QPushButton *PBHelp;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *PBAbort;
    QPushButton *PBAccept;
    QWidget *widget1;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableWidget *tableWidget;

    void setupUi(QDialog *InsertDataWindow)
    {
        if (InsertDataWindow->objectName().isEmpty())
            InsertDataWindow->setObjectName(QStringLiteral("InsertDataWindow"));
        InsertDataWindow->resize(361, 101);
        Check = new QPushButton(InsertDataWindow);
        Check->setObjectName(QStringLiteral("Check"));
        Check->setGeometry(QRect(260, 0, 99, 61));
        splitter = new QSplitter(InsertDataWindow);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(40, 70, 321, 29));
        splitter->setOrientation(Qt::Horizontal);
        PBHelp = new QPushButton(splitter);
        PBHelp->setObjectName(QStringLiteral("PBHelp"));
        splitter->addWidget(PBHelp);
        widget = new QWidget(splitter);
        widget->setObjectName(QStringLiteral("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        splitter->addWidget(widget);
        PBAbort = new QPushButton(splitter);
        PBAbort->setObjectName(QStringLiteral("PBAbort"));
        splitter->addWidget(PBAbort);
        PBAccept = new QPushButton(splitter);
        PBAccept->setObjectName(QStringLiteral("PBAccept"));
        PBAccept->setEnabled(false);
        splitter->addWidget(PBAccept);
        widget1 = new QWidget(InsertDataWindow);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(0, 0, 258, 61));
        verticalLayout = new QVBoxLayout(widget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget1);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        tableWidget = new QTableWidget(widget1);
        if (tableWidget->columnCount() < 1)
            tableWidget->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        if (tableWidget->rowCount() < 1)
            tableWidget->setRowCount(1);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem1);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout->addWidget(tableWidget);


        retranslateUi(InsertDataWindow);

        QMetaObject::connectSlotsByName(InsertDataWindow);
    } // setupUi

    void retranslateUi(QDialog *InsertDataWindow)
    {
        InsertDataWindow->setWindowTitle(QApplication::translate("InsertDataWindow", "Insert data", Q_NULLPTR));
        Check->setText(QApplication::translate("InsertDataWindow", "Check", Q_NULLPTR));
        PBHelp->setText(QApplication::translate("InsertDataWindow", "Help", Q_NULLPTR));
        PBAbort->setText(QApplication::translate("InsertDataWindow", "Cancel", Q_NULLPTR));
        PBAccept->setText(QApplication::translate("InsertDataWindow", "OK", Q_NULLPTR));
        label->setText(QApplication::translate("InsertDataWindow", "Graphical sequence", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("InsertDataWindow", "*", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem1->setText(QApplication::translate("InsertDataWindow", "*", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class InsertDataWindow: public Ui_InsertDataWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSERTDATAWINDOW_H
