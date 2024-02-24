#include "Harl.hpp"

Harl::Harl()
{
    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";
}

void Harl::debug( void )
{
    std::cout << "[ DEBUG ]" << '\n';
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger." << '\n';
    std::cout << "I really do!" << '\n';
}

void Harl::info( void )
{
    std::cout << "[ INFO ]" << '\n';
    std::cout << "I cannot believe adding extra bacon costs more money." << '\n';
    std::cout << "You didn't put enough bacon in my burger!" << '\n';
    std::cout << "If you did, I wouldn't be asking for more!" << '\n';
}

void Harl::warning( void )
{
    std::cout << "[ WARNING ]" << '\n';
    std::cout << "I think I deserve to have some extra bacon for free." << '\n';
    std::cout << "I've been coming for years whereas you started working here since last month." << '\n';
}

void Harl::error( void )
{
    std::cout << "[ ERROR ]" << '\n';
    std::cout << "This is unacceptable! I want to speak to the manager now." << '\n';
}

void Harl::complain(std::string level)
{
    int index = -1;

    for(size_t i = 0; i < levels->length(); i++)
    {
        if (level == levels[i])
        {
            index = i;
            break ;
        }
    }

    switch (index)
    {
        case -1:
            std::cout << "[ Probably complaining about insignificant problems ]" << '\n';
            break ;
        case 0:
            Harl::debug();
            std::cout << '\n';
            //fall through
        case 1:
            Harl::info();
            std::cout << '\n';
            //fall through 
        case 2:
            Harl::warning();
            std::cout << '\n';
            //fall through
        case 3:
            Harl::error();
            std::cout << '\n';
        default:
            break;
    }
}
