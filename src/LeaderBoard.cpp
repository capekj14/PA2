//
// Created by Jakub Čapek on 23.04.2022.
//

#include "LeaderBoard.h"

void LeaderBoard::addPlayerResult(const Player& player)
{
    std::pair<std::string, unsigned int> actual;
    auto it = std::lower_bound(records.begin(), records.end(), actual);
    records.insert(it, actual);
}

void LeaderBoard::showLeaderBoard()
{
    std::cout << "Seznam hráčů " << std::endl;
    int standing = 1;
    for(auto & record : records)
    {
        std::cout << "\t" << standing++ << "hráč: " << record.first << "skóre: " << record.second << std::endl;
    }
}

void LeaderBoard::pushBackPlayer(const std::pair<std::string, unsigned int>& record)
{
    records.push_back(record);
}

std::string LeaderBoard::getNameOnIndex(size_t index)
{
    return records[index].first;
}

unsigned int LeaderBoard::getScoreInIndex(size_t index)
{
    return records[index].second;
}

void LeaderBoard::save(const std::string& fileName)
{
    std::ofstream output(fileName + ".txt");
    output << records.size() << std::endl;
    for(int i = 0; i < records.size(); i++)
    {
        output << i+1 << " " <<getNameOnIndex(i) << " " << getScoreInIndex(i) << std::endl;
    }
}

void LeaderBoard::load(const std::string& fileName)
{
    std::ifstream input(fileName + ".txt");
    int count;
    input >> count;
    for(int i = 0; i < count; i++)
    {
        std::pair<std::string, unsigned int> record;
        input >> record.first >> record.second;
        pushBackPlayer(record);
    }
}
