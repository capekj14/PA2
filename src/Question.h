//
// Created by Jakub Čapek on 22.04.2022.
//
#pragma once
#ifndef SEMESTRALKA_QUESTION_H
#define SEMESTRALKA_QUESTION_H


#include <string>
#include <iostream>
#include <fstream>
#include "QuestionType.h"
#include "QuizMaker.h"
#include "Common.h"
#include <memory>

/**
 * abtract class of question from which derive four children classes
 */
class Question
{
protected:
    bool correctlyAnswered = false;
    std::string text;

public:
    /**
     * displays question into console
     */
    virtual void showQuestion() const = 0;

    /**
     * loads player answer
     * @return player answer
     */
    virtual std::string getAnswer() = 0;

    /**
     * evalute if question was answered right
     * @return bool if question was answered right
     */
    virtual bool evaluate() = 0;

    /**
     * runs question, gets player answer and evaluates
     * @return bool if question was answered right
     */
    bool run();

    /**
     * class variable getter
     * @return bool
     */
    bool getCorrectlyAnswered() const;

    /**
     * @return question type of question
     */
    virtual QuestionType getType() = 0;

    /**
     * called in quiz making process, controls flow of making new question
     */
    virtual void createQuestion() = 0;

    /**
     * writes all data into out
     * @param[in] out ofstream
     */
    virtual void saveQuestion(std::ofstream& out) const = 0;

    /**
     * loads all data from ifstream in
     * @param in ifstream
     * @return bool if loading was successful
     */
    virtual bool loadQuestion(std::ifstream& in) = 0;
};


#endif //SEMESTRALKA_QUESTION_H
