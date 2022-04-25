//
// Created by Jakub Čapek on 22.04.2022.
//

#include "Question.h"


bool Question::run()
{
    getAnswer();
    return evaluate();
}

bool Question::getCorrectlyAnswered() const
{
    return correctlyAnswered;
}
