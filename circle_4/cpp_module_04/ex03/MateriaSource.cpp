#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void) : amateria_index(0), countAmateria(0)
{
    for(int i = 0; i < MAX_AMA_SIZE; i++)
        amateria[i] = 0;

    std::cout << "this is MateriaSource constructor" << '\n';
}

MateriaSource::~MateriaSource(void)
{
    for(int i = 0; i < countAmateria; i++)
        delete amateria[i];

    std::cout << "this is MateriaSource destructor" << '\n';
}
        
MateriaSource::MateriaSource(const MateriaSource& materiaSource)
{
    *this = materiaSource;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& materiaSource)
{
    if (&materiaSource == this)
        return (*this);

    for(int i = 0; i < countAmateria; i++)
        delete amateria[i];
    for(int i = 0; i < materiaSource.getCountAmateria(); i++)
        amateria[i] = materiaSource.amateria[i]->clone();

    return (*this);
}

void MateriaSource::learnMateria(AMateria* amateria)
{
    if (isFull() == true)
        return;

    this->amateria[amateria_index] = amateria;
    amateria_index++;
    countAmateria++;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    if (countAmateria != 0)
    {
        if (amateria[countAmateria]->getType() == type)
            return amateria[countAmateria]->clone();
    }
    return (0);
}

int MateriaSource::getCountAmateria(void) const
{
    return (this->countAmateria);
}

bool MateriaSource::isFull(void) const
{
    if (countAmateria == MAX_AMA_SIZE)
        return (true);
    else
        return (false);
}
