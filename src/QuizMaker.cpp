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
        if(getNumber(pageCount) and pageCount <= 10 and pageCount > 0)
            break;
        std::cout << "Zadejte pocet znovu\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
}

void QuizMaker::askName(std::string& name)
{
    std::cout << "Zadejte jmeno noveho kvizu (bez mezer a jinych bilych znaku) :" << std::endl;
    while(true)
    {
        if(getString(name))
            break;
        std::cout << "Zadejte nazev znovu\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
}

void QuizMaker::askQuestionCount(int& questionCount)
{
    std::cout << "Zadejte pocet otazek na teto strance (maximalne 3):" << std::endl;
    while(true)
    {
        if(getNumber(questionCount) and questionCount <= 3 and questionCount > 0)
            break;
        std::cout << "Zadejte pocet znovu\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
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
        std::cout << "Vyberte typ otazky znovu\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
}

void QuizMaker::askQuestionText(std::string& text)
{
    std::cout << "Zadejte text otazky:" << std::endl;
    while(true)
    {
        if(getText(text) and !text.empty())
            break;
        std::cout << "Zadejte text otazky znovu\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
}
void QuizMaker::askCorrectAnswerMulti(std::string& correctAnswer)
{
    std::cout << "Zadejte spravne odpovedi (napr. abc):" << std::endl;
    while(true)
    {
        if(getString(correctAnswer) and checkABCDset(correctAnswer))
            break;
        std::cout << "Zadejte spravnou odpoved znovu\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
}
void QuizMaker::askCorrectAnswerYesNo(std::string& correctAnswer)
{
    std::cout << "Zadejte spravnou odpoved (napr. ano):" << std::endl;
    while(true)
    {
        if(getString(correctAnswer) and (correctAnswer == "ne" or correctAnswer == "ano"))
            break;
        std::cout << "Zadejte spravnou odpoved znovu\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
}
void QuizMaker::askCorrectAnswerSingle(std::string& correctAnswer)
{
    std::cout << "Zadejte spravnou odpoved (napr. b):" << std::endl;
    while(true)
    {
        if(getString(correctAnswer) and (correctAnswer == "a" or correctAnswer == "b"
                                    or   correctAnswer == "c" or correctAnswer == "d"))
            break;
        std::cout << "Zadejte spravnou odpoved znovu\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
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
        if(getString(correctAnswer) and !correctAnswer.empty())
            break;
        std::cout << "Zadejte spravnou odpoved znovu\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    while(true)
    {
        if(getString(patern) and !patern.empty())
            break;
        std::cout << "Zadejte spravnou odpoved znovu\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    int setAnswerCount;
    while(true)
    {
        if(getNumber(setAnswerCount))
            break;
        std::cout << "Zadejte pocet znovu\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
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
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
}

void QuizMaker::askOptions(std::vector<std::string>& options)
{
    std::cout << "Zadejte 4 moznosti (napr. bila modra zelena ruzova):" << std::endl;
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
            std::cout <<"Zadejte moznost znovu\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        }
    }
}


bool QuizMaker::getString(std::string& str)
{
    return not not((std::cin >> str));
}

bool QuizMaker::getNumber(int& num)
{
    return not not(std::cin >> num);
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

bool QuizMaker::getText(std::string& text)
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::getline(std::cin, text, '\n');
    return true;
}
