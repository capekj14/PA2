//
// Created by Jakub Čapek on 23.04.2022.
//

#include "Player.h"

unsigned int Player::getScore() const
{
    return score;
}

std::string Player::getName() const
{
    return name;
}

void Player::setScore(unsigned int num)
{
    score = num;
}

bool Player::operator<(const Player &other)
{
    return score > other.score;
}

void Player::askPlayerName()
{
    std::cout << "Zadejte vas nickname (nejvice 19 znaku, bez mezer): " << std::endl;
    while (true)
    {
        if(Common::getString(name) and !name.empty() and name.size() <= 19)
            break;
        std::cout << "Zadejte jmeno znovu!\n";
    }
}
