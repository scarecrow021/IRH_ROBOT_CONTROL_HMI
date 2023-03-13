//#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup")



#include "mainhmi.h"

#pragma comment(lib, "Xinput.lib")
#pragma comment(lib, "Xinput9_1_0.lib")

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("windows");
    MainHMI w;
    w.PerformStartup();
    return a.exec();
}
