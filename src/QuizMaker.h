//
// Created by Jakub Čapek on 22.04.2022.
//

#include <iostream>
#include <vector>
#include <set>
#include "Page.h"
#include "Quiz.h"

#ifndef SEMESTRALKA_QUIZMAKER_H
#define SEMESTRALKA_QUIZMAKER_H


class QuizMaker
{
    Quiz quiz;
    //QUIZFORMAT
public:
    void run();
    void askPageCount(int&);
    void askName(std::string&);
    void askQuestionCount(int&);
    void askQuestionType(QuestionType&);
    void askQuestionText(std::string&);
    void askCorrectAnswer(QuestionType& type, std::string&);
    void askOptions(QuestionType& type, std::vector<std::string>&);
    bool getString(std::string&);
    bool getNumber(int&);

    void askCorrectAnswer(QuestionType &type, std::string &correctAnswer, std::string& patern,
                          std::set<std::string>& correctSet);

    bool checkABCDset(std::string&);
};


#endif //SEMESTRALKA_QUIZMAKER_H
