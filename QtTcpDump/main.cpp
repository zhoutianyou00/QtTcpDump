#include "QtTcpDump.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QtTcpDump w;
    w.show();
    return a.exec();
}
