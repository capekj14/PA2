//
// Created by Jakub Čapek on 23.04.2022.
//

#ifndef SEMESTRALKA_LEADERBOARD_H
#define SEMESTRALKA_LEADERBOARD_H


#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Player.h"

class LeaderBoard
{
    std::vector<std::pair<std::string, unsigned int>> records;
public:
    void addPlayerResult(const Player& player);
    void showLeaderBoard();
    void pushBackPlayer(const std::pair<std::string, unsigned int>& record);
    std::string getNameOnIndex(size_t index);
    unsigned int getScoreInIndex(size_t index);
    void save(const std::string&);
    void load(const std::string&);
};


#endif //SEMESTRALKA_LEADERBOARD_H
