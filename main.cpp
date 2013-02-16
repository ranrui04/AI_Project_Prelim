#include <QCoreApplication>
#include "readfile.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    read_coordinate();
    return a.exec();
}
