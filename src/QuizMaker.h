//
// Created by Jakub Čapek on 22.04.2022.
//
#pragma once
#include <iostream>
#include <vector>
#include <set>
#include "QuestionType.h"
#include "Common.h"

/**
 * class for creating new quiz
 * asks user for quiz data
 */
class QuizMaker
{

public:
    /**
     * asks user for numbers of pages in quiz
     * @param[out] num stores inputted number
     */
    static void askPageCount(int& num);

    /**
     * asks player for quiz name
     * @param[out] str stores inputted string
     */
    static void askName(std::string& str);

    /**
     * asks user for number of question on page
     * @param[out] num stores inputted number
     */
    static void askQuestionCount(int& num);

    /**
     * asks user for question type
     * @return question type
     */
    static QuestionType askQuestionType();

    /**
     * asks user for question text
     * @param[out] str stores question text
     */
    static void askQuestionText(std::string& str);

    /**
     * asks user for all quiz options
     * @param[out] vec stores options
     */
    static void askOptions(std::vector<std::string>& vec);

    /**
     * asks for all needed data to know correct answer of question free answer
     * @param[out] correctAnswer exact correct answer
     * @param[out] patern substring which answer must contain
     * @param[out] correctSet set of all other possible answers
     */
    static void askCorrectAnswerFree(std::string &correctAnswer, std::string& patern, std::set<std::string>& correctSet);

    /**
     * asks for correct option
     * @param[out] correctAnswer correct option
     */
    static void askCorrectAnswerMulti(std::string &correctAnswer);

    /**
     * asks for correct answer
     * @param[out] correctAnswer correct answer
     */
    static void askCorrectAnswerYesNo(std::string &correctAnswer);

    /**
     * asks for correct option
     * @param[out] correctAnswer correct option
     */
    static void askCorrectAnswerSingle(std::string &correctAnswer);

};
