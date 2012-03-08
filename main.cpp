/*
 * File:   main.cpp
 * Author: E082474W
 *
 * Created on 7 mars 2012, 09:37
 */

#include <QtGui/QApplication>
#include "Gui/mainwindow.h"

int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);

    QApplication app(argc, argv);
    MainWindow w;
    w.show();


    // create and show your widgets here

    return app.exec();
}

