#ifndef CITY_H
#define CITY_H

#include <QString>

class City
{
private:
    int x, y;
    QString name;
public:
    City(QString n, int xco, int yco);
    void setX(int value);
    void setY(int value);
    void setName(QString str);
    int getX();
    int getY();
    QString getName();
};

#endif // CITY_H
