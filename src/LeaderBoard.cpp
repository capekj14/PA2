//
// Created by Jakub Čapek on 23.04.2022.
//

#include "LeaderBoard.h"

void LeaderBoard::load()
{

}

void LeaderBoard::save()
{

}

void LeaderBoard::addPlayerResult(const Player& player)
{
    std::pair<std::string, unsigned int> actual;
    auto it = std::lower_bound(records.begin(), records.end(), actual);
    records.insert(it, actual);
}

void LeaderBoard::printRecords()
{
    std::cout << "Seznam hráčů " << std::endl;
    int standing = 1;
    for(auto & record : records)
    {
        std::cout << "\t" << standing++ << "hráč: " << record.first << "skóre: " << record.second << std::endl;
    }
}

void LeaderBoard::pushBackPlayer(std::pair<std::string, unsigned int> record)
{
    records.push_back(record);
}
