//
// Created by Jakub Čapek on 22.04.2022.
//

#include "Application.h"

void Application::showMenu()
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
            Common::clearConsole();
        }
        else
            return ret;
    }
}

void Application::run()
{
    while(true)
    {
        showMenu();
        int result = getAction();
        if(result == 1)
        {
            quiz.createQuiz();
        }
        else if(result == 2)
        {
            std::string quizName = findSelectQuizes();
            quiz.loadQuiz(quizName);
            quiz.run();
        }
        else if(result == 3)
            break;
    }
}

std::string Application::findSelectQuizes()
{
    std::string name;
    std::vector<std::string> availableQuizes;
    for(const auto& item : std::filesystem::directory_iterator{"../quizes"})
    {
        std::string str = item.operator const std::filesystem::path &().filename().string();
        std::string adding(str.data(), str.size() - 4);
        availableQuizes.push_back(adding);
        std::cout << adding << std::endl;
    }
    std::cout << "vyberte si kviz z nabidky\n";
    while (true)
    {
        std::cin >> name;
        if(std::find(availableQuizes.begin(), availableQuizes.end(), name) == availableQuizes.end())
        {
            std::cout << "nevybrali jste zadny dostupny kviz\n";
            Common::clearConsole();
        }
        else
            break;
    }
    return name;
}
