#ifndef _ITER_HPP__
# define _ITER_HPP__

# include <iostream>

template <typename T1>
void print(T1& value)
{
    std::cout << value << '\n';
}

template <typename T1, typename T2>
void iter(T1 *arr, size_t len, T2 func)
{
    for(size_t i = 0; i < len; i++)
        func(arr[i]);
}

# endif