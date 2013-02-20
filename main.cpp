/* Shortest Path using A* search algorithm
 * Ubuntu 12.10(Linux 3.5.0) with Qt 5.0.1
 * GUI will be added in final version
 * By Chengcheng Mou and Ran Rui, Feb 2013
 */

#include <QCoreApplication>
#include "readfile.h"
#include "search.h"
#include <QTextStream>
//#include <QString>
//

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString coordinate, connection, start, end, forbid;
    QTextStream(stdout) << "Please Specify City Coordinate File(Enter 0 for Default):" << endl;
    QTextStream(stdin) >> coordinate;
    if (coordinate.toInt() != 0)
        read_coordinate(coordinate);
    else
        read_coordinate();
    QTextStream(stdout) << "Please Specify City Connection File(Enter 0 for Default):" << endl;
    QTextStream(stdin) >> connection;
    if(connection.toInt() != 0)
        read_connection();
    else
        read_connection();
    while(start.isEmpty())
    {
        QTextStream(stdout) << "Please Specify Start City:" << endl;
        QTextStream(stdin) >> start;
    }
    while(end.isEmpty())
    {
        QTextStream(stdout) << "Please Specify End City:" << endl;
        QTextStream(stdin) >> end;
    }
    QTextStream(stdout) << "Please Specify Skipped City:" << endl;
    QTextStream(stdin) >> forbid;
    search(start, end, forbid);
    return a.exec();
}
