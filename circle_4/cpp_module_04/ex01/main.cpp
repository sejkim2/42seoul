#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    {
        std::cout << "_____________________________test case 1_____________________________" << '\n';
        
        const Animal *j = new Dog();
        const Animal *i = new Cat();
        delete j; // should not create a leak
        delete i;
    }
    {
        std::cout << "_____________________________test case 2_____________________________" << '\n';
        
        Animal *animals[6];
        for(int i = 0; i<3; i++)
            animals[i] = new Dog();
        for(int i = 3; i < 6; i++)
            animals[i] = new Cat();

        for(int i = 0; i<3; i++)
            animals[i] = new Dog();
        for(int i = 3; i < 6; i++)
            animals[i] = new Cat();
    }
}