//
// Created by Jakub Čapek on 23.04.2022.
//

#ifndef SEMESTRALKA_QUESTIONYESNO_H
#define SEMESTRALKA_QUESTIONYESNO_H


#include "Question.h"

class QuestionYesNo : public Question
{
    std::string correctAnswer;
    std::string playerAnswer;
public:
    void showQuestion() override;
    std::string getAnswer() override;
    bool evaluate() override;
    QuestionType getType() override;
    void createQuestion() override;
};


#endif //SEMESTRALKA_QUESTIONYESNO_H
