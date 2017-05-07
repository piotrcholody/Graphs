#ifndef RANDOMIZE_H
#define RANDOMIZE_H

#include <QDialog>

namespace Ui {
class Randomize;
}

class Randomize : public QDialog
{
    Q_OBJECT

public:
    friend class GraphDraw2;
    explicit Randomize(QWidget *parent = 0);
    ~Randomize();

private slots:
    int returnFunc();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::Randomize *ui;
    int values;
};

#endif // RANDOMIZE_H
