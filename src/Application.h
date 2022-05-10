//
// Created by Jakub Čapek on 22.04.2022.
//
#pragma once

#include <iostream>
#include "Quiz.h"
#include "QuizMaker.h"
#include <filesystem>
#include "Common.h"
/**
 * represents whole application
 */
class Application
{
    Quiz quiz;

public:
    /**
     * runs whole program
     * controls loading or creating quiz
     */
    void run();
    /**
     * shows menu options
     */
    void showMenu() const;
    /**
     * choses from menu options
     * @return number which represents players action
     */
    int getAction();
};