#ifndef _MATERIASOURCE
# define _MATERIASOURCE

# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
        /*canonical form*/
        MateriaSource(void);
        virtual ~MateriaSource(void);
        MateriaSource(const MateriaSource& materiaSource);
        MateriaSource& operator=(const MateriaSource& materiaSource);

        virtual void learnMateria(AMateria* amateria);
        virtual AMateria* createMateria(std::string const & type);

        int getCountAmateria(void) const;
    private:
        int amateria_index;
        int countAmateria;
        AMateria *amateria[4];
        bool isFull(void) const;
};

#endif
