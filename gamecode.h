#ifndef GAMECODE_H
#define GAMECODE_H

#include "player.h"
#include <iostream>
#include <random> // for std::mt199937 and std::random_device



namespace Random
{
    int getInt(int min, int max);

}

void playGuessingGame(Player& player);


#endif