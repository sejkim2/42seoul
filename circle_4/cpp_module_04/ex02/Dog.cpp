#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog")
{
    brain = new Brain("dog idea...");
    std::cout << "this is Dog constructor" << '\n';
    std::cout << "Dog has Brain" << '\n';
}

Dog::~Dog(void)
{
    delete brain;
    std::cout << "this is Dog destructor" << '\n';
    std::cout << "Dog Brain is delete" << '\n';
}
        
Dog::Dog(const Dog& dog) : Animal(dog)
{
    *this = dog;
}

Dog& Dog::operator=(const Animal& animal)
{
    if (&animal == this)
        return (*this);

    Animal::operator=(animal);
    const Dog* dog = dynamic_cast<const Dog*>(&animal);
    delete this->brain;
    this->brain = new Brain(*dog->brain);

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

std::string Dog::getBrainIdeas(int index) const
{
    return (this->brain->getIdeas(index));
}
