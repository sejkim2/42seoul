#ifndef _FRAGTRAP_HPP_
# define _FRAGTRAP_HPP_

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
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
};

#endif
