//
// Created by Jakub Čapek on 22.04.2022.
//

#include "Quiz.h"

void Quiz::run()
{
    Common::clearConsole();
    std::cout << "Hrajete kviz " << name << std::endl;
    player.askPlayerName();
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
        {
            Common::clearConsole();
            std::cout << "odpovedeli jste 3 po sobe spatne. Vase hra je ukoncena" << std::endl;
            break;
        }
    }
    doFakeLoadingScreen();
    Common::clearConsole();
    player.setScore(getScore());
    printPlayerResult();
}

void Quiz::printPlayerResult() const
{
    std::cout << "Vase skore je " << player.getScore() << "/" << getQuestionCount() << std::endl;
    LeaderBoard leaderBoard;
    leaderBoard.load(name);
    leaderBoard.addPlayerResult(player);
    leaderBoard.showLeaderBoard();
    leaderBoard.save(name);
}

size_t Quiz::getQuestionCount() const
{
    size_t ret = 0;
    for(const auto& page : pages)
    {
        ret += page.getQuestionCount();
    }
    return ret;
}

int Quiz::getScore()
{
    int score = 0;
    for(const auto& page : pages)
    {
        int pageScore = page.getScore();
        score += pageScore;
    }
    player.setScore(score);
    return score;
}

void Quiz::pushToQueue(std::queue<Page>& Q) const
{
    for(auto& page : pages)
        Q.push(page);
}

void Quiz::createQuiz()
{
    std::cout << "VITEJTE V ULTIMATNIM NASTROJI PRO VYTVORENI KVIZU\n";
    QuizMaker::askName(name);
    QuizMaker::askPageCount(pageCount);
    for(int i = 0; i < pageCount; i++)
    {
        Common::clearConsole();
        std::cout << "stranka " << i + 1 << "/" << pageCount << std::endl;
        Page page;
        page.createPage();
        pages.push_back(page);
        page.setPageInOrder(i);
    }
    saveQuiz();
    Common::clearConsole();
    std::cout << "VAS KVIZ BYL USPESNE ULOZEN\n";
}

void Quiz::saveQuiz() const
{
    std::ofstream out("quizes/"+ name + ".txt");
    out << "\"nazev\" : << " << name << " >>" << std::endl;
    out << "\"pocet stran\" : << " << pageCount << " >>" << std::endl;
    for(auto& page : pages)
        page.savePage(out);
}

bool Quiz::loadQuiz(const std::string& fileName)
{
    std::ifstream in("quizes/"+ fileName + ".txt");
    std::string input;

    std::getline(in, input);
    auto skippedName = Common::skip(input, "\"nazev\" : ");
    
    name = Common::extractField(skippedName);
    std::getline(in, input);
    auto skippedPageCount = Common::skip(input, "\"pocet stran\" : ");

    std::string pageCountStr = Common::extractField(skippedPageCount);
    auto [pageCount, ok] = Common::strToInt(pageCountStr.data());
    if(ok == false)
        return false;


    for(int i = 0; i < pageCount; i++)
    {
        std::cout << "stranka:" << i << std::endl;
        Page page;
        page.setPageInOrder(i);
        if(not page.loadPage(in))
            return false;
        pages.push_back(std::move(page));
    }
    return true;
}

void Quiz::doFakeLoadingScreen()
{
    Common::clearConsole();
    std::cout << "probiha hodnoceni ." << std::endl;
    Common::shortSleep();

    Common::clearConsole();
    std::cout << "probiha hodnoceni .." << std::endl;
    Common::shortSleep();

    Common::clearConsole();
    std::cout << "probiha hodnoceni ..." << std::endl;
    Common::shortSleep();

    Common::clearConsole();
    std::cout << "probiha hodnoceni ." << std::endl;
    Common::shortSleep();

    Common::clearConsole();
    std::cout << "probiha hodnoceni .." << std::endl;
    Common::shortSleep();

    Common::clearConsole();
    std::cout << "probiha hodnoceni ..." << std::endl;
    Common::shortSleep();
}