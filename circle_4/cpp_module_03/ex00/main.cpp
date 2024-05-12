#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap ct1("ct1");
    ClapTrap ct2("ct2");

    while (1)
    {
        if (ct1.getEnergyPoint() == 0)
        {
            std::cout << "energy point is zero!!" << '\n';
            break ;
        }
        ct1.attack(ct2.getName());
        ct2.takeDamage(ct1.getAttackDamage());
    }
}