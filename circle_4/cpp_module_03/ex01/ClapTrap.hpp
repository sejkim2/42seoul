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

        std::string     getName(void);
        unsigned int    getHitPoint(void);
        unsigned int    getEnergyPoint(void);
        unsigned int    getAttackDamage(void);

    // private:
    protected:
        bool            isDisabled();
        std::string          name;
        unsigned int         hitPoint;
        unsigned int         energyPoint;
        unsigned int         attackDamage;
};

#endif
