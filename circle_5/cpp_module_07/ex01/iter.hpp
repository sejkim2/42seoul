#ifndef _ITER_HPP__
# define _ITER_HPP__

# include <iostream>

template <typename T>
void save(T* arr, size_t index)
{
    arr[index] = index;
}

template <typename T>
void print(T* arr, size_t index)
{
    std::cout << "arr[" << index << "] : " << arr[index] << '\n';
}

template <typename T>
void iter(T *arr, size_t len, void (*func)(T*, size_t))
{
    for(size_t i = 0; i < len; i++)
        func(arr, i);
}

# endif