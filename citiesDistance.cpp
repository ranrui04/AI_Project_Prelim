#include <iostream>
#include <cmath>
#include "city.h"

using namespace std;

char point_p,point_q,selected_point,decision_point[4],goal_point,;
int x1,x2,y1,y2,numPotenPath;
double distance;

void StraLineCalculate()
{
    scanf("%c,&selected_point");
    scanf("%c,&goal_point");

    while(selected_point==str.at(0))
    {
        numPotenPath=Connstr.at(1).toInt();

        for(int i=0;i<numPotenPath,i++;)
        {
            decision_point-> connection();
        }

    }

    while(goal_point=str.at(0))
    {
        x2=str.at(1).toInt();
        y2=str.at(2).toInt();
        point_q=goal_point;
    }


    while(decision_point=setName())
    {
        x1=str.at(1).toInt();
        y1=str.at(2).toInt();

        point_p=select_point;

    }

    for(int i=0; i<numPotenPath,i++;)
    {
        distance = sqrt((x2-x1)^2+(y2-y1)^2);
    }

}


