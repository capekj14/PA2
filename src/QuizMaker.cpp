//
// Created by Jakub Čapek on 22.04.2022.
//

#include "QuizMaker.h"

void QuizMaker::run()
{

}

void QuizMaker::askPageCount()
{
    std::cout << "Zadejte počet stránek nového kvízu:" << std::endl;
}

void QuizMaker::askName()
{
    std::cout << "Zadejte jméno nového kvízu:" << std::endl;
}

void QuizMaker::askQuestionCount()
{
    std::cout << "Zadejte počet otázek na této stránce (maximálně 3):" << std::endl;
}

void QuizMaker::askQuestionType()
{
    std::cout << "Vyberte typ další otázky:\n" << "1) single choice\n" << "2) multi choice\n" << "3) ano/ne\n"
              << "4) volná odpověď" << std::endl;

}

void QuizMaker::askQuestionText()
{
    std::cout << "Zadejte text otázky:" << std::endl;
}

void QuizMaker::askCorrectAnswer(int type)
{
    if(type == 1)
    {
        std::cout << "Zadejte správnou odpověď (např. b):" << std::endl;
    }
    else if(type == 2)
    {
        std::cout << "Zadejte správné odpovědi (např. abc):" << std::endl;
    }
    else if(type == 3)
    {
        std::cout << "Zadejte správnou odpověď (např. ano):" << std::endl;
    }
    else
    {
        std::cout << "Zadejte přesnou správnou odpověď (např. karel)\n"
                  << "Poté zadejte pattern který musí odpověď nutně obsahovat (např. kar)\n"
                  << "Poté zadejte další uznávané odpovědi ve formátu číslo a odpovědi (např. 2 karla karlovi)"
                  << std::endl;
    }
}

void QuizMaker::askOptions(int type)
{
    if(type == 1)
    {
        std::cout << "Zadejte 4 možnosti (např. bílá modrá zelená růžová):" << std::endl;
    }
    else if(type == 2)
    {
        std::cout << "Zadejte 4 možnosti (např. bílá modrá zelená růžová):" << std::endl;
    }
}

std::string QuizMaker::getString()
{
    std::string ret;
    std::cin >> ret;
    return ret;
}

int QuizMaker::getNumber()
{
    int ret;
    std::cin >> ret;
    return ret;
}
