#include "Animal.hpp"

Animal::Animal(void) : type("")
{
    std::cout << "this is Animal constructor" << '\n';
}

Animal::~Animal(void)
{
    std::cout << "this is Animal desstructor" << '\n';
}
        
Animal::Animal(const Animal& animal)
{
    *this = animal;
}

Animal& Animal::operator=(const Animal& animal)
{
    if (&animal == this)
        return (*this);
    type = animal.type;
    return (*this);
}

Animal::Animal(std::string type) : type(type)
{
    /* empty */
}

std::string Animal::getType(void) const
{
    return (type);
}

// void Animal::setType(std::string type)
// {
//     this->type = type;
// }

void Animal::makeSound(void) const
{
    std::cout << "Animal's sound : @#$%@#$" << '\n';
    /* this is pure virtual function */
}
