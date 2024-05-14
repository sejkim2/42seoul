#ifndef _IMATERIASOURCE
# define _IMATERIASOURCE

# include "AMateria.hpp"
# define MAX_AMA_SIZE 4

class IMateriaSource
{
    public:
        virtual ~IMateriaSource() {}
        virtual void learnMateria(AMateria*) = 0;
        virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
