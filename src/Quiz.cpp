//
// Created by Jakub Čapek on 22.04.2022.
//

#include "Quiz.h"

void Quiz::run()
{
    //pro kazdou stranku a kazdou otazku proved metody
    //na konci print vysledky
}

void Quiz::printPlayerResult()
{
    std::cout << "Vaše skóre je " << player.getScore() << "/" << getQuestionCount() << "\n" << std::endl;
    LeaderBoard leaderBoard;
    leaderBoard.load();
    leaderBoard.addPlayerResult(player);
    leaderBoard.printRecords();
    leaderBoard.save();
}

size_t Quiz::getQuestionCount()
{
    size_t ret = 0;
    for(auto page : pages)
    {
        ret += page.getQuestionCount();
    }
    return ret;
}

std::string Quiz::getName()
{
    return name;
}

int Quiz::getScore()
{
    int score = 0;
    for(auto page : pages)
    {
        int pageScore = page.getScore();
        score += pageScore;
    }
    player.setScore(score);
    return score;
}

void Quiz::incrementStreak()
{
    falseStreak++;
}

int Quiz::getStreak()
{
    return falseStreak;
}
