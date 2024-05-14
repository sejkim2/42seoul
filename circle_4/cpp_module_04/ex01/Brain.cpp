#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "this is Brain constructor" << '\n';
}

Brain::~Brain(void)
{
    std::cout << "this is Brain destructor" << '\n';
}
        
Brain::Brain(const Brain& brain)
{
    *this = brain;
}

Brain& Brain::operator=(const Brain& brain)
{
    if (&brain == this)
        return (*this);

    for(int i = 0; i<IDEASIZE; i++)
        ideas[i] = brain.ideas[i];

    return (*this);
}

Brain::Brain(std::string idea)
{
    for(int i = 0; i<IDEASIZE; i++)
        this->ideas[i] = idea;
}

std::string Brain::getIdeas(int index) const
{
    if (index < 0 || index >= IDEASIZE)
        return "invalid index";
    else
        return this->ideas[index];
}
