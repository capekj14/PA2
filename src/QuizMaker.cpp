//
// Created by Jakub Čapek on 22.04.2022.
//

#include <limits>
#include "QuizMaker.h"

void QuizMaker::askPageCount(int& pageCount)
{
    std::cout << "Zadejte pocet stranek noveho kvizu (nezadavejte vice nez 10) :" << std::endl;
    while(true)
    {
        if(Common::getNumber(pageCount) and pageCount <= 10 and pageCount > 0)
            break;
        std::cout << "Zadejte pocet znovu\n";
        //Common::clearConsole();
    }
}

void QuizMaker::askName(std::string& name)
{
    std::cout << "Zadejte jmeno noveho kvizu (bez mezer a jinych bilych znaku) :" << std::endl;
    while(true)
    {
        if(Common::getString(name) and Common::checkQuizName(name))
            break;
        std::cout << "Zadejte nazev znovu, bud jste neodpovedeli nebo takovy kviz jiz existuje\n";
        //Common::clearConsole();
    }
}

void QuizMaker::askQuestionCount(int& questionCount)
{
    std::cout << "Zadejte pocet otazek na teto strance (maximalne 3):" << std::endl;
    while(true)
    {
        if(Common::getNumber(questionCount) and questionCount <= 3 and questionCount > 0)
            break;
        std::cout << "Zadejte pocet znovu\n";
        //Common::clearConsole();
    }
}

void QuizMaker::askQuestionType(QuestionType& type)
{
    std::cout << "Vyberte typ dalsi otazky (staci odpovedet vyberem cisla) :\n"
              << "1) single choice\n"
              << "2) multi choice\n"
              << "3) ano/ne (text otazky bude vyzadovat odpoved ano, ne)\n"
              << "4) volna odpoved" << std::endl;
    int num;
    while(true)
    {
        if(Common::getNumber(num) and (num == 1 or num == 2 or num == 3 or num == 4))
        {
            switch (num)
            {
                case 1: type = QuestionType::SingleChoice; break;
                case 2: type = QuestionType::MultiChoice; break;
                case 3: type = QuestionType::YesNo; break;
                default: type = QuestionType::Free; break;
            }
            break;
        }
        std::cout << "Vyberte typ otazky znovu\n";
        //Common::clearConsole();
    }
}

void QuizMaker::askQuestionText(std::string& text)
{
    std::cout << "Zadejte text otazky:" << std::endl;
    while(true)
    {
        if(Common::getText(text) and !text.empty())
            break;
        std::cout << "Zadejte text otazky znovu\n";
        //Common::clearConsole();
    }
}
void QuizMaker::askCorrectAnswerMulti(std::string& correctAnswer)
{
    std::cout << "Zadejte spravne odpovedi (napr. abc):" << std::endl;
    while(true)
    {
        if(Common::getString(correctAnswer) and Common::checkABCDSet(correctAnswer))
            break;
        std::cout << "Zadejte spravnou odpoved znovu\n";
        //Common::clearConsole();
    }
}
void QuizMaker::askCorrectAnswerYesNo(std::string& correctAnswer)
{
    std::cout << "Zadejte spravnou odpoved (napr. ano):" << std::endl;
    while(true)
    {
        if(Common::getString(correctAnswer) and (correctAnswer == "ne" or correctAnswer == "ano"))
            break;
        std::cout << "Zadejte spravnou odpoved znovu\n";
        //Common::clearConsole();
    }
}
void QuizMaker::askCorrectAnswerSingle(std::string& correctAnswer)
{
    std::cout << "Zadejte spravnou odpoved (napr. b):" << std::endl;
    while(true)
    {
        if(Common::getString(correctAnswer) and (correctAnswer == "a" or correctAnswer == "b"
                                    or   correctAnswer == "c" or correctAnswer == "d"))
            break;
        std::cout << "Zadejte spravnou odpoved znovu\n";
        //Common::clearConsole();
    }
}
void QuizMaker::askCorrectAnswerFree(std::string& correctAnswer, std::string& patern, std::set<std::string>& correctSet)
{
    std::cout << "Zadejte presnou spravnou odpoved (napr. karel)\n"
              << "Pote zadejte pattern ktery musi odpoved nutne obsahovat (napr. kar)\n"
              << "Pote zadejte dalsi uznavane odpovedi ve formatu cislo a odpovedi (nape. 2 karla karlovi)"
              << std::endl;
    while(true)
    {
        if(Common::getText(correctAnswer) and !correctAnswer.empty())
            break;
        std::cout << "Zadejte spravnou odpoved znovu\n";
        //Common::clearConsole();
    }
    while(true)
    {
        if(Common::getText(patern) and !patern.empty())
            break;
        std::cout << "Zadejte spravnou odpoved znovu\n";
        //Common::clearConsole();
    }
    int setAnswerCount;
    while(true)
    {
        if(Common::getNumber(setAnswerCount))
            break;
        std::cout << "Zadejte pocet znovu\n";
        //Common::clearConsole();
    }
    for(int i = 0; i < setAnswerCount; i++)
    {
        while(true)
        {
            std::string str;
            if(Common::getText(str) and !str.empty())
            {
                correctSet.insert(str);
                break;
            }
            std::cout << "Zadejte text znovu\n";
            //Common::clearConsole();
        }
    }
}

void QuizMaker::askOptions(std::vector<std::string>& options)
{
    std::cout << "Zadejte 4 moznosti (napr. bila modra zelena ruzova):" << std::endl;
    for(int i = 0; i < 4; i++)
    {
        std::cout << char('a' + i);
        while(true)
        {
            std::string str;
            if(Common::getText(str) and !str.empty())
            {
                options.push_back(str);
                break;
            }
            std::cout <<"Zadejte moznost znovu\n";
            //Common::clearConsole();
        }
    }
}


