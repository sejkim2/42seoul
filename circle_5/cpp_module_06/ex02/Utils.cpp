#include "Utils.hpp"

Base* generate(void)
{
    std::srand(std::time(0));
    sleep(1);

    int randomNumber = std::rand() % 3;
    if (randomNumber == 0)
    {
        std::cout << "generate : A" << '\n';
        return (new A());
    }
    else if (randomNumber == 1)
    {
        std::cout << "generate : B" << '\n';
        return (new B());
    }
    else
    {
        std::cout << "generate : C" << '\n';
        return (new C());
    }
}

void identify(Base* p)
{
    std::cout << "<pointer>" << '\n';

    A* a = dynamic_cast<A*>(p);
    if (a != 0)
    {
        std::cout << "actual type : A" << '\n';
        return;
    }

    B* b = dynamic_cast<B*>(p);
    if (b != 0)
    {
        std::cout << "actual type : B" << '\n';
        return;
    }

    C* c = dynamic_cast<C*>(p);
    if (c != 0)
    {
        std::cout << "actual type : C" << '\n';
        return;
    }

    std::cout << "actual type : other object" << '\n';
}

void identify(Base& p)
{
    std::cout << "<reference>" << '\n';

    try {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "actual type : A" << '\n';
        return;
    } catch (std::bad_cast& e) {
        std::cout << "not A" << '\n';
    }

    try {
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "actual type : B" << '\n';
        return;
    } catch (std::bad_cast& e) {
        std::cout << "not B" << '\n';
    }

    try {
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "actual type : C" << '\n';
        return;
    } catch (std::bad_cast& e) {
        std::cout << "not C" << '\n';
    }

    std::cout << "actual type : other object" << '\n';
}