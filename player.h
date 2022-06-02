#ifndef PLAYER_H
#define PLAYER_H


class Player
{
private:
    int m_wager{};
    int m_money{};
    int guessedNumber{};
public:
    void giveMoney(int amount);
    void takeMoney(int amount);
    int showMoney() const;
};


#endif