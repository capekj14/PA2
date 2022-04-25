//
// Created by Jakub Čapek on 22.04.2022.
//

#include "Quiz.h"
#include "IOUnitLeaderBoard.h"

void Quiz::run()
{
    int falseStreak = 0;
    std::queue<Page> pageQueue;
    pushToQueue(pageQueue);
    while(!pageQueue.empty())
    {
        auto& page = pageQueue.front();
        pageQueue.pop();
        int result = page.run(falseStreak);//odpovezena dobre, spatne, skip
        if(result == 2)
            pageQueue.push(page);
        else if(result == 1)
            break;
        else if(result == 0)
        {
            page.setIsAnswered(true);
        }
    }
    getScore();
    printPlayerResult();
}

void Quiz::printPlayerResult()
{
    std::cout << "Vaše skóre je " << player.getScore() << "/" << getQuestionCount() << "\n" << std::endl;
    IOUnitLeaderBoard ioboard;
    ioboard.load(name);
    ioboard.leaderBoard.addPlayerResult(player);
    ioboard.leaderBoard.printRecords();
    ioboard.leaderBoard.save();
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

void Quiz::pushToQueue(std::queue<Page> &Q)
{
    for(auto& page : pages)
        Q.push(page);
}

