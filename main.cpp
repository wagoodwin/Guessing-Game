#include <iostream>
#include <cassert> // for assert()
#include <random> // for std::mt199937


class Player
{
private:
    int m_wager{};
    int m_money{};
    int guessedNumber{};
public:
    void giveMoney(int amount)
    {
        m_money = m_money + amount;
    }
    void takeMoney(int amount)
    {
        m_money = m_money - amount;
    }
    int showMoney() const
    {
        return m_money;
    }
};

int generateNumber()
{
    return 5; // we'll do the random number stuff later
}


void playGuessingGame(Player& player) // will make bool type later
{


    // initialize wager and guessed number
    int wager{0};
    int guessedNumber{};

    std::cout << "You currently have " << player.showMoney() <<
    " dollars in the bank." << "\n";

    std::cout << "How much do you wanna wager?" << "\n";
    std::cin >> wager;

    int randomNumber = generateNumber();

    std::cout << "A random number between 1 and 10 has been generated." <<
    " What's your guess?" << "\n";

    std::cin >> guessedNumber;

    if (randomNumber == guessedNumber)
    {
        player.giveMoney(wager);
    }
    else
    {
        player.takeMoney(wager);
    }




    // player.giveMoney(wager);

    // std::cout << "Your account now has " << player.showMoney() << 
    // " dollars." << "\n";











}



int main()
{
    // create player object and give them some money
    Player player{};
    player.giveMoney(1000);

    // game loop:
    while(player.showMoney() >= 0)
    {
        playGuessingGame(player);
    }





    return 0;
}