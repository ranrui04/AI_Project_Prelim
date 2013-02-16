#include <QTextStream>
#include <QStringList>
#include <QFile>
#include "city.h"
#include "readfile.h"

void read_coordinate(QString filename)
{
    QFile f(filename);
    QList<City> city_list;
    City *cur_city;
    QStringList str;

    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
        QTextStream(stdout) << "Cannot Open File" << filename << endl;
    else {
        QTextStream in(&f);
        do {
            str.clear();
            str = in.readLine().split(' ');
            //QTextStream(stdout) << str.at(0) /*<< " " << str.at(1) << " " << str.at(2) << " " << city_list.size()*/ << endl;
            if (str.at(0) != "END") {
                cur_city = new City(str.at(0),str.at(1).toInt(),str.at(2).toInt());
                //cur_city->setName(str.at(0));
                //cur_city->setX(str.at(1).toInt());
                //cur_city->setY(str.at(2).toInt());
                city_list.append(*cur_city);
            }
        }while( str.at(0) != "END");
        //if (city_list.size()!=0)
            //QTextStream(stdout) << city_list.size() << endl;

        for(int i = 0; i < city_list.size(); i++)
        {
            *cur_city = city_list.at(i);
            QTextStream(stdout) << i+1 <<" "<< cur_city->getName() << " " <<cur_city->getX()<< " " << cur_city->getY()<< endl;
        }
        f.close();
        QTextStream(stdout) << "City Location File Read Done!" << endl;
    }
}
