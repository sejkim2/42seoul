#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap " << this->name << " Default constructor called" << '\n';
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap " << this->name << " Default Destructor called" << '\n';
}
        
DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap)
{
    *this = diamondTrap;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
    if (&diamondTrap == this)
        return (*this);
    this->name = diamondTrap.name;
    // this->hitPoint = diamondTrap.hitPoint;
    // this->energyPoint = diamondTrap.energyPoint;
    // this->attackDamage = diamondTrap.attackDamage;
    return (*this);
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}