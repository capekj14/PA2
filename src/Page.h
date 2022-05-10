//
// Created by Jakub Čapek on 22.04.2022.
//
#pragma once
#include <vector>
#include <memory>
#include <iostream>
#include <fstream>
#include "Question.h"
#include "QuestionFreeAnswer.h"
#include "QuestionMultiChoice.h"
#include "QuestionSingleChoice.h"
#include "QuestionYesNo.h"
#include "QuizMaker.h"
#include "Common.h"

/**
 * represents one page in quiz
 * page can contains more questions
 */
class Page
{
    std::vector<std::shared_ptr<Question>> questions;
    int questionCount = 0;
    size_t pageInOrder;

    void addPage(QuestionType type);

public:
    /**
     * print whole page into console
     */
    void showPage() const;

    /**
     * @return number of questions on page
     */

    size_t getQuestionCount() const;

    /**
     * @return score from page
     */
    int getScore() const;

    /**
     * runs whole page
     * @param falseStreak number of consecutive false answers
     * @return state in which page ended
     */
    int run(int& falseStreak);

    /**
     * is used in quiz making process, controls flow of making new page
     */
    void createPage();

    /**
     * writes all data into out
     * @param[in] out inputted ofstream
     */
    void savePage(std::ofstream& out) const;

    /**
     * loads all data from in
     * @param[in] in inputted ifstream
     * @return bool if loading was all right
     */
    bool loadPage(std::ifstream& in);

    /**
     * sets class variable
     * @param[in] num inputted number
     */
    void setPageInOrder(size_t num);
};


