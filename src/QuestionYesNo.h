//
// Created by Jakub Čapek on 23.04.2022.
//
#pragma once

#include "Question.h"

/**
 * derived class from Question
 * represents yes no question, player can choose from answers "yes" and "no"
 */
class QuestionYesNo : public Question
{
    std::string correctAnswer;
    std::string playerAnswer;
public:
    void showQuestion() const override;
    std::string getAnswer() override;
    bool evaluate() override;
    QuestionType getType() override;
    void createQuestion() override;
    void saveQuestion(std::ofstream&) const override;
    bool loadQuestion(std::ifstream&) override;
};
