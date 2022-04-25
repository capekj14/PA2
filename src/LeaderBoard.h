//
// Created by Jakub Čapek on 23.04.2022.
//

#ifndef SEMESTRALKA_LEADERBOARD_H
#define SEMESTRALKA_LEADERBOARD_H


#include <string>
#include <vector>
#include <iostream>
#include "Player.h"

class LeaderBoard
{
    std::vector<std::pair<std::string, unsigned int>> records;
public:
    void load();
    void save();
    void addPlayerResult(const Player& player);
    void printRecords();
    void pushBackPlayer(std::pair<std::string, unsigned int> record);
};


#endif //SEMESTRALKA_LEADERBOARD_H
