#ifndef _FRAGTRAP_HPP_
# define _FRAGTRAP_HPP_

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
    public:
        /*canonical form*/
        FragTrap(void);
        virtual ~FragTrap(void);
        FragTrap(const FragTrap& fragTrap);
        FragTrap& operator=(const FragTrap& fragTrap);

        FragTrap(std::string name);
        virtual void attack(const std::string& target);
        void highFivesGuys(void);

    protected:
        static const unsigned HITPOINT = 100;
        static const unsigned ENERGYPOINT = 100;
        static const unsigned ATTACKDAMAGE = 30;
};

#endif
