//
// Created by Jakub Čapek on 22.04.2022.
//
#pragma once
#ifndef SEMESTRALKA_APPLICATION_H
#define SEMESTRALKA_APPLICATION_H

#include <iostream>
#include "Quiz.h"
#include "QuizMaker.h"
#include <filesystem>
#include "Common.h"
class Application
{
    Quiz quiz;

public:
    void run();
    void showMenu();
    int getAction();
    std::string findSelectQuizes();
};


#endif //SEMESTRALKA_APPLICATION_H
