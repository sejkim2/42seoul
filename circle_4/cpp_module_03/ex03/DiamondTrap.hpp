#ifndef _DIAMONDTRAP_HPP_
# define _DIAMONDTRAP_HPP_

# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : virtual public FragTrap, virtual public ScavTrap
{
    /*canonical form*/
    public:
        DiamondTrap(void);
        virtual ~DiamondTrap(void);
        DiamondTrap(const DiamondTrap& diamondTrap);
        DiamondTrap& operator=(const DiamondTrap& diamondTrap);

        DiamondTrap(std::string name);
        virtual void attack(const std::string& target);
        void whoAmI(void) const;
    private:
        std::string name;    
};

#endif
