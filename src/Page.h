//
// Created by Jakub Čapek on 22.04.2022.
//
#include <vector>
#include <memory>
#include "Question.h"
#include <iostream>

#ifndef SEMESTRALKA_PAGE_H
#define SEMESTRALKA_PAGE_H

class Page
{
    std::vector<std::shared_ptr<Question>> questions;
    bool isAnswered = false;
public:
    void showPage();
    size_t getQuestionCount();
    int getScore();
};


#endif //SEMESTRALKA_PAGE_H
