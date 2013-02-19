#include <QCoreApplication>
#include "readfile.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    read_coordinate();
    read_connection();
    return a.exec();
}
