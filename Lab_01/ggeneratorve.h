#ifndef GGENERATORVE_H
#define GGENERATORVE_H

#include <QDialog>
#include <utility>
#include "graph.h"

namespace Ui {
class GGeneratorVE;
}

class GGeneratorVE : public QDialog
{
    Q_OBJECT

public:
    friend class Gdraw;
    explicit GGeneratorVE(QWidget *parent = 0);
    ~GGeneratorVE();

private slots:
    std::pair<int,int> on_buttonBox_accepted();
    void update();

private:
    Ui::GGeneratorVE *ui;
};

#endif // GGENERATORVE_H
