#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void)
{
    std::cout << "DiamondTrap Default constructor called" << '\n';
}

DiamondTrap::~DiamondTrap(void)
{
    std::cout << "DiamondTrap Destructor called" << '\n';
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
    this->hitPoint = diamondTrap.hitPoint;
    this->energyPoint = diamondTrap.energyPoint;
    this->attackDamage = diamondTrap.attackDamage;
    return (*this);
}

DiamondTrap::DiamondTrap(std::string name) : name(name)
{
    // DiamondTrap::name = name;
    this->hitPoint = FragTrap::getHitPoint();
}

void DiamondTrap::whoAmI(void)
{
    std::cout << "DiamondTrap name is " << this->name << ", and ClapTrap name is " << ClapTrap::name;
}
