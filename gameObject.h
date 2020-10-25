/*
Dungeon Crawler
Created by: Christopher Newton, Corbin Robinson, and Zaniken Gurule
CS 3150
Last Edited: 10/13/2020
*/
#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

//static string hero;
//static int hmove;
// static int movehold;
// int moveHero();

enum STATUS{alive, dead};

struct item{
    int xPos;
    int yPos;
    int dmg = 0;
};

struct character{
    STATUS status;
    int hp;
    int strength;
    int xPos;
    int yPos;
    int goldCount = 0;
};

STATUS statusCheck(character c);

#endif
