#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap()
{
    std::cout << "ScavTrap " << this->name << " Default constructor called" << '\n';
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
}

ScavTrap::~ScavTrap(void)
{
    std::cout << "ScavTrap " << this->name << " Default Destructor called" << '\n';
}
        
ScavTrap::ScavTrap(const ScavTrap& scavTrap)
{
    *this = scavTrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
    if (&scavTrap == this)
        return (*this);
    this->name = scavTrap.name;
    this->hitPoint = scavTrap.hitPoint;
    this->energyPoint = scavTrap.energyPoint;
    this->attackDamage = scavTrap.attackDamage;
    return (*this);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap " << this->name << " constructor called" << '\n';
    this->hitPoint = 100;
    this->energyPoint = 50;
    this->attackDamage = 20;
}

void ScavTrap::attack(const std::string& target)
{
    if (isDisabled())
        return;
    std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << '\n';
    this->energyPoint--;
}

void ScavTrap::guardGate(void) const
{
    std::cout << "ScavTrap is now in Gate keeper mode." << '\n';
}
