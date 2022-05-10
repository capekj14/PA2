//
// Created by Jakub Čapek on 22.04.2022.
//
#pragma once
#include <vector>
#include <string>
#include <queue>
#include <fstream>
#include "Page.h"
#include "Player.h"
#include "LeaderBoard.h"
#include "QuizMaker.h"

#ifndef SEMESTRALKA_QUIZ_H
#define SEMESTRALKA_QUIZ_H

/**
 * represents quiz, which is main class of this whole application
 */
class Quiz
{
    std::vector<Page> pages;
    Player player;
    std::string name;
    int pageCount;
public:
    /**
     * runs whole quiz
     */
    void run();

    /**
     * prints players score and writes quiz leaderBoard into console
     */
    void printPlayerResult() const;

    /**
     * @return number of question in quiz
     */
    size_t getQuestionCount() const;

    /**
     * calculate quiz score
     * @return score from quiz
     */
    int getScore();

    /**
     * pushes all pages into queue
     * @param Q std::queue of pages
     */
    void pushToQueue(std::queue<Page>& Q) const;

    /**
     * controls creating new quiz, asks for all needed information
     */
    void createQuiz();

    /**
     * opens ifstream and controls saving quiz into correct file
     */
    void saveQuiz() const;

    /**
     * controls loading quiz information from file
     * @param[in] str file name which player chose
     * @return if loading of quiz was successful
     */
    bool loadQuiz(const std::string& str);

};


#endif //SEMESTRALKA_QUIZ_H
