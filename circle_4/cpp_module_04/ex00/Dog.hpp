#ifndef _DOG
# define _DOG

# include "Animal.hpp"

class Dog : public Animal
{
    public:
        /*canonical form*/
        Dog(void);
        virtual ~Dog(void);
        Dog(const Dog& dog);
        Dog& operator=(const Dog& dog);

        virtual std::string getType(void) const;
        virtual void makeSound(void) const;
};

#endif