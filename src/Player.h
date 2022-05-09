//
// Created by Jakub Čapek on 23.04.2022.
//
#pragma once
#ifndef SEMESTRALKA_PLAYER_H
#define SEMESTRALKA_PLAYER_H


#include <string>
#include <utility>
#include <iostream>
#include "Common.h"

class Player
{
    std::string name;
    unsigned int score;
public:
    Player()
    {
        name = "";
        score = 0;
    }
    explicit Player(std::string str)
        :name(std::move(str)), score(0){};
    Player(std::string str, unsigned int num)
        :name(std::move(str)), score(num){};

    unsigned int getScore() const;
    std::string getName() const;
    void setScore(unsigned int num);
    bool operator < (const Player& other);
    void askPlayerName();
};


#endif //SEMESTRALKA_PLAYER_H
