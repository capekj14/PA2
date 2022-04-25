//
// Created by Jakub Čapek on 23.04.2022.
//

#ifndef SEMESTRALKA_IOUNIT_H
#define SEMESTRALKA_IOUNIT_H
#include "LeaderBoard.h"
#include "Quiz.h"
#include <fstream>
#include <istream>

class IOUnit
{

public:
    virtual bool load(const std::string& fileName) = 0;
    virtual bool save(const std::string& fileName) = 0;
};


#endif //SEMESTRALKA_IOUNIT_H
