//
// Created by Jakub Čapek on 23.04.2022.
//

#include "Player.h"

unsigned int Player::getScore() const
{
    return score;
}

std::string Player::getName()
{
    return name;
}

void Player::setScore(unsigned int num)
{
    score = num;
}
