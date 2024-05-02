#include "stdafx.h"
#include "olibrary.h"
#include <QtWidgets/QApplication>
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Olibrary w;
    w.show();
    return a.exec();
}
