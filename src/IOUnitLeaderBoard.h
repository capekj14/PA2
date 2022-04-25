//
// Created by notebookHP on 25.04.2022.
//

#ifndef SEMESTRALKA_IOUNITLEADERBOARD_H
#define SEMESTRALKA_IOUNITLEADERBOARD_H


#include "IOUnit.h"

class IOUnitLeaderBoard : public IOUnit
{
public:
    LeaderBoard leaderBoard;
    bool load(const std::string& fileName) override;
    bool save(const std::string& fileName) override;
};


#endif //SEMESTRALKA_IOUNITLEADERBOARD_H
