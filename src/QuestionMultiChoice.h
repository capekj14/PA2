//
// Created by Jakub Čapek on 23.04.2022.
//
#pragma once

#include "Question.h"
#include <set>

/**
 * class derived from Question
 * represents multi choice question, player can choose from multiple options
 */
class QuestionMultiChoice : public Question
{
    std::string correctAnswer;
    std::string playerAnswer;
    std::vector<std::string> options;
public:
    void showQuestion() const override;
    std::string getAnswer() override;
    bool evaluate() override;
    QuestionType getType() override;
    void createQuestion() override;
    void saveQuestion(std::ofstream &) const override;
    bool loadQuestion(std::ifstream &) override;
};
