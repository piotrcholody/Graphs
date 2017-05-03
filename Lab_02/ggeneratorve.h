#ifndef GGENERATORVE_H
#define GGENERATORVE_H

#include <QDialog>


namespace Ui {
class GGeneratorVE;
}

class GGeneratorVE : public QDialog
{
    Q_OBJECT

public:
    friend class GraphDraw2;
    explicit GGeneratorVE(QWidget *parent = 0);
    ~GGeneratorVE();

private slots:
    std::pair<int,int> on_buttonBox_accepted();
    void update();

private:
    Ui::GGeneratorVE *ui;
};

#endif // GGENERATORVE_H
