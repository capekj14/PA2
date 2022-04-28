//
// Created by Jakub Čapek on 22.04.2022.
//
#include <vector>
#include <string>
#include <queue>
#include "Page.h"
#include "Player.h"
#include "LeaderBoard.h"
#include "QuizMaker.h"

#ifndef SEMESTRALKA_QUIZ_H
#define SEMESTRALKA_QUIZ_H



class Quiz
{
    std::vector<Page> pages;
    Player player;
    std::string name;
    int pageCount;
public:
    void run();
    void printPlayerResult();
    size_t getQuestionCount();
    std::string getName();
    void setName(const std::string&);
    int getScore();
    void pushToQueue(std::queue<Page>& Q);
    void addPage(const Page&);
    void createQuiz();
    void saveQuiz();
    void loadQuiz();

};


#endif //SEMESTRALKA_QUIZ_H
