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
/**
 * class for usefull methods that are used in many other classes
 */
struct Common
{
    /**
     * reads string from std::cin
     * @param[in,out] str for storing inputted data
     * @return bool if loading was all right
     */
    static bool getString(std::string& str);

    /**
     * reads number from std::cin
     * @param[in,out] num for storing inputted data
     * @return bool if loading was all right
     */
    static bool getNumber(int& num);

    /**
     * reads line from std::cin
     * @param[in,out] line for storing inputted data
     * @return bool if loading was all right
     */
    static bool getText(std::string& line);

    /**
     * clears std::cin for enabling another input
     */
    static void clearConsole();

    /**
     * checking parameter if contains just letters a,b,c,d each maximally once
     * @param[in] str answer from user
     * @return bool if abcd set is correct
     */
    static bool checkABCDSet(const std::string& str);

    /**
     * finds all existing quizes in directory quiz
     * @param[out] vec for storing names of existing quizes
     * @param[in] print enables printing possible quizes into console
     */
    static void findQuizes(std::vector<std::string>& vec, bool print);

    /**
     * user choose quiz name
     * @param[in] vec all existing quizes names
     * @return selected name of quiz
     */
    static std::string selectQuiz(const std::vector<std::string>& vec);

    /**
     * in creating new quiz we need unique name of quiz
     * @param[in] str inputted quiz name
     * @return if selected name is unique
     */
    static bool checkQuizName(const std::string& str);

    /**
     * clean up console for clear view
     */
    static void deleteConsole();

    /**
     * calls library function for sleep with parameter 3000 milliseconds
     */
    static void sleep();
};


#endif //SEMESTRALKA_COMMON_H
