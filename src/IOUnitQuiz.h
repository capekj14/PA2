//
// Created by notebookHP on 25.04.2022.
//

#ifndef SEMESTRALKA_IOUNITQUIZ_H
#define SEMESTRALKA_IOUNITQUIZ_H


#include "IOUnit.h"

class IOUnitQuiz : public IOUnit
{
    Quiz quiz;
public:
    bool load(const std::string& fileName) override;
    bool save(const std::string& fileName) override;
};


#endif //SEMESTRALKA_IOUNITQUIZ_H
