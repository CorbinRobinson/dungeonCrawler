/*
Dungeon Crawler
Created by: Christopher Newton, Corbin Robinson, and Zaniken Gurule
CS 3150
Last Edited: 10/13/2020
*/
//INCLUDES
#ifndef DRIVER_H
#define DRIVER_H

#include "map.h"
#include "gameObject.h"
#include <vector>

//enum DIRECTION {w,a,s,d};

map setupInitialValues(string[], int);
void convertInput(int*, int*, string, map);
string printInfo(map, int);

#endif