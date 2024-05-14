#ifndef _ICHARACTER
# define _ICHARACTER

# include "AMateria.hpp"
# define MAX_SLOT_SIZE 4
# define FLOOR_SIZE 1000

class ICharacter
{
    public:
        /*canonical form*/
        ICharacter(void);
        virtual ~ICharacter(void);
        ICharacter(const ICharacter& iCharacter);
        ICharacter& operator=(const ICharacter& iCharacter);

        ICharacter(std::string name);
        virtual std::string const & getName() const = 0;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx) = 0;
        virtual void use(int idx, ICharacter& target) = 0;

    private:
        int index;
        int countAMateria;
        bool getIsFull(void) const;
        std::string name;
        AMateria *slot[4];
        AMateria *floor[FLOOR_SIZE];
};

#endif