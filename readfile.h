#ifndef READFILE_H
#define READFILE_H

/* This file contains the functions for
 *extracting information from input files
 */

#include <QString>

void read_coordinate(QString filename = "locsamp.txt");
void read_connection(QString filename = "connsamp.txt");
int find_city(QString);

#endif // READFILE_H
