//
// Created by Jakub Čapek on 23.04.2022.
//
#pragma once
#ifndef SEMESTRALKA_QUESTIONFREEANSWER_H
#define SEMESTRALKA_QUESTIONFREEANSWER_H


#include <set>
#include <memory>
#include "Question.h"

class QuestionFreeAnswer : public Question
{
    std::set<std::string> correctAnswerSet;
    std::string correctAnswer;
    std::string playerAnswer;
    std::string pattern;
public:
    void showQuestion() override;
    std::string getAnswer() override;
    bool evaluate() override;
    bool checkBySubstring();
    QuestionType getType() override;
    void createQuestion() override;
    void saveQuestion(std::ofstream&) override;
    bool loadQuestion(std::ifstream&) override;
    std::shared_ptr<Question> clone() const override;};


#endif //SEMESTRALKA_QUESTIONFREEANSWER_H
