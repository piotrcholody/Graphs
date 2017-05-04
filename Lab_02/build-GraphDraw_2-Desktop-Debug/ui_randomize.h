/********************************************************************************
** Form generated from reading UI file 'randomize.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RANDOMIZE_H
#define UI_RANDOMIZE_H

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

class Ui_Randomize
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *spinBox;

    void setupUi(QDialog *Randomize)
    {
        if (Randomize->objectName().isEmpty())
            Randomize->setObjectName(QStringLiteral("Randomize"));
        Randomize->resize(237, 164);
        buttonBox = new QDialogButtonBox(Randomize);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-100, 110, 301, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        verticalLayoutWidget = new QWidget(Randomize);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(39, 30, 161, 80));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        spinBox = new QSpinBox(verticalLayoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(100000);

        horizontalLayout->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Randomize);
        QObject::connect(buttonBox, SIGNAL(accepted()), Randomize, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Randomize, SLOT(reject()));

        QMetaObject::connectSlotsByName(Randomize);
    } // setupUi

    void retranslateUi(QDialog *Randomize)
    {
        Randomize->setWindowTitle(QApplication::translate("Randomize", "Dialog", 0));
        label->setText(QApplication::translate("Randomize", "Ilo\305\233\304\207 losowa\305\204", 0));
    } // retranslateUi

};

namespace Ui {
    class Randomize: public Ui_Randomize {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RANDOMIZE_H
