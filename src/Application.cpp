//
// Created by Jakub Čapek on 22.04.2022.
//

#include "Application.h"

void Application::showMenu() const
{
    std::cout << "Vitejte v aplikaci Marast v2\n\n" << "\t1) Vytvorit novy kviz\n" << "\t2) Nacist kviz a hrat\n"
              << "\t3) Konec\n";
}

int Application::getAction()
{
    while(true)
    {
        int ret;
        std::cin >> ret;
        if (ret != 1 and ret != 2 and ret != 3)
        {
            std::cout << "Zadali jste neplatnou moznost, zkuste to znovu" << std::endl;
            Common::resetConsole();
        }
        else
            return ret;
    }
}

void Application::run()
{
    Common::clearConsole();
    showMenu();
    int result = getAction();
    if(result == 1)
    {
        Common::clearConsole();
        quiz.createQuiz();
    }
    else if(result == 2)
    {
        Common::clearConsole();
        std::vector<std::string> availableQuizes;
        std::cout << "vyberte si kviz z nabidky\n";
        Common::findQuizes(availableQuizes, true);

        std::string quizName = Common::selectQuiz(availableQuizes);
        quiz.loadQuiz(quizName);
    
        quiz.run();
    }
    else if(result == 3)
        return;
}

