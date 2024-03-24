#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "this is Brain constructor" << '\n';
}

Brain::~Brain(void)
{
    std::cout << "this is Brain desstructor" << '\n';
}
        
Brain::Brain(const Brain& brain)
{
    *this = brain;
}

Brain& Brain::operator=(const Brain& brain)
{
    if (&brain == this)
        return (*this);

    for(int i = 0; i<100; i++)
        ideas[i] = brain.ideas[i];

    return (*this);
}
