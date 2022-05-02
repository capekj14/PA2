//
// Created by Jakub Čapek on 22.04.2022.
//
#pragma once
#include <iostream>
#include <vector>
#include <set>
#include "QuestionType.h"
#include "Common.h"

#ifndef SEMESTRALKA_QUIZMAKER_H
#define SEMESTRALKA_QUIZMAKER_H

class QuizMaker
{

public:
    static void askPageCount(int&);
    static void askName(std::string&);
    static void askQuestionCount(int&);
    static void askQuestionType(QuestionType&);
    static void askQuestionText(std::string&);
    static void askOptions(std::vector<std::string>&);
    static void askCorrectAnswerFree(std::string &correctAnswer, std::string& patern, std::set<std::string>& correctSet);
    static void askCorrectAnswerMulti(std::string &correctAnswer);
    static void askCorrectAnswerYesNo(std::string &correctAnswer);
    static void askCorrectAnswerSingle(std::string &correctAnswer);

};


#endif //SEMESTRALKA_QUIZMAKER_H
