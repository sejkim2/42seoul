#ifndef _CLAPTRAP
# define _CLAPTRAP

# include <iostream>
# include <string>

class ClapTrap
{
    public:
        /*canonical form*/
        ClapTrap(void);
        virtual ~ClapTrap(void);
        ClapTrap(const ClapTrap& clapTrap);
        ClapTrap& operator=(const ClapTrap& clapTrap);

        ClapTrap(std::string name);
        virtual void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        std::string     getName(void) const;
        unsigned int    getHitPoint(void) const;
        unsigned int    getEnergyPoint(void) const;
        unsigned int    getAttackDamage(void) const;

    protected:
        bool            isDisabled();
        std::string          name;
        unsigned int         hitPoint;
        unsigned int         energyPoint;
        unsigned int         attackDamage;
        static const unsigned int   HITPOINT = 10;
        static const unsigned int   ENERGYPOINT = 10;
        static const unsigned int   ATTACKDAMAGE = 0;
};

#endif
