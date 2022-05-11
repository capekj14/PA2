//
// Created by Jakub Čapek on 23.04.2022.
//
#pragma once

#include <string>
#include <utility>
#include <iostream>
#include "Common.h"
/**
 * represents player of quiz
 * storing his name and score
 */
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

    /**
     * @return score from whole quiz
     */
    unsigned int getScore() const;

    /**
     * @return name of player
     */
    std::string getName() const;

    /**
     * sets class variable
     * @param num inputted number
     */
    void setScore(unsigned int num);

    /**
     * @param other another player
     * @return bool if this players score is higher than others player score (on purpose opposite behaviour)
     */
    bool operator < (const Player& other) const;

    /**
     * asks player for his names, checks loaded data
     */
    void askPlayerName();
};


