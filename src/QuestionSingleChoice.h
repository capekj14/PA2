//
// Created by Jakub Čapek on 23.04.2022.
//

#ifndef SEMESTRALKA_QUESTIONSINGLECHOICE_H
#define SEMESTRALKA_QUESTIONSINGLECHOICE_H


#include <vector>
#include "Question.h"

class QuestionSingleChoice : public Question
{
    std::string correctAnswer;
    std::string playerAnswer;
    std::vector<std::string> options;
public:
    void showQuestion() override;
    std::string getAnswer() override;
    bool evaluate() override;
};


#endif //SEMESTRALKA_QUESTIONSINGLECHOICE_H
