#ifndef CITY_H
#define CITY_H

#include <QString>
#include <QVector>

class City
{
private:
    int x, y;
    QString name;
    QVector<int> conn;
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
    void addConn(int i);
    int nConn();
    int connIndex(int i);
};

#endif // CITY_H
