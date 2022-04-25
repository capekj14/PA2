//
// Created by Jakub Čapek on 22.04.2022.
//
#include <vector>
#include <string>
#include <queue>
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
public:
    void run();
    void printPlayerResult();
    size_t getQuestionCount();
    std::string getName();
    int getScore();
    void pushToQueue(std::queue<Page>& Q);

};


#endif //SEMESTRALKA_QUIZ_H
