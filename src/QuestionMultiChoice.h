//
// Created by Jakub Čapek on 23.04.2022.
//
#pragma once
#ifndef SEMESTRALKA_QUESTIONMULTICHOICE_H
#define SEMESTRALKA_QUESTIONMULTICHOICE_H

#include <vector>
#include "Question.h"
#include <set>

class QuestionMultiChoice : public Question
{
    std::string correctAnswer;
    std::string playerAnswer;
    std::vector<std::string> options;
public:
    void showQuestion() override;
    std::string getAnswer() override;
    bool evaluate() override;
    QuestionType getType() override;
    void createQuestion() override;
};


#endif //SEMESTRALKA_QUESTIONMULTICHOICE_H
