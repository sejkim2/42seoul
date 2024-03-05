#ifndef _FRAGTRAP
# define _FRAPTRAP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    public:
        /*canonical form*/
        FragTrap(void);
        ~FragTrap(void);
        FragTrap(const FragTrap& fragTrap);
        FragTrap& operator=(const FragTrap& fragTrap);

        FragTrap(std::string name);
        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif