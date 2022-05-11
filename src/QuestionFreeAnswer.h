//
// Created by Jakub Čapek on 23.04.2022.
//
#pragma once


#include <set>
#include <memory>
#include "Question.h"

/**
 * children class derived from abstract class Question
 * represents free answer question, player answers with his own words
 */
class QuestionFreeAnswer : public Question
{
    std::set<std::string> correctAnswerSet;
    std::string correctAnswer;
    std::string playerAnswer;
    std::string pattern;

public:
    void showQuestion()const override;
    std::string getAnswer() override;
    bool evaluate() override;
    /**
     * checks player answer if it contains substring "pattern"
     * @return true or false if player answer contains substring
     */
    bool checkBySubstring();
    QuestionType getType() override;
    void createQuestion() override;
    void saveQuestion(std::ofstream&)const override;
    bool loadQuestion(std::ifstream&) override;
};
