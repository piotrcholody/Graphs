#include "gdraw.h"
#include <QApplication>
#include <QtGui>
#include <ctime>
int main(int argc, char *argv[])
{
    srand(time(NULL));
    QApplication a(argc, argv);
    Gdraw w;
    w.show();

    return a.exec();
}
