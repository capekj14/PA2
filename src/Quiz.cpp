//
// Created by Jakub Čapek on 22.04.2022.
//

#include "Quiz.h"

void Quiz::run()
{
    int falseStreak = 0;
    std::queue<Page> pageQueue;
    pushToQueue(pageQueue);
    while(!pageQueue.empty())
    {
        auto page = pageQueue.front();
        pageQueue.pop();
        int result = page.run(falseStreak);
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
    std::cout << "Vase skore je " << player.getScore() << "/" << getQuestionCount() << "\n" << std::endl;
    LeaderBoard leaderBoard;
    leaderBoard.load(name);
    leaderBoard.addPlayerResult(player);
    leaderBoard.showLeaderBoard();
    leaderBoard.save(name);
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

void Quiz::pushToQueue(std::queue<Page>& Q)
{
    for(auto& page : pages)
        Q.push(page);
}

void Quiz::addPage(const Page& page)
{
    pages.push_back(page);
}

void Quiz::createQuiz()
{
    std::cout << "VITEJTE V ULTIMATNIM NASTROJI PRO VYTVORENI KVIZU\n";
    QuizMaker::askName(name);
    QuizMaker::askPageCount(pageCount);
    for(int i = 0; i < pageCount; i++)
    {
        Page page;
        page.createPage();
        pages.push_back(page);
    }
    saveQuiz();
    std::cout << "VAS KVIZ BYL USPESNE ULOZEN\n";
}

void Quiz::saveQuiz()
{
    std::ofstream out("../quizes/"+ name + ".txt");
    out << "\"nazev\" : << " << name << " >>" << std::endl;
    out << "\"pocet stran\" : << " << pageCount << " >>" << std::endl;
    for(auto& page : pages)
        page.savePage(out);
}

void Quiz::loadQuiz(const std::string& fileName)
{
    std::ifstream in("../quizes/"+ fileName + ".txt");
    std::string input;
    std::getline(in, input, '\n');
    char const * fakeName;
    sscanf(input.c_str(), "\"nazev\" : << %s >>", fakeName);
    name = fakeName;
    std::getline(in, input, '\n');
    char const * pageCountStr;
    sscanf(input.c_str(), "\"pocet stran\" : << %s >>", pageCountStr);
    pageCount = strtol(pageCountStr, nullptr, 10);
    for(int i = 0; i < pageCount; i++)
    {
        Page page;
        page.loadPage(in);
        pages.push_back(page);
    }

}

void Quiz::setName(const std::string & str)
{
    name = str;
}
