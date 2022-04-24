//
// Created by Jakub Čapek on 22.04.2022.
//
#include <vector>
#include <string>
#include "Page.h"
#include "Player.h"
#include "LeaderBoard.h"

#ifndef SEMESTRALKA_QUIZ_H
#define SEMESTRALKA_QUIZ_H


class Quiz
{
    std::vector<Page> pages;
    Player player;
    std::string name;
    int falseStreak = 0;
public:
    void run();
    void printPlayerResult();
    size_t getQuestionCount();
    std::string getName();
    int getScore();
    void incrementStreak();
    int getStreak();

};


#endif //SEMESTRALKA_QUIZ_H
