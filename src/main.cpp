/********************************************
	* File Name : 	"main.cpp"
	* Authors : 	P. Boix and E. Moussy
	* Created on : 	10/11/2017
********************************************/

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    // Create the application
    QApplication a(argc, argv);

    // Create the main window and show it
    MainWindow w;
    w.show();

    return a.exec();
}