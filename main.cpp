#include "mainwindow.h"
#include <QApplication>

double BugsPercentageOnEnv1;
double BugsPercentageOnEnv2;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
