#ifndef _CLAPTRAP
# define _CLAPTRAP

# include <iostream>
# include <string>
# define HITPOINT 10
# define ENERGYPOINT 10
# define ATTACKDAMAGE 0

class ClapTrap
{
    public:
        /*canonical form*/
        ClapTrap(void);
        ~ClapTrap(void);
        ClapTrap(const ClapTrap& clapTrap);
        ClapTrap& operator=(const ClapTrap& clapTrap);

        ClapTrap(std::string name);
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string     getName(void) const;
        unsigned int    getHitPoint(void) const;
        unsigned int    getEnergyPoint(void) const;
        unsigned int    getAttackDamage(void) const;

    private:
        bool            isDisabled() const;
        std::string          name;
        unsigned int         hitPoint;
        unsigned int         energyPoint;
        unsigned int         attackDamage;
};

#endif