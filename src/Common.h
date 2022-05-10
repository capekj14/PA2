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
#include <algorithm>
#include <chrono>
#include <thread>

struct Common
{
    static bool getString(std::string&);
    static bool getNumber(int&);
    static bool getText(std::string&);
    static void clearConsole();
    static bool checkABCDSet(std::string&);
    static void findQuizes(std::vector<std::string>&, bool print);
    static std::string selectQuiz(std::vector<std::string>&);
    static bool checkQuizName(const std::string &);
    static void deleteConsole();
    static void sleep();
};


#endif //SEMESTRALKA_COMMON_H
