/*
Dungeon Crawler
Created by: Christopher Newton, Corbin Robinson, and Zaniken Gurule
CS 3150
Last Edited: 10/13/2020
*/

/*
    ENUM: We used an ENUM within the character struct to track alive or dead. It's the break condition for the main while
    loop running the game.
    Extern: We have a an int extern moveCount within map that keeps track of the number of moves taken by the player.
    Structs: We have multiple different structs within gameObject and map.
    Random Number Generator: We assign traps random damage values between 1-3 using "trap.dmg = rand() % 3 + 1".
*/
//INCLUDES
#include <iostream>
#include <vector>
#include <stdlib.h>
// #include <fstream>
// #include <conio.h>
#include "map.h"
#include "driver.h"
#include "gameObject.h"

using namespace std;

map setupInitialValues(string sArr[])
{
    map theMap;
    theMap.mapVec = makeMap(sArr, 3);
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
                hero.status = alive;
                theMap.hero = hero;
            }
            else if (theMap.mapVec[i][j] == "x")
            {
                item trap;
                trap.xPos = j;
                trap.yPos = i;
                trap.dmg = rand() % 3 + 1;
                theMap.tVec.push_back(trap);
            }
        }
    }
    return theMap;
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
            cout << "Input v to end the game or w, a, s, d, to go up, left, down, right respectively: " << endl;
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
        if (input == "w" || input == "a" || input == "s" || input == "d" || input == "v")
        {
            return input;
        }
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
    string sArr[3] = {"wwwwwwwwww", "w.x     Sw", "wwwwwwwwww"};
    //printMap(map);
    map theMap = setupInitialValues(sArr);
    //bool wonered = false;
    while (theMap.hero.status == alive)
    {
        string input = printInfo(theMap, 1);
        if (input == "v")
        {
            endScreen(&theMap);
        }
        int newX, newY;
        convertInput(&newX, &newY, input, theMap);
        if (isValidMove(newX, newY, &theMap))
        {
            move(newX, newY, &theMap);
        }
        else
        {
            printInfo(theMap, 3);
        }
    }
    system("CLS");
    cout << R"(
__/\\\________/\\\_______/\\\\\_______/\\\________/\\\____________/\\\\\\\\\\\\_____/\\\\\\\\\\\__/\\\\\\\\\\\\\\\__/\\\\\\\\\\\\____        
 _\///\\\____/\\\/______/\\\///\\\____\/\\\_______\/\\\___________\/\\\////////\\\__\/////\\\///__\/\\\///////////__\/\\\////////\\\__       
  ___\///\\\/\\\/______/\\\/__\///\\\__\/\\\_______\/\\\___________\/\\\______\//\\\_____\/\\\_____\/\\\_____________\/\\\______\//\\\_      
   _____\///\\\/_______/\\\______\//\\\_\/\\\_______\/\\\___________\/\\\_______\/\\\_____\/\\\_____\/\\\\\\\\\\\_____\/\\\_______\/\\\_     
    _______\/\\\_______\/\\\_______\/\\\_\/\\\_______\/\\\___________\/\\\_______\/\\\_____\/\\\_____\/\\\///////______\/\\\_______\/\\\_    
     _______\/\\\_______\//\\\______/\\\__\/\\\_______\/\\\___________\/\\\_______\/\\\_____\/\\\_____\/\\\_____________\/\\\_______\/\\\_   
      _______\/\\\________\///\\\__/\\\____\//\\\______/\\\____________\/\\\_______/\\\______\/\\\_____\/\\\_____________\/\\\_______/\\\__  
       _______\/\\\__________\///\\\\\/______\///\\\\\\\\\/_____________\/\\\\\\\\\\\\/____/\\\\\\\\\\\_\/\\\\\\\\\\\\\\\_\/\\\\\\\\\\\\/___ 
        _______\///_____________\/////__________\/////////_______________\////////////_____\///////////__\///////////////__\////////////_____
    )" << endl;


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
