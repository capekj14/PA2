//
// Created by notebookHP on 25.04.2022.
//

#include "IOUnitLeaderBoard.h"

bool IOUnitLeaderBoard::load(const std::string &fileName)
{
    std::fstream input(fileName + ".txt");
    int count;
    input >> count;
    for(int i = 0; i < count; i++)
    {
        std::pair<std::string, unsigned int> record;
        input >> record.first >> record.second;
        leaderBoard.pushBackPlayer(record);
    }
    return true;
}

bool IOUnitLeaderBoard::save(const std::string &fileName)
{
    return false;
}
