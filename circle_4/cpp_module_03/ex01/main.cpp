#include "ScavTrap.hpp"

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
    // ScavTrap st1("st1");
    // ScavTrap st2("st2");
    ClapTrap ct1("ct1");
    ClapTrap ct2("ct2");

    // st1.attack(st2.getName());
    // st2.takeDamage(st1.getAttackDamage());
    // std::cout << "st2 hitpoint : " << st2.getHitPoint() << '\n';

    // std::cout << "_____________________________________________________" << '\n';

    // TrapHandler trapHandler(&st1, &st2);
    TrapHandler trapHandler(&ct1, &ct2);
    trapHandler.trapAction();
}
