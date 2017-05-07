#ifndef GGENERATORK_H
#define GGENERATORK_H

#include <QDialog>


namespace Ui {
class GGeneratork;
}

class GGeneratork : public QDialog
{
    Q_OBJECT

public:
    friend class GraphDraw2;
    explicit GGeneratork(QWidget *parent = 0);
    ~GGeneratork();

private slots:
    std::pair<int,int> returnFunc();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void update();
private:
    Ui::GGeneratork *ui;
    std::pair<int,int> values;
};

#endif // GGENERATORK_H
