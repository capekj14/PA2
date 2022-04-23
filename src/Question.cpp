//
// Created by Jakub Čapek on 22.04.2022.
//

#include "Question.h"


void Question::run()
{
    showQuestion();
    getAnswer();
    evaluate();
}

bool Question::getCorrectlyAnswered()
{
    return correctlyAnswered;
}
