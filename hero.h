/*
Dungeon Crawler
Created by: Christopher Newton, Corbin Robinson, and Zaniken Gurule
CS 3150
Last Edited: 10/13/2020
*/
#pragma once
#ifndef HERO_H
#define HERO_H

//static string hero;
//static int hmove;
// static int movehold;
// int moveHero();

struct item{
    int xPos;
    int yPos;
};

struct character{
    int hp;
    int strength;
    int xPos;
    int yPos;
    int goldCount = 0;
};

#endif
