//
// Created by Jakub Čapek on 22.04.2022.
//

#include "Page.h"

void Page::showPage()
{

}

size_t Page::getQuestionCount()
{
    return questions.size();
}

int Page::getScore()
{
    int ret = 0;
    for(auto question : questions)
    {
        bool ok = question->getCorrectlyAnswered();
        if(ok)
            ret++;
    }
    return ret;
}
