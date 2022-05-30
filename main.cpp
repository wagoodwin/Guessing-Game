#include <iostream>
#include <cassert> // for assert()
#include <random> // for std::mt199937 and std::random_device

namespace Random
{
    // std::mt19937 mt: creates a Mersenne Twister PRNG
    // std::random_device{}(): creates seed for PRNG
    std::mt19937 mt{std::random_device{}()};

    int getInt(int min, int max)
    {
        // creates a uniform dist of numbers between two numbers
        std::uniform_int_distribution<> d10{min, max};
        // mt picks out a number from d10, giving us our number (I think)
        return d10(mt);
    }

}



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

    std::cout << "You've bankrupted yourself. You currently owe "
    << -player.showMoney() << " dollars. "
    << "You are sentenced to manual labor as repayment." << "\n";

    return 0;
}