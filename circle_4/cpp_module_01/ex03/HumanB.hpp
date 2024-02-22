#ifndef _HUMAN_B
# define _HUMAN_B

# include "Weapon.hpp"

class HumanB
{
    private:
        Weapon* weapon;
        std::string name;
    public:
        HumanB(std::string name);
        void attack();
        void setWeapon(Weapon& weapon);
};

#endif