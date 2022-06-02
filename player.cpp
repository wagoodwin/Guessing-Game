#include "player.h"


void Player::giveMoney(int amount)
{
    m_money = m_money + amount;
}
void Player::takeMoney(int amount)
{
    m_money = m_money - amount;
}
int Player::showMoney() const
{
    return m_money;
}