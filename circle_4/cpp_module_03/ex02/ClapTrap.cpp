#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void) : hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << "Default constructor called" << '\n';
}

ClapTrap::~ClapTrap(void)
{
    std::cout << "Destructor called" << '\n';
}
        
ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
    *this = clapTrap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
    if (&clapTrap == this)
        return (*this);
    this->name = clapTrap.name;
    this->hitPoint = clapTrap.hitPoint;
    this->energyPoint = clapTrap.energyPoint;
    this->attackDamage = clapTrap.attackDamage;
    return (*this);
}

ClapTrap::ClapTrap(std::string name) : name(name), hitPoint(10), energyPoint(10), attackDamage(0)
{
    std::cout << "constructor called" << '\n';
}

void ClapTrap::attack(const std::string& target)
{
    if (isDisabled())
        return;
    std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage!" << '\n';
    this->energyPoint--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (isDisabled())
        return;
    std::cout << "ClapTrap " << this->name << " taken " << amount << " damages!" << '\n';
    if (this->hitPoint < amount)
        this->hitPoint = 0;
    else
        this->hitPoint -= amount;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (isDisabled())
        return;
    std::cout << this->name << " is repaired" << '\n';
    this->energyPoint--;
    this->hitPoint++;
}

std::string     ClapTrap::getName(void)
{
    return (this->name);
}

unsigned int    ClapTrap::getHitPoint(void)
{
    return (this->hitPoint);
}

unsigned int    ClapTrap::getEnergyPoint(void)
{
    return (this->energyPoint);
}

unsigned int    ClapTrap::getAttackDamage(void)
{
    return (this->attackDamage);
}

bool            ClapTrap::isDisabled()
{
    if (this->hitPoint == 0 || this->energyPoint == 0)
    {
        std::cout << "ClapTrap " << this->name << " disabled " << '\n';
        return (true);
    }
    else
        return (false);
}