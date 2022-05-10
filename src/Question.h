//
// Created by Jakub Čapek on 22.04.2022.
//
#pragma once
#ifndef SEMESTRALKA_QUESTION_H
#define SEMESTRALKA_QUESTION_H


#include <string>
#include <iostream>
#include <fstream>
#include "QuestionType.h"
#include "QuizMaker.h"
#include "Common.h"
#include <memory>

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
    virtual void createQuestion() = 0;
    virtual void saveQuestion(std::ofstream&) = 0;
    virtual bool loadQuestion(std::ifstream&) = 0;
    virtual std::shared_ptr<Question> clone() const = 0;
};


#endif //SEMESTRALKA_QUESTION_H
