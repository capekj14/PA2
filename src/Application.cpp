//
// Created by Jakub Čapek on 22.04.2022.
//

#include "Application.h"

void Application::createQuiz()
{
    quiz.createQuiz();
    quiz.saveQuiz();
}

bool Application::loadQuiz()
{
    std::cout << "Vyberte název kvízu z nabídky:" << std::endl;
    //printAll possible quizez
    std::string str;
    std::cin >> str;
    quiz.setName(str);
    quiz.loadQuiz();
    return true;
}

void Application::showMenu()
{
    std::cout << "Vítejte v aplikaci Marast v2\n\n" << "\t1) Vytvořit nový kvíz\n" << "\t2) Načíst kvíz a hrát\n"
              << "\t3) Konec\n";
}

int Application::getAction()
{
    int ret;
    while(true)
    {
        std::cin >> ret;
        if (ret != 1 and ret != 2 and ret != 3)
        {
            std::cout << "Zadali jste neplatnou možnost, zkuste to znovu " << std::endl;
        }
        else
            break;
    }
    return ret;
}

void Application::run()
{
    while(true)
    {
        showMenu();
        int result = getAction();
        if(result == 1)
        {
            quiz.loadQuiz();
            quiz.run();
        }
        else if(result == 2)
        {
            quiz.createQuiz();
        }
        else if(result == 3)
            break;
    }
}
