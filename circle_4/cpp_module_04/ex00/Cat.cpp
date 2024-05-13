#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    std::cout << "this is Cat constructor" << '\n';
}

Cat::~Cat(void)
{
    std::cout << "this is Cat desstructor" << '\n';
}
        
Cat::Cat(const Cat& cat)
{
    *this = cat;
}

Cat& Cat::operator=(const Cat& cat)
{
    if (&cat == this)
        return (*this);

    Animal::operator=(cat);
    
    return (*this);
}

std::string Cat::getType(void) const
{
    return (Animal::getType());
}

void Cat::makeSound(void) const
{
    std::cout << "Cat's sound : Yaong" << '\n';
}
