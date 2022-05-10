//
// Created by Jakub Čapek on 23.04.2022.
//
#pragma once
#ifndef SEMESTRALKA_QUESTIONSINGLECHOICE_H
#define SEMESTRALKA_QUESTIONSINGLECHOICE_H


#include <vector>
#include "Question.h"

/**
 * derived class from Question
 * represents single choice question player can choose only one option
 */
class QuestionSingleChoice : public Question
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
    void saveQuestion(std::ofstream&) const override;
    bool loadQuestion(std::ifstream&) override;
    std::shared_ptr<Question> clone() const override;
};


#endif //SEMESTRALKA_QUESTIONSINGLECHOICE_H
