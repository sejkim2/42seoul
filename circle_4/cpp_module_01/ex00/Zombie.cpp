#include "Zombie.hpp"

void    Zombie::setName(std::string name)
{
    this->name = name;
}

void    Zombie::announce()
{
    std::cout << name << " : " << "BraiiiiiiinnnzzzZ..." << '\n';
}

Zombie::~Zombie()
{
    std::cout << name << " : " << "is destroyed" << '\n';
}
