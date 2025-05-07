
#include <QApplication>
#include <QLabel>

#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MainWindow();
    w->show();
    //QLabel *label = new QLabel("hi there");
    //label->show();
    return a.exec();
}
