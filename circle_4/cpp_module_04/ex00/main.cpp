#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        std::cout << "_______________test case 1_______________" << '\n';
        const Animal *meta = new Animal();
        const Animal *j = new Dog();
        const Animal *i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); // will output the cat sound!
        j->makeSound();
        meta->makeSound();

        delete meta;
        delete j;
        delete i;
    }
    {
        std::cout << "___________________test case 2 : WrongAnimal___________________" << '\n';
        const WrongAnimal *meta = new WrongAnimal();
        const WrongAnimal *i = new WrongCat();
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); // will output the cat sound!
        meta->makeSound();

        delete meta;
        delete i;
    }
}
