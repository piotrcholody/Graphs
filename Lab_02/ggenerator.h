#ifndef GGENERATOR_H
#define GGENERATOR_H

#include <QDialog>
#include <QPushButton>

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
    void on_buttonBox_rejected();

private:
    Ui::GGenerator *ui;
    std::pair<int,double> values;
};

#endif // GGENERATOR_H
