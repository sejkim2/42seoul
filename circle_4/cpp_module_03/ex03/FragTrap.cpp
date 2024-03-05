#include "FragTrap.hpp"

FragTrap::FragTrap(void)
{
    std::cout << "FragTrap Default constructor called" << '\n';
}

FragTrap::~FragTrap(void)
{
    std::cout << "FragTrap Destructor called" << '\n';
}
        
FragTrap::FragTrap(const FragTrap& fragTrap)
{
    *this = fragTrap;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
    if (&fragTrap == this)
        return (*this);
    this->name = fragTrap.name;
    this->hitPoint = fragTrap.hitPoint;
    this->energyPoint = fragTrap.energyPoint;
    this->attackDamage = fragTrap.attackDamage;
    return (*this);
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap constructor called" << '\n';
    this->hitPoint = 100;
    this->energyPoint = 100;
    this->attackDamage = 30;
}

void FragTrap::attack(const std::string& target)
{
    if (isDisabled())
        return;
    std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << '\n';
    this->energyPoint--;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap : high fives :)" << '\n';
}
