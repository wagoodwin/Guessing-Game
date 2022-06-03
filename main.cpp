#include "player.h"
#include "gamecode.h"
#include <iostream>


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