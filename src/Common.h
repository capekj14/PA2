//
// Created by Jakub Čapek on 02.05.2022.
//
#pragma once
#ifndef SEMESTRALKA_COMMON_H
#define SEMESTRALKA_COMMON_H

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <filesystem>


struct Common
{
    static bool getString(std::string&);
    static bool getNumber(int&);
    static bool getText(std::string&);
    static void clearConsole();
    static bool checkABCDSet(std::string&);
    static void findQuizes(std::vector<std::string>&);
    static std::string selectQuiz(const std::vector<std::string>&);
    static bool checkQuizName(const std::string &);
};


#endif //SEMESTRALKA_COMMON_H
