//
// Created by Jakub Čapek on 23.04.2022.
//
#pragma once
#ifndef SEMESTRALKA_QUESTIONYESNO_H
#define SEMESTRALKA_QUESTIONYESNO_H


#include "Question.h"

class QuestionYesNo : public Question
{
    std::string correctAnswer;
    std::string playerAnswer;
public:
    void showQuestion() override;
    std::string getAnswer() override;
    bool evaluate() override;
    QuestionType getType() override;
    void createQuestion() override;
    void saveQuestion(std::ofstream&) override;
    void loadQuestion(std::ifstream&) override;
    std::shared_ptr<Question> clone() const override;
};


#endif //SEMESTRALKA_QUESTIONYESNO_H
