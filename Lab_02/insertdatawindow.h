#ifndef INSERTDATAWINDOW_H
#define INSERTDATAWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <string>
#include <vector>
#include <algorithm>


namespace Ui {
class InsertDataWindow;
}

class InsertDataWindow : public QDialog
{
    Q_OBJECT

public:
    //friend class Graf;
    friend class GraphDraw2;
    explicit InsertDataWindow(QWidget *parent = 0);
    ~InsertDataWindow();

private slots:

    void on_Check_clicked();

    void on_tableWidget_cellChanged(int row, int column);

    std::vector<int> on_PBAccept_clicked();

    void on_PBAbort_clicked();

    void on_PBHelp_clicked();

private:
    Ui::InsertDataWindow *ui;
    std::vector<int> IDWseq;
};

#endif // INSERTDATAWINDOW_H
