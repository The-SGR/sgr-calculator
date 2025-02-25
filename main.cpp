#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle("SGR's Advanced Calculator");
    w.setFixedSize(335, 400);
    return a.exec();
}
