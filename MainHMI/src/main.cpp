//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")

#include "mainhmi.h"

#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("windows");
    MainHMI w;
    w.PerformStartup();
    return a.exec();
}
