//
// Created by Jakub Čapek on 22.04.2022.
//

#include "QuizMaker.h"

void QuizMaker::run()
{
    std::cout << "VÍTEJTE V MARAST V2 ULTIMÁTNÍM NÁSTROJI PRO VYTVÁŘENÍ KVÍZŮ\n";
    std::string name;
    askName(name);
    int pageCount;
    askPageCount(pageCount);
    for(int i = 0; i < pageCount; i++)
    {
        int questionCount;
        askQuestionCount(questionCount);
        for(int i = 0; i < questionCount; i++)
        {
            QuestionType type;
            askQuestionType(type);
            std::string text;
            askQuestionText(text);
            std::vector<std::string> options;
            askOptions(type, options);
            std::string correctAnswer;
            if(type == QuestionType::Free)
            {
                std::string patern;
                std::set<std::string> correctSet;
                askCorrectAnswer(type, correctAnswer, patern, correctSet);
            }
            else
            {
                askCorrectAnswer(type, correctAnswer);
            }
        }

    }
}

void QuizMaker::askPageCount(int& pageCount)
{
    std::cout << "Zadejte počet stránek nového kvízu (nezadávejte více než 10) :" << std::endl;
    while(true)
    {
        if(getNumber(pageCount) and pageCount <= 10 and pageCount > 0)
            break;
        std::cout << "Zadejte počet znovu\n";
    }
}

void QuizMaker::askName(std::string& name)
{
    std::cout << "Zadejte jméno nového kvízu (bez mezer a jiných bílých znaků) :" << std::endl;
    while(true)
    {
        if(getString(name))
            break;
        std::cout << "Zadejte název znovu\n";
    }
}

void QuizMaker::askQuestionCount(int& questionCount)
{
    std::cout << "Zadejte počet otázek na této stránce (maximálně 3):" << std::endl;
    while(true)
    {
        if(getNumber(questionCount) and questionCount <= 3 and questionCount > 0)
            break;
        std::cout << "Zadejte počet znovu\n";
    }
}

void QuizMaker::askQuestionType(QuestionType& type)
{
    std::cout << "Vyberte typ další otázky (stačí odpovědět výběrem čísla) :\n"
              << "1) single choice\n"
              << "2) multi choice\n"
              << "3) ano/ne (text otázky bude vyžadovat odpověď ano, ne)\n"
              << "4) volná odpověď" << std::endl;
    int num;
    while(true)
    {
        if(getNumber(num) and (num == 1 or num == 2 or num == 3 or num == 4))
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
        std::cout << "Vyberte typ otázky znovu\n";
    }
}

void QuizMaker::askQuestionText(std::string& text)
{
    std::cout << "Zadejte text otázky:" << std::endl;
    while(true)
    {
        if(getString(text) and !text.empty())
            break;
        std::cout << "Zadejte text otázky znovu\n";
    }
}

void QuizMaker::askCorrectAnswer(QuestionType& type, std::string& correctAnswer)
{
    if(type == QuestionType::SingleChoice)
    {
        std::cout << "Zadejte správnou odpověď (např. b):" << std::endl;
        while(true)
        {
            if(getString(correctAnswer) and (correctAnswer == "a" or correctAnswer == "b"
                                        or   correctAnswer == "c" or correctAnswer == "d"))
                break;
            std::cout << "Zadejte správnou odpověď znovu\n";
        }
    }
    else if(type == QuestionType::MultiChoice)
    {
        std::cout << "Zadejte správné odpovědi (např. abc):" << std::endl;
        while(true)
        {
            if(getString(correctAnswer) and checkABCDset(correctAnswer))
                break;
            std::cout << "Zadejte správnou odpověď znovu\n";
        }
    }
    else if(type == QuestionType::YesNo)
    {
        std::cout << "Zadejte správnou odpověď (např. ano):" << std::endl;
        while(true)
        {
            if(getString(correctAnswer) and (correctAnswer == "ne" or correctAnswer == "ano"))
                break;
            std::cout << "Zadejte správnou odpověď znovu\n";
        }
    }

}
void QuizMaker::askCorrectAnswer(QuestionType& type, std::string& correctAnswer, std::string& patern, std::set<std::string>& correctSet)
{
    std::cout << "Zadejte přesnou správnou odpověď (např. karel)\n"
              << "Poté zadejte pattern který musí odpověď nutně obsahovat (např. kar)\n"
              << "Poté zadejte další uznávané odpovědi ve formátu číslo a odpovědi (např. 2 karla karlovi)"
              << std::endl;
    while(true)
    {
        if(getString(correctAnswer) and !correctAnswer.empty())
            break;
        std::cout << "Zadejte správnou odpověď znovu\n";
    }
    while(true)
    {
        if(getString(patern) and !patern.empty())
            break;
        std::cout << "Zadejte správnou odpověď znovu\n";
    }
    int setAnswerCount;
    while(true)
    {
        if(getNumber(setAnswerCount))
            break;
        std::cout << "Zadejte počet znovu\n";
    }
    for(int i = 0; i < setAnswerCount; i++)
    {
        while(true)
        {
            std::string str;
            if(getString(str) and !str.empty())
            {
                correctSet.insert(str);
                break;
            }
            std::cout << "Zadejte text znovu\n";
        }
    }
}

void QuizMaker::askOptions(QuestionType& type, std::vector<std::string>& options)
{
    if(type == QuestionType::MultiChoice)
    {
        std::cout << "Zadejte 4 možnosti (např. bílá modrá zelená růžová):" << std::endl;
        for(int i = 0; i < 4; i++)
        {
            while(true)
            {
                std::string str;
                if(getString(str) and !str.empty())
                {
                    options.push_back(str);
                    break;
                }
                std::cout <<"Zadejte možnost znovu\n";
            }
        }
    }
    else if(type == QuestionType::SingleChoice)
    {
        std::cout << "Zadejte 4 možnosti (např. bílá modrá zelená růžová):" << std::endl;
        for(int i = 0; i < 4; i++)
        {
            while(true)
            {
                std::string str;
                if(getString(str) and !str.empty())
                {
                    options.push_back(str);
                    break;
                }
                std::cout <<"Zadejte možnost znovu\n";
            }
        }
    }
}

bool QuizMaker::getString(std::string& str)
{
    std::cin >> str;
    if(std::cin.fail())
        return false;
    return true;
}

bool QuizMaker::getNumber(int& num)
{
    std::cin >> num;
    if(std::cin.fail())
        return false;
    return true;
}

bool QuizMaker::checkABCDset(std::string &str)
{
    int counts[] = {0,0,0,0};
    if(str.size() >= 4 or str.empty())
        return false;
    for(auto c : str)
    {
        if(c != 'a' and c != 'b' and c != 'c' and c != 'd')
            return false;
        switch(c)
        {
            case 'a': counts[0]++; break;
            case 'b': counts[1]++; break;
            case 'c': counts[2]++; break;
            case 'd': counts[3]++; break;
            default: break;
        }
    }
    for(int count : counts)
        if(count > 1)
            return false;
    return true;
}
