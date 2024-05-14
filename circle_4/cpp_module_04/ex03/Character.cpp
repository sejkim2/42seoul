#include "Character.hpp"

Character::Character(void) : 
slot_index(0), countAMateria(0), floor_index(0), countFloorAMateria(0), name("empty")
{
    for(int i = 0; i < MAX_SLOT_SIZE; i++)
        this->slot[i] = 0;
    
    for(int i = 0; i < FLOOR_SIZE; i++)
        this->floor[i] = 0;
    
    std::cout << "this is ICharacter constructor" << '\n';
}

Character::~Character(void)
{
    for(int i = 0; i < countAMateria; i++)
        delete slot[i];
    for(int i = 0; i < countFloorAMateria; i++)
        delete floor[i];
    std::cout << "this is ICharacter desstructor" << '\n';
}
        
Character::Character(const Character& character)
{
    *this = character;
}

Character& Character::operator=(const Character& character)
{
    if (&character == this)
        return (*this);

    for(int i = 0; i < countAMateria; i++)
        delete slot[i];
    for(int i = 0; i < countFloorAMateria; i++)
        delete floor[i];

    for(int i = 0; i < character.getCountAMateria(); i++)
        slot[i] = character.slot[i]->clone();
    for(int i = 0; i < character.getCountFloorAMateria(); i++)
        floor[i] = character.floor[i]->clone();

    return (*this);
}

Character::Character(std::string name) :
slot_index(0), countAMateria(0), floor_index(0), countFloorAMateria(0), name(name)
{
    for(int i = 0; i < MAX_SLOT_SIZE; i++)
        this->slot[i] = 0;
    
    for(int i = 0; i < FLOOR_SIZE; i++)
        this->floor[i] = 0;
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    if (isFullSlot() == true)
    {
        std::cout << "inventory is full status" << '\n';
        return;
    }

    slot[slot_index] = m;
    slot_index++;
    countAMateria++;
}

void Character::unequip(int idx)
{
    if (slot[idx] == 0)
        return;
    if (isFullFloor() == true)
    {
        std::cout << "floor is full status" << '\n';
        return;
    }

    this->floor[floor_index] = slot[idx];
    slot[idx] = 0;
    std::cout << "unequip " << this->floor[floor_index]->getType() << '\n';
    floor_index++;
    countFloorAMateria++;
}

void Character::use(int idx, Character& target)
{
    if (slot[idx] == 0)
        return;
    slot[idx]->use(target);
}

int Character::getCountAMateria(void) const
{
    return (this->countAMateria);
}

int Character::getCountFloorAMateria(void) const
{
    return (this->countFloorAMateria);
}

bool Character::isFullSlot(void) const
{
    if (countAMateria == MAX_SLOT_SIZE)
        return (true);
    else
        return (false);
}

bool Character::isFullFloor(void) const
{
    if (countFloorAMateria == FLOOR_SIZE)
        return (true);
    else
        return (false);
}
