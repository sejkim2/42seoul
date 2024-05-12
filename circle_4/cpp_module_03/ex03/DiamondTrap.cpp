#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap " << this->name << " Default constructor called" << '\n';
    this->hitPoint = FragTrap::HITPOINT;
    this->energyPoint = ScavTrap::ENERGYPOINT;
    this->attackDamage = FragTrap::ATTACKDAMAGE;
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
    this->hitPoint = diamondTrap.hitPoint;
    this->energyPoint = diamondTrap.energyPoint;
    this->attackDamage = diamondTrap.attackDamage;
    return (*this);
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name)
{
    this->name = name;
    std::cout << "DiamondTrap " << this->name << " constructor called" << '\n';
    this->hitPoint = FragTrap::HITPOINT;
    this->energyPoint = ScavTrap::ENERGYPOINT;
    this->attackDamage = FragTrap::ATTACKDAMAGE;
}

void DiamondTrap::attack(const std::string& target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) const
{
    std::cout << "DiamondTrap name is " << DiamondTrap::name << ", and ClapTrap name is " << ClapTrap::name << '\n';
}
