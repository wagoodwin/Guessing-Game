#include "gamecode.h"
#include <iostream>
#include <random> // for std::mt199937 and std::random_device


// std::mt19937 mt: creates a Mersenne Twister PRNG
// std::random_device{}(): creates seed for PRNG
// use "static" so we don't reseed every time mt is called
static std::mt19937 mt{std::random_device{}()}; 

int Random::getInt(int min, int max)
{
    // creates a uniform dist of numbers between two numbers
    std::uniform_int_distribution<> d10{min, max};
    // mt picks out a number from d10, giving us our number (I think)
    return d10(mt);
}

// use Player& player (pass by ref) to ensure we're moving money around
// with the same player object. Otherwise, we'd make a copy of player and 
// the player we want wouldn't change
void playGuessingGame(Player& player) 
{

    // initialize wager and guessed number
    int wager{0};
    int guessedNumber{};

    std::cout << "You currently have " << player.showMoney() <<
    " dollars in the bank." << "\n";

    std::cout << "How much do you want to wager?" << "\n";
    std::cin >> wager;

    int randomNumber = Random::getInt(1,10);
    

    std::cout << "A random number between 1 and 10 has been generated." <<
    " What's your guess?" << "\n";

    std::cin >> guessedNumber;

    if (randomNumber == guessedNumber)
    {
        player.giveMoney(wager);
        std::cout << "You won.";
    }
    else
    {
        player.takeMoney(wager);
        std::cout << "You lost.";
    }

}


