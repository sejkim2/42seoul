#ifndef _SCAVTRAP
# define _SCAVTRAP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        /*canonical form*/
        ScavTrap(void);
        ~ScavTrap(void);
        ScavTrap(const ScavTrap& scavTrap);
        ScavTrap& operator=(const ScavTrap& scavTrap);

        ScavTrap(std::string name);
        virtual void attack(const std::string& target);
        void guardGate();
};

#endif