//
// Created by Jakub Čapek on 22.04.2022.
//

#include <iostream>
#include <vector>
#include <set>
#include "QuestionType.cpp"

#ifndef SEMESTRALKA_QUIZMAKER_H
#define SEMESTRALKA_QUIZMAKER_H

//KAZDY OBJEKT UMI SAVNOUT SVOJE DATA BERE FSTREAM
//KAZDY OBJEKT SE UMI ZEPTAT NA VSECHNY DATA CO POTREBUJE Z CINU
//NA KONCU RUN SE ZAVOLA IOUNITQUIZ KTERA PRO CELY KVIZ VYPISE VSE 
class QuizMaker
{

public:
    static void askPageCount(int&);
    static void askName(std::string&);
    static void askQuestionCount(int&);
    static void askQuestionType(QuestionType&);
    static void askQuestionText(std::string&);
    static void askOptions(std::vector<std::string>&);
    static bool getString(std::string&);
    static bool getNumber(int&);
    static void askCorrectAnswerFree(std::string &correctAnswer, std::string& patern,
                                     std::set<std::string>& correctSet);
    static void askCorrectAnswerMulti(std::string &correctAnswer);
    static void askCorrectAnswerYesNo(std::string &correctAnswer);
    static void askCorrectAnswerSingle(std::string &correctAnswer);
    static bool checkABCDset(std::string&);
};


#endif //SEMESTRALKA_QUIZMAKER_H
