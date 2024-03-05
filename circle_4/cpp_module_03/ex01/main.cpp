#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap ct1("ct1");
    ClapTrap ct2("ct2");

    ct1.attack(ct2.getName());
    ct2.takeDamage(ct1.getAttackDamage());
}