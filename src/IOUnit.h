//
// Created by Jakub Čapek on 23.04.2022.
//

#ifndef SEMESTRALKA_IOUNIT_H
#define SEMESTRALKA_IOUNIT_H


#include "Quiz.h"

class IOUnit
{
    Quiz quiz;
public:
    bool loadQuiz();
    bool saveQuiz();
};


#endif //SEMESTRALKA_IOUNIT_H
