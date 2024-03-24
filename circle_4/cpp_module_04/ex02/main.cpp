#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    const Animal *j = new Dog();
    const Animal *i = new Cat();
    delete j; // should not create a leak
    delete i;

    // const Animal *animals[100];
    // for(int i = 0; i<50; i++)
    //     animals[i] = new Dog();
    // for(int i = 50; i < 100; i++)
    //     animals[i] = new Cat();

    // for(int i = 0; i<50; i++)
    //     animals[i] = new Dog();
    // for(int i = 50; i < 100; i++)
    //     animals[i] = new Cat();
    return 0;
}