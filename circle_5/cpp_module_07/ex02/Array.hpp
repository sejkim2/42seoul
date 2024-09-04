#ifndef _ARRAY_HPP__
# define _ARRAY_HPP__

# include <cstring>

template<typename T>
class Array
{
    public:
        Array(void);
        ~Array(void);
        Array(const Array& copy);
        Array<T>& operator=(const Array& obj);

        Array(unsigned int n);
        unsigned int size(void) const;
        T& operator[](int index);
        const T& operator[](int index) const;

    private:
        T* arr;
        unsigned int _size;
};

# include "Array.tpp"

#endif