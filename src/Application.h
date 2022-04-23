//
// Created by Jakub Čapek on 22.04.2022.
//

#ifndef SEMESTRALKA_APPLICATION_H
#define SEMESTRALKA_APPLICATION_H

#include <iostream>
#include "Quiz.h"
#include "QuizMaker.h"
#include "IOUnit.h"

class Application
{
    Quiz quiz;

public:
    void run();
    bool loadQuiz();
    void createQuiz();
    void showMenu();
    int getAction();
};


#endif //SEMESTRALKA_APPLICATION_H
