#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("Empty")
{
    std::cout << "this is WrongAnimal constructor" << '\n';
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "this is WrongAnimal destructor" << '\n';
}
        
WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal)
{
    *this = wrongAnimal;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
    if (&wrongAnimal == this)
        return (*this);

    this->type = wrongAnimal.type;
    
    return (*this);
}

WrongAnimal::WrongAnimal(std::string type) : type(type)
{
}

std::string WrongAnimal::getType(void) const
{
    return (type);
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal's sound : @#$%@#$" << '\n';
}
