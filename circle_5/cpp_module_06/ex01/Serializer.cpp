#include "Serializer.hpp"

Serializer::Serializer(void)
{
    std::cout << "Serializer Default Constructor Called" << '\n';
}

Serializer::~Serializer(void)
{
    std::cout << "Serializer Default Destructor Called" << '\n';
}

Serializer::Serializer(const Serializer& copy)
{
    *this = copy;
}

Serializer& Serializer::operator=(const Serializer& obj)
{
    if (&obj != this)
    {
    }
    return (*this);
}

uintptr_t Serializer::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
    return (reinterpret_cast<Data*>(raw));
}
