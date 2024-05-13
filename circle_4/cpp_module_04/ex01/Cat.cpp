#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat")
{
    brain = new Brain("cat idea...");
    std::cout << "this is Cat constructor" << '\n';
    std::cout << "Cat has Brain" << '\n';
}

Cat::~Cat(void)
{
    delete brain;
    std::cout << "this is Cat desstructor" << '\n';
    std::cout << "Cat delete Brain" << '\n';
}
        
Cat::Cat(const Cat& cat)
{
    *this = cat;
}

Cat& Cat::operator=(const Cat& cat)
{
    if (&cat == this)
        return (*this);

    delete this->brain;
    this->brain = new Brain();
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
