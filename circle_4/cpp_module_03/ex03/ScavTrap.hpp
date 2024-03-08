#ifndef _SCAVTRAP_HPP_
# define _SCAVTRAP_HPP_

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
    public:
        /*canonical form*/
        ScavTrap(void);
        virtual ~ScavTrap(void);
        ScavTrap(const ScavTrap& scavTrap);
        ScavTrap& operator=(const ScavTrap& scavTrap);

        ScavTrap(std::string name);
        virtual void attack(const std::string& target);
        void guardGate(void);
};

#endif
