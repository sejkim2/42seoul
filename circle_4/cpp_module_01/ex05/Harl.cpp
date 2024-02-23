#include "Harl.hpp"

void Harl::debug( void )
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!" << '\n';
}

void Harl::info( void )
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << '\n';
}

void Harl::warning( void )
{
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month." << '\n';
}

void Harl::error( void )
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << '\n';
}

void Harl::complain(std::string level)
{
    // (level == DEBUG) ? debug() : (level == INFO) ? info() : (level == WARNING) ? warning() : (level == ERROR) ? error() : (std::cout << "invalid level" << '\n');
    (level == DEBUG) ? debug() :
(level == INFO) ? info() :
(level == WARNING) ? warning() :
(level == ERROR) ? Harl::error() :
(std::cout << "invalid level" << '\n');


}



