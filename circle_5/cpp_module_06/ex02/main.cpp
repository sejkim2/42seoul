#include "Base.hpp"
#include "Utils.hpp"

int main()
{
    Base * p = generate();
    
    identify(p);
    identify(*p);
}