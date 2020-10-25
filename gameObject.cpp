/*
Dungeon Crawler
Created by: Christopher Newton, Corbin Robinson, and Zaniken Gurule
CS 3150
Last Edited: 10/13/2020
*/
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include "gameObject.h"
#include "map.h"
#include "driver.h"

using namespace std;

STATUS statusCheck(character c)
{
    if (c.hp > 0)
        return alive;
    else
        return dead;
}

