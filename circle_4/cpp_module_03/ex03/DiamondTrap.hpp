#ifndef _DIAMONDTRAP
# define _DIAMONDTRAP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    public:
        /*canonical form*/
        DiamondTrap(void);
        ~DiamondTrap(void);
        DiamondTrap(const DiamondTrap& diamondTrap);
        DiamondTrap& operator=(const DiamondTrap& diamondTrap);

    private:
        std::string name;
};

#endif