#include "Zombie.hpp"

int main(void)
{
    std::string name1;
    std::string name2;

    std::cout << "input zombie name >> ";
    std::getline(std::cin, name1);
    std::cout << "input zombie name >> ";
    std::getline(std::cin, name2);
    
    Zombie *zombie = newZombie(name1);
    zombie->announce();

    randomChump(name2);
    delete zombie;
}