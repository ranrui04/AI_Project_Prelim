#include <QTextStream>
#include <QStringList>
#include <QFile>
#include "city.h"
#include "readfile.h"

QList<City> city_list;

void read_coordinate(QString filename)
{
    QFile f(filename);
    City *cur_city;
    QStringList str;

    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
        QTextStream(stdout) << "Cannot Open File " << filename << endl;
    else {
        QTextStream in(&f);
        do {
            str.clear();
            str = in.readLine().split(' ');
            if (str.at(0) != "END") {
                cur_city = new City(str.at(0),str.at(1).toInt(),str.at(2).toInt());
                city_list.append(*cur_city);
            }
        }while( str.at(0) != "END");

        City c;
        for(int i = 0; i < city_list.size(); i++)
        {
            c = city_list.at(i);
            QTextStream(stdout) << i+1 <<" "<< c.getName() << " " <<c.getX()<< " " << c.getY()<< endl;
        }
        f.close();
        QTextStream(stdout) << "City Location File Read Done!" << endl;
    }
}

int find_city(QString cname)
{
    City c;
    int i;
    for (i = 0; i < city_list.size(); i++)
    {
        c = city_list.at(i);
        if (c.getName() == cname)
            break;
    }
    return i;
}

void read_connection(QString filename)
{
    QFile f(filename);
    QStringList str;
    if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
        QTextStream(stdout) << "Cannot Open File " << filename << endl;
    else {
        QTextStream in(&f);
        do {
            str.clear();
            str = in.readLine().split(' ');
            if (str.at(0) != "END") {
                int cur_c = find_city(str.at(0));
                City city = city_list.at(cur_c);
                for (int j = 0; j < str.at(1).toInt(); j++)
                {
                    int con_c = find_city(str.at(2+j));
                    city.addConn(con_c);
                }
                city_list.replace(cur_c, city);
            }
        }while( str.at(0) != "END");

        City c,d;
        for(int i = 0; i < city_list.size(); i++)
        {
            c = city_list.at(i);
            QTextStream(stdout) << c.getName() << " " <<c.nConn()<< " ";
            for (int j = 0; j < c.nConn(); j++)
            {
                d = city_list.at(c.connIndex(j));
                QTextStream(stdout) << d.getName() << " ";
            }
            QTextStream(stdout) << "\n";
        }
        QTextStream(stdout) << "City Connection File Read Done!" <<endl;
    }
}
