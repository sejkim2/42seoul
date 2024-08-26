#include "Serializer.hpp"

int main(void)
{
    Data data("hello");

    Data *ptr = &data;

    uintptr_t a = Serializer::serialize(ptr);
    Data *b = Serializer::deserialize(a);

    std::cout << "origin pointer : " << ptr << '\n';
    std::cout << "dest pointer : " << b << '\n';

    std::cout << ((ptr == b) ? "equal" : "different") << '\n';
}