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
    return (*this);
}