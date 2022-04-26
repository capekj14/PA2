//
// Created by Jakub Čapek on 22.04.2022.
//

#ifndef SEMESTRALKA_QUESTION_H
#define SEMESTRALKA_QUESTION_H


#include <string>
#include <iostream>
#include "QuestionType.cpp"
class Question
{
protected:
    bool correctlyAnswered = false;
    bool answered = false;
    std::string text;

public:
    virtual void showQuestion() = 0;
    virtual std::string getAnswer() = 0;
    virtual bool evaluate() = 0;
    bool run();
    bool getCorrectlyAnswered() const;
    virtual QuestionType getType() = 0;
};


#endif //SEMESTRALKA_QUESTION_H
