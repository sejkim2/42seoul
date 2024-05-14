#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    std::cout << "this is Dog constructor" << '\n';
}

Dog::~Dog(void)
{
    std::cout << "this is Dog destructor" << '\n';
}
        
Dog::Dog(const Dog& dog) : Animal(dog)
{
    *this = dog;
}

Dog& Dog::operator=(const Dog& dog)
{
    if (&dog == this)
        return (*this);
    
    Animal::operator=(dog);

    return (*this);
}

std::string Dog::getType(void) const
{
    return (Animal::getType());
}

void Dog::makeSound(void) const
{
    std::cout << "Dog's sound : Bow" << '\n';
}
