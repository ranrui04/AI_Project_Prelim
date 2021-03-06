/* this file is the definition of class City,
 *which contains city location and connection
 *information and related member functions   */


#include "city.h"

City::City(QString n, int xco, int yco)
{
    name = n;
    x = xco;
    y = yco;
}

void City::setX(int value){x = value;}
void City::setY(int value){y = value;}
void City::setName(QString str){name = str;}
int City::getX(){return x;}
int City::getY(){return y;}
QString City::getName(){return name;}

void City::addConn(int i){conn.append(i);}
City::City(){}
int City::nConn()
{
    return conn.size();
}

int City::connIndex(int i)
{
    return conn.at(i);
}
