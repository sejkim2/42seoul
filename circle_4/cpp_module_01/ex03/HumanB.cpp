#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    weapon = NULL;
    this->name = name;
}

void HumanB::attack()
{
    if (weapon == NULL)
        std::cout << "not have a Weapon" << '\n';
    else
        std::cout << name << " attacks with their " << weapon->getType() << '\n';
}

void HumanB::setWeapon(Weapon& weapon)
{
    this->weapon = &weapon;
}