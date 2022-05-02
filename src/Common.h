//
// Created by notebookHP on 02.05.2022.
//
#pragma once
#ifndef SEMESTRALKA_COMMON_H
#define SEMESTRALKA_COMMON_H

#include <iostream>
#include <string>
#include <limits>

class Common
{
public:
    static bool getString(std::string&);
    static bool getNumber(int&);
    static bool getText(std::string&);
    static void clearConsole();
    static bool checkABCDset(std::string&);
};


#endif //SEMESTRALKA_COMMON_H
