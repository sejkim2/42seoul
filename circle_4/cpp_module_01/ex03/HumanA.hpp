#ifndef _HUMAN_A
# define _HUMAN_A

# include "Weapon.hpp"

class HumanA
{
    private:
        Weapon weapon;
        std::string name;
    public:
        HumanA(std::string name, Weapon weapon);
        void attack();
};

#endif