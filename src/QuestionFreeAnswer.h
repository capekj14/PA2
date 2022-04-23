//
// Created by Jakub Čapek on 23.04.2022.
//

#ifndef SEMESTRALKA_QUESTIONFREEANSWER_H
#define SEMESTRALKA_QUESTIONFREEANSWER_H


#include <set>
#include "Question.h"

class QuestionFreeAnswer : public Question
{
    std::set<std::string> correctAnswerSet;
    std::string correctAnswer;
    std::string playerAnswer;
    std::string correctPattern;
public:
    void showQuestion() override;
    std::string getAnswer() override;
    bool evaluate() override;
    bool checkByRegex(const std::string& str);
};


#endif //SEMESTRALKA_QUESTIONFREEANSWER_H