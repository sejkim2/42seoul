#ifndef _CAT
# define _CAT

# include "Animal.hpp"

class Cat : public Animal
{
    public:
        /*canonical form*/
        Cat(void);
        virtual ~Cat(void);
        Cat(const Cat& cat);
        virtual Cat& operator=(const Animal& cat);

        virtual std::string getType(void) const;
        virtual void makeSound(void) const;

        std::string getBrainIdeas(int index) const;

    private:
        Brain *brain;
};

#endif