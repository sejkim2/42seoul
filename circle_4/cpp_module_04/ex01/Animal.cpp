#include "Animal.hpp"

Animal::Animal(void) : type("Empty"), brain(0)
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

    this->type = animal.type;
    
    return (*this);
}

Animal::Animal(std::string type) : type(type), brain(0)
{
}

std::string Animal::getType(void) const
{
    return (type);
}

void Animal::makeSound(void) const
{
    std::cout << "Animal's sound : @#$%@#$" << '\n';
}
