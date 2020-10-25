
#ifndef MAP_H
#define MAP_H

#include <vector>
#include <string>
#include "hero.h"
using namespace std;

extern int moveCount;
vector<vector<string>> makeMap(string[], size_t);
void printMap(vector<vector<string>>);

struct map{
    int goldCount = 0;
    vector<character> eVec;
    character hero;
    vector<item> wVec;
    vector<vector<string>> mapVec;
};

bool isValidMove(int, int, map);
void move(int, int, map*);


#endif