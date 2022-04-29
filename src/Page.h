//
// Created by Jakub Čapek on 22.04.2022.
//
#pragma once
#include <vector>
#include <memory>
#include "Question.h"
#include "QuestionFreeAnswer.h"
#include "QuestionMultiChoice.h"
#include "QuestionSingleChoice.h"
#include "QuestionYesNo.h"
#include <iostream>
#include <fstream>
#include "QuizMaker.h"

#ifndef SEMESTRALKA_PAGE_H
#define SEMESTRALKA_PAGE_H

class Page
{
    std::vector<std::shared_ptr<Question>> questions;
    bool isAnswered = false;
    int questionCount;
public:
    void showPage();
    size_t getQuestionCount();
    int getScore();
    void setIsAnswered(bool b);
    void addQuestion(const std::shared_ptr<Question>&);
    int run(int& falseStreak);
    void createPage();
    void savePage(std::ofstream &);
    void loadPage(std::ifstream &);
};


#endif //SEMESTRALKA_PAGE_H
