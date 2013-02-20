#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QVector>

class City
{
private:
    int x, y;  //coordinates
    QString name;  //city name
    QVector<int> conn;  //the index of cities connected to this one
    //enum{VISITED,ELIMINATED,UNVISITED} state;
public:
    City();
    City(QString n, int xco, int yco);  //initializer
    void setX(int value);
    void setY(int value);
    void setName(QString str);
    int getX();
    int getY();
    QString getName();
    void addConn(int i); //add connections
    int nConn();  //return number of connections
    int connIndex(int i);  //return index of a connection
};

#endif // CITY_H
