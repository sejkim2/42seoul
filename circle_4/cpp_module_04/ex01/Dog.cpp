#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    brain = new Brain();
    std::cout << "this is Dog constructor" << '\n';
    std::cout << "Dog has Brain" << '\n';
}

Dog::~Dog(void)
{
    delete brain;
    std::cout << "this is Dog desstructor" << '\n';
    std::cout << "Dog delete Brain" << '\n';
}
        
Dog::Dog(const Dog& dog)
{
    *this = dog;
}

Dog& Dog::operator=(const Dog& dog)
{
    if (&dog == this)
        return (*this);

    Brain *del = brain;
    brain = dog.brain;
    delete del;

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
