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

Cat::Cat(const Cat& cat) : Animal(cat)
{
    *this = cat;
}

Cat& Cat::operator=(const Animal& animal)
{
    if (&animal == this)
        return (*this);

    Animal::operator=(animal);
    const Cat* cat = dynamic_cast<const Cat*>(&animal);
    delete this->brain;
    this->brain = new Brain(*cat->brain);

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
