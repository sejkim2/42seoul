#ifndef _EASYFIND_HPP__
# define _EASYFIND_HPP__

# include <iostream>
# include <algorithm>
# include <vector>
# include <list>
# include <deque>

template <typename T>
void easyfind(T container, int n)
{
    typename T::const_iterator iter = std::find(container.begin(), container.end(), n);
    
    if (iter == container.end())
        throw std::runtime_error("Value not found");
    else
        std::cout << *iter << " is exist" << '\n';
}

# endif