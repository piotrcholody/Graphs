#ifndef GGENERATOR_H
#define GGENERATOR_H

#include <QDialog>
#include <utility>
#include <iostream>

namespace Ui {
class GGenerator;
}

class GGenerator : public QDialog
{
    Q_OBJECT

public:
    friend class GraphDraw2;
    explicit GGenerator(QWidget *parent = 0);
    ~GGenerator();

private slots:
    std::pair<int,double> on_buttonBox_accepted();

private:
    Ui::GGenerator *ui;
};

#endif // GGENERATOR_H
