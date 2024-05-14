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
    std::cout << "this is Cat destructor" << '\n';
    std::cout << "Cat Brain is delete" << '\n';
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
    delete this->brain;
    this->brain = new Brain();
    this->brain = cat.brain;

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

std::string Cat::getBrainIdeas(int index) const
{
    return (this->brain->getIdeas(index));
}
