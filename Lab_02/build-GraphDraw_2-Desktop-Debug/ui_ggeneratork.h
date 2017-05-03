/********************************************************************************
** Form generated from reading UI file 'ggeneratork.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GGENERATORK_H
#define UI_GGENERATORK_H

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

class Ui_GGeneratork
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QSpinBox *spinBox_2;

    void setupUi(QDialog *GGeneratork)
    {
        if (GGeneratork->objectName().isEmpty())
            GGeneratork->setObjectName(QStringLiteral("GGeneratork"));
        GGeneratork->resize(264, 110);
        buttonBox = new QDialogButtonBox(GGeneratork);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(0, 70, 221, 41));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(GGeneratork);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(40, 10, 184, 66));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(30);
        spinBox->setValue(5);

        horizontalLayout->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_2->addWidget(label_2);

        spinBox_2 = new QSpinBox(layoutWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setValue(2);

        horizontalLayout_2->addWidget(spinBox_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(GGeneratork);
        QObject::connect(buttonBox, SIGNAL(accepted()), GGeneratork, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GGeneratork, SLOT(reject()));
        QObject::connect(spinBox_2, SIGNAL(valueChanged(int)), GGeneratork, SLOT(update()));

        QMetaObject::connectSlotsByName(GGeneratork);
    } // setupUi

    void retranslateUi(QDialog *GGeneratork)
    {
        GGeneratork->setWindowTitle(QApplication::translate("GGeneratork", "Dialog", 0));
        label->setText(QApplication::translate("GGeneratork", "Vertices", 0));
        label_2->setText(QApplication::translate("GGeneratork", "k", 0));
    } // retranslateUi

};

namespace Ui {
    class GGeneratork: public Ui_GGeneratork {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GGENERATORK_H
