//
// Created by Jakub Čapek on 22.04.2022.
//

#include <iostream>
#include <vector>
#include "Page.h"
#include "Quiz.h"

#ifndef SEMESTRALKA_QUIZMAKER_H
#define SEMESTRALKA_QUIZMAKER_H


class QuizMaker
{
    Quiz quiz;
public:
    void run();
    void askPageCount();
    void askName();
    void askQuestionCount();
    void askQuestionType();
    void askQuestionText();
    void askCorrectAnswer(int type);
    void askOptions(int type);
    std::string getString();
    int getNumber();
};


#endif //SEMESTRALKA_QUIZMAKER_H
