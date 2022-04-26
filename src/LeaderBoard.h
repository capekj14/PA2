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
    void addPlayerResult(const Player& player);
    void printRecords();
    void pushBackPlayer(std::pair<std::string, unsigned int> record);
    int getRecordCount();
    std::string getNameOnIndex(size_t index);
    unsigned int getScoreInIndex(size_t index);
};


#endif //SEMESTRALKA_LEADERBOARD_H
