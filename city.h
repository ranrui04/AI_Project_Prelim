#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QList>

class City
{
private:
    int x, y;
    QString name;
    QList<City> conn;
    enum{VISITED,ELIMINATED,UNVISITED} state;
public:
    City();
    City(QString n, int xco, int yco);
    void setX(int value);
    void setY(int value);
    void setName(QString str);
    int getX();
    int getY();
    QString getName();
    void addConn(City &city);
    int nConn();
    const City & showConn(int i);
};

#endif // CITY_H
