#include "DiamondTrap.hpp"

int main(void)
{
    DiamondTrap dt1("dt1");
    DiamondTrap dt2("dt2");

    dt1.whoAmI();
    dt2.whoAmI();

    // dt1.attack(dt2.getName());
    std::cout << "dt2 hit point is " << dt2.getHitPoint() << '\n';
    std::cout << "dt2 energy point is " << dt2.getEnergyPoint() << '\n';
    std::cout << "dt2 attack point is " << dt2.getAttackDamage() << '\n';
}
