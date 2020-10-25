/*
Dungeon Crawler
Created by: Christopher Newton, Corbin Robinson, and Zaniken Gurule
CS 3150
Last Edited: 10/13/2020
*/
//INCLUDES
#include <iostream>
#include <vector>
#include <stdlib.h>
// #include <fstream>
// #include <conio.h>
#include "map.h"
#include "driver.h"
#include "hero.h"

using namespace std;

map setupInitialValues(string sArr[], int S)
{
    map theMap;
    theMap.mapVec = makeMap(sArr, S);
    for (int i = 0; i < theMap.mapVec.size(); i++)
    {
        for (int j = 0; j < theMap.mapVec[0].size(); j++)
        {
            if (theMap.mapVec[i][j] == "w")
            {
                item wall;
                wall.xPos = j;
                wall.yPos = i;
                theMap.wVec.push_back(wall);
            }
            else if (theMap.mapVec[i][j] == ".")
            {
                /*
                item gold;
                gold.xPos = j;
                gold.yPos = i;
                theMap.gVec.push_back(gold);
                */
                theMap.goldCount++;
            }
            else if (theMap.mapVec[i][j] == "S")
            {
                character hero;
                hero.xPos = j;
                hero.yPos = i;
                hero.strength = 5;
                hero.hp = 10;
                hero.goldCount = 0;
                theMap.hero = hero;
            }
            else if (theMap.mapVec[i][j] == "E")
            {
                character hero;
                hero.xPos = j;
                hero.yPos = i;
                hero.strength = 5;
                hero.hp = 10;
                hero.goldCount = 0;
                theMap.eVec.push_back(hero);
            }
        }
    }
    return theMap;
}

map chooseMap() {
    string sArr[3] = { "wwwwwwwwww", "w.      Sw", "wwwwwwwwww" };
    string mArr[11] = { "wwwwwwwwwwwwwwwwwwww", "wo...w........w....w", "w.ww.w.wwwwww.w.ww.w", "w.w..............w.w", "w.w.ww.ww  ww.ww.w.w", "w......wE  Ew......w", "w.w.ww.wwwwww.ww.w.w", "w.w..............w.w", "w.ww.w.wwwwww.w.ww.w", "w....w...S....w...ow", "wwwwwwwwwwwwwwwwwwww" };
    string lArr[45] = { "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww", "w         w               w               w w", "w w       w www           w           w   w w", "w w       w   w                       w   w w", "w wwwww www www           wwwwwww www w   w w", "w w       w w             w         w w   w w", "w w       www w           w  S      w w   w w", "w             w           w           w     w", "www       wwwww           w         w w   w w", "w         w               w           w   w w", "wwwwwwwwwww   w           w         wwwww w w", "w         w   w           w             w   w", "w         w   www wwwww w w wwwww www   w   w", "w             w   w     w   w   w w w   w   w", "w w wwwwwww   w   w     w   w   w w w   w   w", "w w       w   w   w     w   w   w   w   w   w", "w w wwwwwww   w   w     w   w   www w   w   w", "w   w         w   w     w   w   w           w", "w www     wwwww   w     w   w   wwwww wwwww w", "w   w                   w       w         w w", "www w     w w www w     w wwwwwww         w w", "w   w     w w   w w         w   w           w", "w www     w w   wwwwwww w www w w         w w", "w   w       w   w     w     w w           w w", "w www wwwwwww   w     w     w wwwwwwwwwww www", "w w       w     w           w           w   w", "w w     w w w   w     wwwww w     w     w   w", "w w     w   w   w         w w     w     w   w", "w w     w www   w     www www     w     w   w", "w w     w   w   w       w         w         w", "w wwwww www wwwwwww wwwwwwwww     w     w   w", "w w               w         w     w     w   w", "w w           w   w         w     wwwwwwwww w", "w w           w   w         w     w     w   w", "w w           www w         w     w     w   w", "w               w           w               w", "w w           w wwwwwwwww wwwww www     www w", "w w           w       w       w w       w   w", "w w           w       w       w w w     w   w", "w w           w       w       w   w         w", "w www wwwwwwwww       www wwwwwwwwwwwww www w", "w w                         w               w", "w w       w   www wwwww     w     w       www", "w w       w                       w         w", "wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"};
    //printMap(map);
    int mapC;
    int mapS;
    cout << "Please choose a map size! Type 1 for a small map, 2 for a medium map, or 3 for a large map! (full screen required for large map)" << endl;
    cin >> mapC;
    map theMap;
    if (mapC == 1) {
        mapS = 3;
        map theMap = setupInitialValues(sArr, mapS);
        return theMap;
    }
    else if (mapC == 2) {
        mapS = 11;
        map theMap = setupInitialValues(mArr, mapS);
        return theMap;
    }
    else if (mapC == 3) {
        mapS = 45;
        map theMap = setupInitialValues(lArr, mapS);
        return theMap;
    }
}

string printInfo(map theMap, int x)
{
    while (true)
    {
        system("CLS");
        printMap(theMap.mapVec);
        cout << "HP: " << theMap.hero.hp << "     Gold: " << theMap.hero.goldCount << endl;
        switch (x)
        {
        case 1:
            cout << "Input w, a, s, d, to go up, left, down, right respectively: " << endl;
            break;
        case 2:
            cout << "Invalid input, try again" << endl;
            break;
        case 3:
            cout << "Illegal move, try again" << endl;
            break;
        }
        string input;
        cin >> input;
        if (input == "w" || input == "a" || input == "s" || input == "d")
        {
            return input;
        }
        //printf("%c[2K", 27);
        x = 2;
    }
}

void convertInput(int *x, int *y, string input, map theMap)
{
    if (input == "w")
    {
        *x = theMap.hero.xPos;
        *y = theMap.hero.yPos - 1;
    }
    else if (input == "a")
    {
        *x = theMap.hero.xPos - 1;
        *y = theMap.hero.yPos;
    }
    else if (input == "s")
    {
        *x = theMap.hero.xPos;
        *y = theMap.hero.yPos + 1;
    }
    else if (input == "d")
    {
        *x = theMap.hero.xPos + 1;
        *y = theMap.hero.yPos;
    }
}

int main()
{
    map theMap = chooseMap();
    //printMap(map);
    //map theMap = setupInitialValues(sArr);
    bool wonered = false;
    while (!wonered)
    {
        string input = printInfo(theMap, 1);
        int newX, newY;
        convertInput(&newX, &newY, input, theMap);
        if (isValidMove(newX, newY, theMap))
        {
            move(newX, newY, &theMap);
        } else{
            printInfo(theMap, 3);
        }
    }

    // ifstream file;
    // file.open("textMaze.txt");
    // cout << "yo" << endl;
    // if (file.is_open())
    // {
    //     cout << "is open" << endl;
    //     string line;
    //     for (int i = 0; getline(file, line); i++)
    //     {
    //         vector<string> tempVec;
    //         string stemp;
    //         for (int j = 0; j < line.length(); j++)
    //         {
    //             stemp = line.at(j);
    //             tempVec.push_back(stemp);
    //         }
    //         s.push_back(tempVec);
    //     }
    //     for (int i = 0; i < s.size(); i++)
    //     {
    //         for (int j = 0; j < s[i].size(); j++)
    //         {
    //             cout << s[i][j];
    //         }
    //         cout << endl;
    //     }
    // }
}
