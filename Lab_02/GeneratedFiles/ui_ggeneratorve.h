/********************************************************************************
** Form generated from reading UI file 'ggeneratorve.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGENERATORVE_H
#define UI_GGENERATORVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GGeneratorVE
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox;

    void setupUi(QDialog *GGeneratorVE)
    {
        if (GGeneratorVE->objectName().isEmpty())
            GGeneratorVE->setObjectName(QStringLiteral("GGeneratorVE"));
        GGeneratorVE->resize(264, 110);
        GGeneratorVE->setSizeGripEnabled(false);
        buttonBox = new QDialogButtonBox(GGeneratorVE);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(0, 70, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(GGeneratorVE);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(50, 10, 171, 66));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBox_2 = new QSpinBox(layoutWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(30);

        horizontalLayout->addWidget(spinBox_2);


        verticalLayout_2->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMaximum(1);
        spinBox->setValue(0);

        horizontalLayout_2->addWidget(spinBox);


        verticalLayout_2->addLayout(horizontalLayout_2);


        retranslateUi(GGeneratorVE);
        QObject::connect(buttonBox, SIGNAL(accepted()), GGeneratorVE, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GGeneratorVE, SLOT(reject()));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), GGeneratorVE, SLOT(update()));

        QMetaObject::connectSlotsByName(GGeneratorVE);
    } // setupUi

    void retranslateUi(QDialog *GGeneratorVE)
    {
        GGeneratorVE->setWindowTitle(QApplication::translate("GGeneratorVE", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("GGeneratorVE", "Vertices", Q_NULLPTR));
        label_2->setText(QApplication::translate("GGeneratorVE", "Edges", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GGeneratorVE: public Ui_GGeneratorVE {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGENERATORVE_H
