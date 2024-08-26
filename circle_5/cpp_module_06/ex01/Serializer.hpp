#ifndef _SERIALIZATION_HPP__
# define _SERIALIZATION_HPP__

# include <iostream>
# include "Data.hpp"

class Serializer
{
    public:
        ~Serializer(void);
        Serializer(const Serializer& copy);
        Serializer& operator=(const Serializer& obj);
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

    private:
        Serializer(void);

};

#endif