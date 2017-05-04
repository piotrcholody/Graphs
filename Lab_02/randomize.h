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
    int on_buttonBox_accepted();

private:
    Ui::Randomize *ui;
};

#endif // RANDOMIZE_H
