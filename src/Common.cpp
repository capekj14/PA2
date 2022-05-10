//
// Created by Jakub Čapek on 02.05.2022.
//

#include "Common.h"

bool Common::getString(std::string& str)
{
    std::cin >> str;
    resetConsole();
    return std::cin.good();
}

bool Common::getNumber(int& num)
{
    std::cin >> num;
    resetConsole();
    return std::cin.good();
}

bool Common::getText(std::string& text)
{
    std::getline(std::cin, text, '\n');
    std::cin.clear();
    return std::cin.good();
}

void Common::resetConsole()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

bool Common::checkABCDSet(const std::string& str)
{
    int counts[] = {0,0,0,0};
    if(str.empty())
        return false;
    for(auto c : str)
    {
        if(c < 'a' || c > 'd')
            return false;

        counts[c - 'a'] ++;
        if(counts[c - 'a'] > 1)
            return false;
    }
    return true;
}

void Common::findQuizes(std::vector<std::string>& availableQuizes, bool print)
{
    for(const auto& item : std::filesystem::directory_iterator{"quizes"})
    {
        std::filesystem::path path = item;
        std::string str = path.filename().string();
        if(str.size() < 4)
            continue;

        std::string_view last(str.c_str() + str.size() - 4, 4);
        if(last != ".txt")
            continue;

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

void Common::clearConsole()
{
    std::cout << "\x1B[2J\x1B[H";
}

void Common::sleep()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
}

Common::ConversionState Common::strToInt(const char* str)
{
    char dummy = '\0';
    char* end = &dummy; 
    int ret = strtol(str, &end, 10);

    return Common::ConversionState{ret, end != str};
}

std::string Common::extractBetween(std::string_view input, std::string_view before, std::string_view after)
{
    size_t from = input.find(before);
    size_t to = input.find(after);
    
    if(from == (size_t)-1 or to == (size_t)-1 or from > to)
        return "";
    else
        return std::string(input.data() + from + before.size(), to - from - before.size());
}

std::string_view Common::skip(std::string_view in, const char* match)
{
    auto pos = in.find(match);
    if(pos == (size_t)-1)
        return "";

    return in.substr(pos, in.size() - pos);
}

#include "Common.h"
