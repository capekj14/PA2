//
// Created by Jakub Čapek on 23.04.2022.
//
#pragma once
#ifndef SEMESTRALKA_LEADERBOARD_H
#define SEMESTRALKA_LEADERBOARD_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "Player.h"
#include <iomanip>

/**
 * represents leaderBoard of concrete quiz
 */
class LeaderBoard
{
    std::vector<Player> records;
public:
    /**
     * inserts player into vector of records
     * @param[in] player inputted player
     */
    void addPlayerResult(const Player& player);

    /**
     * print all players in records into console
     */
    void showLeaderBoard() const;

    /**
     * pushbacks player into vector of records
     * @param[in] player inputted player
     */
    void pushBackPlayer(const Player& player);

    /**
     * @param[in] index in vector
     * @return name of player on index in vector of records
     */
    std::string getNameOnIndex(size_t index) const;

    /**
     * @param index in vector
     * @return score of player on index in vector of records
     */
    unsigned int getScoreInIndex(size_t index) const;

    /**
     * opens output file stream and writes all records into it
     * @param[in] str quizname for constructor of ofstream
     */
    void save(const std::string& str) const;

    /**
     * opens input file stream and load all records from it
     * @param[in] str quizname for constructor of ifstream
     */
    void load(const std::string& str);
};


#endif //SEMESTRALKA_LEADERBOARD_H
