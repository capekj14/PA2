//
// Created by Jakub Čapek on 02.05.2022.
//

#include "Common.h"

bool Common::getString(std::string& str)
{
    std::cin >> str;
    clearConsole();
    return true;
}

bool Common::getNumber(int& num)
{
    std::cin >> num;
    clearConsole();
    return true;
}

bool Common::getText(std::string& text)
{
    std::getline(std::cin, text, '\n');
    std::cin.clear();
    return true;
}

void Common::clearConsole()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

bool Common::checkABCDSet(const std::string& str)
{
    int counts[] = {0,0,0,0};
    if(str.size() >= 4 or str.empty())
        return false;
    for(auto c : str)
    {
        if(c != 'a' and c != 'b' and c != 'c' and c != 'd')
            return false;
        switch(c)
        {
            case 'a': counts[0]++; break;
            case 'b': counts[1]++; break;
            case 'c': counts[2]++; break;
            case 'd': counts[3]++; break;
        }
    }
    for(int count : counts)
        if(count > 1)
            return false;
    return true;
}

void Common::findQuizes(std::vector<std::string>& availableQuizes, bool print)
{
    for(const auto& item : std::filesystem::directory_iterator{"quizes"})
    {
        std::string str = item.operator const std::filesystem::path &().filename().string();
        std::string adding(str.data(), str.size() - 4);
        availableQuizes.push_back(adding);
        if(print)
            std::cout << " - " << adding << std::endl;
    }
}

std::string Common::selectQuiz(const std::vector<std::string>& availableQuizes)
{
    std::string name;
    while (true)
    {
        Common::getString(name);
        if(std::find(availableQuizes.begin(), availableQuizes.end(), name) == availableQuizes.end())
        {
            std::cout << "nevybrali jste zadny dostupny kviz\n";
        }
        else
            break;
    }
    return name;
}

bool Common::checkQuizName(const std::string& name)
{
    std::vector<std::string> availableQuizes;
    Common::findQuizes(availableQuizes, false);
    for(auto& quiz : availableQuizes)
        if(quiz == name)
            return false;
    return true;
}

void Common::deleteConsole()
{
    std::cout << "\x1B[2J\x1B[H";
}

void Common::sleep()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}

#include "Common.h"
