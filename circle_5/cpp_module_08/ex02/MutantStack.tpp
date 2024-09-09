#ifndef _MUTANTSTACK_TPP__
# define _MUTANTSTACK_TPP__

# include "MutantStack.hpp"

template<typename T, typename C>
MutantStack<T, C>::MutantStack(void)
{
    // std::cout << "MutantStack Default Constructor Called" << '\n';
}

template<typename T, typename C>
MutantStack<T, C>::~MutantStack(void)
{
    // std::cout << "MutantStack Default Destructor Called" << '\n';
}

template<typename T, typename C>
MutantStack<T, C>::MutantStack(const MutantStack& copy)
{
    *this = copy;
}

template<typename T, typename C>
MutantStack<T, C>& MutantStack<T, C>::operator=(const MutantStack& obj)
{
    if (&obj != this)
    {
    }
    return (*this);
}

template<typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::begin(void)
{
    return (this->c.begin());
}

template<typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::end(void)
{
    return (this->c.end());
}

template<typename T, typename C>
typename MutantStack<T, C>::reverse_iterator MutantStack<T, C>::rbegin(void)
{
    return (this->c.rbegin());
}

template<typename T, typename C>
typename MutantStack<T, C>::reverse_iterator MutantStack<T, C>::rend(void)
{
    return (this->c.rend());
}

#endif