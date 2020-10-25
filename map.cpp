/*
Dungeon Crawler
Created by: Christopher Newton, Corbin Robinson, and Zaniken Gurule
CS 3150
Last Edited: 10/13/2020
*/
//INCLUDES
#include <iostream>
#include <vector>
#include "map.h"
using namespace std;
int moveCount = 0;

vector<vector<string>> makeMap(string sArr[], size_t arrSize)
{
    vector<vector<string>> tempMap;

    for (int i = 0; i < arrSize; i++)
    {
        vector<string> tempVec;
        string stemp;
        for (int j = 0; j < sArr[0].length(); j++)
        {
            stemp = sArr[i].at(j);
            tempVec.push_back(stemp);
        }
        tempMap.push_back(tempVec);
        tempVec.clear();
    }
    return tempMap;
}

void printMap(vector<vector<string>> s)
{
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s[i].size(); j++)
        {
            cout << s[i][j];
        }
        cout << endl;
    }
}

bool isValidMove(int newX, int newY, map m){
    if(m.mapVec[newY][newX] == "w"){
        return false;
    } else if(m.mapVec[newY][newX] == "."){
        m.hero.goldCount++;
    }
    return true;
}

void move(int newX, int newY, map* m){
    moveCount++;
    m->mapVec[newY][newX] = "S";
    m->mapVec[m->hero.yPos][m->hero.xPos] = " ";
    m->hero.xPos = newX;
    m->hero.yPos = newY;
}
