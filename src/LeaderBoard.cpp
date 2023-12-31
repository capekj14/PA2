//
// Created by Jakub Čapek on 23.04.2022.
//

#include "LeaderBoard.h"

void LeaderBoard::addPlayerResult(const Player& player)
{
    auto it = std::lower_bound(records.begin(), records.end(), player);
    records.insert(it, player);
}

void LeaderBoard::showLeaderBoard() const
{
    std::cout << "Seznam hracu " << std::endl;
    int standing = 1;
    for(auto & player : records)
    {
        std::cout << "poradi: " << std::setw(3) << standing++ <<
        "\thrac: " << std::setw(20) << player.getName() <<
        "\tskore: " << std::setw(3) << player.getScore() <<
        std::endl;
    }
}

void LeaderBoard::pushBackPlayer(const Player& player)
{
    records.push_back(player);
}

std::string LeaderBoard::getNameOnIndex(size_t index) const
{
    return records[index].getName();
}

unsigned int LeaderBoard::getScoreInIndex(size_t index) const
{
    return records[index].getScore();
}

void LeaderBoard::save(const std::string& fileName) const
{
    std::ofstream output("leaderboards/" + fileName + "_leaderboard.txt");
    output << records.size() << std::endl;
    for(size_t i = 0; i < records.size(); i++)
    {
        output << getNameOnIndex(i) << " " << getScoreInIndex(i) << std::endl;
    }
}

void LeaderBoard::load(const std::string& fileName)
{
    std::ifstream input("leaderboards/" + fileName + "_leaderboard.txt");

    int count;
    input >> count;
    if (input.fail())
        return;
    for(int i = 0; i < count; i++)
    {
        std::string str;
        int num;
        input >> str >> num;
        Player record(str, num);
        pushBackPlayer(record);
    }
}
