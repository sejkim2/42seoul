#ifndef _ARRAY_TPP__
# define _ARRAY_TPP__

# include "Array.hpp"

template<typename T>
Array<T>::Array(void)
: _size(0)
{
    // std::cout << "Array Default Constructor Called" << '\n';
    arr = new T[_size];
}

template<typename T>
Array<T>::~Array(void)
{
    // std::cout << "Array Default Destructor Called" << '\n';
    delete[] arr;
}

template<typename T>
Array<T>::Array(const Array& copy)
: _size(0)
{
    arr = new T[_size];
    *this = copy;
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& obj)
{
    if (&obj != this)
    {
        delete[] arr;

        this->_size = obj.size();
        this->arr = new T[this->size()];

        for(unsigned int i = 0; i < this->size(); i++)
            this->arr[i] = obj.arr[i];
    }
    return (*this);
}

template<typename T>
Array<T>::Array(unsigned int n)
: _size(n)
{
    this->arr = new T[n];
    std::memset(this->arr, 0, n * sizeof(T));
}

template<typename T>
unsigned int Array<T>::size(void) const
{
    return (this->_size);
}

template<typename T>
T& Array<T>::operator[](int index)
{
    if (index >= 0 && (unsigned int)index < this->size())
        return (this->arr[index]);
    throw std::out_of_range("Index out of range");
}

template<typename T>
const T& Array<T>::operator[](int index) const
{
    if (index >= 0 && (unsigned int)index < this->size())
        return (this->arr[index]);
    throw std::out_of_range("Index out of range");
}

#endif