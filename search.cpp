#include "city.h"
#include <QList>
#include "readfile.h"
#include <QTextStream>
#include <qmath.h>
#include <QStack>

extern QList<City> city_list;

//typedef enum{START, END, OPEN, CLOSED} State;
//State *state;
//QList<City> path;

int *prev_city;   //stores the previous node of current one
int *open;   //1 if node is open for evaluation, 0 if excluded from evaluation, -1 if unvisited
double *dist_trav;  //distance traveled by current node
double *dist_total;  //distance traveled + heuristic

bool a_star_search(int start, int end, int forbid);  //A* seach
void output_path(int start, int end);  //output the optimal path

//preperation before search
void search(QString start,QString end, QString forbid)
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
    //state = malloc(sizeof(State) * city_list.size());

    if(a_star_search(s_index, e_index, f_index))
        QTextStream(stdout) << "No Path Found!" << endl;
}

//return whether there are open nodes to be evaluated
int open_is_empty()
{
    for(int i = 0; i < city_list.size(); i++)
    {
        if (open[i] == 1)
            return 0;
    }
    return 1;
}

//calculate the distance between to cities
double distance(int p1, int p2)
{
    City c1,c2;
    c1 = city_list.at(p1);
    c2 = city_list.at(p2);
    return qSqrt(qPow(c1.getX()-c2.getX(),2) + qPow(c1.getY()-c2.getY(),2));
}

//find the node with minimum cost among those that are open for evaluation
int find_min_cost()
{
    double min = 999999999;
    int index;
    for (int i = 0; i < city_list.size(); i++)
    {
        if (open[i] == 1 && dist_total[i] < min)
        {
            min = dist_total[i];
            index = i;
        }
    }
    return index;
}

//A* search algorithm
bool a_star_search(int start, int end, int forbid)
{    
    prev_city = (int*)malloc(sizeof(int) * city_list.size());
    open = (int*)malloc(sizeof(int) * city_list.size()+1);
    dist_trav = (double*)malloc(sizeof(double) * city_list.size());
    dist_total = (double*)malloc(sizeof(double) * city_list.size());

    /* nodes that are excluded are set to "close" before search,
     *start node is set to open,
     *others are unvisited,
     *distances are set to Infinity except for the start node */
    for(int i = 0; i < city_list.size(); i++)
    {
        prev_city[i] = city_list.size();
        if (i == start)
        {
            open[i] = 1;
            dist_trav[i] = 0;
            dist_total[i] = dist_trav[i] + distance(start, end);
        }
        else
        {
            open[i] = -1;
            dist_trav[i] = 999999999;
            dist_total[i] = 999999999;
        }
        if (i == forbid)
            open[i] = 0;
    }

    int cur_index = start;
    City cur_city;
    double accum_dist;

    while (!open_is_empty())  //continue evaluation if there are open nodes
    {
        cur_index = find_min_cost();
        if (cur_index == end)  //reach end node, output the path and return
        {
            output_path(start,end); //output path
            return 0;
        }
        open[cur_index] = 0;  //current node is closed
        cur_city = city_list.at(cur_index);
        //QTextStream(stdout) << cur_city.getName() << endl;
        for(int i = 0; i < cur_city.nConn(); i++)  //evaluate connected nodes with heuristic
        {
            int j = cur_city.connIndex(i);
            if (open[j] == 0)   //skip if node is closed
                continue;
            accum_dist = dist_trav[cur_index] + distance(j, cur_index);  //distance

            //update info if node is unvisited or obtain a smaller distance after evaluation
            if (open[j] != 1 || accum_dist < dist_trav[j])
            {
                prev_city[j] = cur_index;
                dist_trav[j] = accum_dist;
                dist_total[j] = dist_trav[j] + distance(j, end);
                if (open[j] != 1)  //if never visited, add to open set
                    open[j] = 1;
            }
        }
    }
    return 1;
}

// backtrace the path and output
void output_path(int start, int end)
{
    QStack<int> s;
    int prev_index = end;
    s.push(end);
    while(prev_index != start)
    {
        prev_index = prev_city[prev_index];
        s.push(prev_index);
    }
    QTextStream(stdout) << "The Optimal Path is:" << endl;
    City c;
    while(!s.isEmpty())
    {
        c = city_list.at(s.pop());
        QTextStream(stdout) << c.getName() << endl;
    }
}
