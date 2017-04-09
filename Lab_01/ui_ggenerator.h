/********************************************************************************
** Form generated from reading UI file 'ggenerator.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGENERATOR_H
#define UI_GGENERATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GGenerator
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox;

    void setupUi(QDialog *GGenerator)
    {
        if (GGenerator->objectName().isEmpty())
            GGenerator->setObjectName(QStringLiteral("GGenerator"));
        GGenerator->resize(264, 110);
        buttonBox = new QDialogButtonBox(GGenerator);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(0, 70, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(GGenerator);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(40, 0, 184, 66));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(widget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(30);
        spinBox->setValue(6);

        horizontalLayout->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        doubleSpinBox = new QDoubleSpinBox(widget);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMaximum(1);
        doubleSpinBox->setSingleStep(0.01);
        doubleSpinBox->setValue(0.5);

        horizontalLayout_2->addWidget(doubleSpinBox);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(GGenerator);
        QObject::connect(buttonBox, SIGNAL(accepted()), GGenerator, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GGenerator, SLOT(reject()));

        QMetaObject::connectSlotsByName(GGenerator);
    } // setupUi

    void retranslateUi(QDialog *GGenerator)
    {
        GGenerator->setWindowTitle(QApplication::translate("GGenerator", "Dialog", 0));
        label->setText(QApplication::translate("GGenerator", "Vertices", 0));
        label_2->setText(QApplication::translate("GGenerator", "Edge probability", 0));
    } // retranslateUi

};

namespace Ui {
    class GGenerator: public Ui_GGenerator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGENERATOR_H
