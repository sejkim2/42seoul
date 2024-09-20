#ifndef _EASYFIND_HPP__
# define _EASYFIND_HPP__

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <deque>

template <typename T>
typename T::iterator easyfind(T& container, const int& n)
{
    typename T::iterator iter = std::find(container.begin(), container.end(), n);
    
    if (iter == container.end())
        throw std::out_of_range("Value not found");
    else
        return (iter);
}

template <typename T>
typename T::const_iterator easyfind(const T& container, const int& n)
{
    typename T::const_iterator iter = std::find(container.begin(), container.end(), n);
    
    if (iter == container.end())
        throw std::out_of_range("Value not found");
    else
        return (iter);
}

# endif