#ifndef _CHARACTER
# define _CHARACTER

# include "ICharacter.hpp"

class Character : public ICharacter
{
    public:
        /*canonical form*/
        Character(void);
        virtual ~Character(void);
        Character(const Character& character);
        Character& operator=(const Character& character);

        Character(std::string name);
        virtual std::string const & getName() const;
        virtual void equip(AMateria* m) = 0;
        virtual void unequip(int idx);
        virtual void use(int idx, Character& target) = 0;

        int getCountAMateria(void) const;
        int getCountFloorAMateria(void) const;
    private:
        int slot_index;
        int countAMateria;
        int floor_index;
        int countFloorAMateria;
        bool isFullSlot(void) const;
        bool isFullFloor(void) const;
        std::string name;
        AMateria *slot[4];
        AMateria *floor[FLOOR_SIZE];
};

#endif
