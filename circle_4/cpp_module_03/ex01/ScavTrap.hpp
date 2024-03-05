#ifndef _SCAVTRAP
# define _SCAVTRAP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        /*canonical form*/
        ScavTrap(void);
        ~ScavTrap(void);
        ScavTrap(const ScavTrap& scavTrap);
        ScavTrap& operator=(const ScavTrap& scavTrap);

        ScavTrap(std::string name);
        void attack(const std::string& target);
        void guardGate();
};

#endif