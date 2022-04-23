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
    //insert
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
