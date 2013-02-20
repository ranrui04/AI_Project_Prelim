#include "city.h"
#include <QList>
#include "readfile.h"
#include <QTextStream>

extern QList<City> city_list;

typedef enum{START, END, OPEN, CLOSED} State;
State *state;

void search(QString start, QString end, QString forbid)
{
    int s_index, e_index, f_index;
    s_index = find_city(start);
    e_index = find_city(end);
    f_index = find_city(forbid);
    if (s_index >= city_list.size())
        QTextStream(stdout) << "Start Point Not Found!\n";
    if (e_index >= city_list.size())
        QTextStream(stdout) << "End Point Not Found!\n";
    if (f_index >= city_list.size())
        QTextStream(stdout) << "Eliminated Point Not Found!\n";
    state = malloc(sizeof(State) * city_list.size());
    for (int i; i < city_list.size(); i++)
    {
        if (city_list.at(i).nConn() == 0)
            state[i] = DE;
        else {
        switch(i)
        {
        case s_index:
            state[i] = START;
            break;
        case e_index:
            state[i] = END;
            break;
        case f_index:
            state[i] = DE;
            break;
        default:
            state[i] = OPEN;
            break;
        }
        }
    }
}

void a_star_search(int start, int end)
{

}
