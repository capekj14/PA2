//
// Created by Jakub Čapek on 02.05.2022.
//

#include "Common.h"

bool Common::getString(std::string& str)
{
    std::cin >> str;
    clearConsole();
}

bool Common::getNumber(int& num)
{
    std::cin >> num;
    clearConsole();
}

bool Common::getText(std::string& text)
{
    std::getline(std::cin, text, '\n');
    clearConsole();
    return true;
}

void Common::clearConsole()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
}

bool Common::checkABCDset(std::string& str)
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
            default: break;
        }
    }
    for(int count : counts)
        if(count > 1)
            return false;
    return true;
}

#include "Common.h"
