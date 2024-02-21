#include "Zombie.hpp"

Zombie::Zombie()
{
    
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

void    Zombie::announce()
{
    std::cout << name << " : " << "BraiiiiiiinnnzzzZ..." << '\n';
}

void    Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie::~Zombie()
{
    std::cout << name << " : " << "Call Destructor..." << '\n';
}