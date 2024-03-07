#include "FragTrap.hpp"

class TrapHandler
{
    public:
        TrapHandler(ClapTrap* attacker, ClapTrap* defender)
        {
            this->attacker = attacker;
            this->defender = defender;
        }
        void trapAction()
        {
            attacker->attack(defender->getName());
            defender->takeDamage(attacker->getAttackDamage());
            std::cout << "hitpoint : " << defender->getHitPoint() << '\n';        
        }
    private:
        ClapTrap* attacker;
        ClapTrap* defender;
};

int main(void)
{
    // FragTrap ft1("ft1");
    // FragTrap ft2("ft2");
    ClapTrap ct1("ct1");
    ClapTrap ct2("ct2");

    // ft1.attack(ft2.getName());
    // ft2.takeDamage(ft1.getAttackDamage());
    // std::cout << "ft2 hitpoint : " << ft2.getHitPoint() << '\n';

    // std::cout << "_____________________________________________________" << '\n';

    // TrapHandler trapHandler(&ft1, &ft2);
    TrapHandler trapHandler(&ct1, &ct2);
    trapHandler.trapAction();
}
