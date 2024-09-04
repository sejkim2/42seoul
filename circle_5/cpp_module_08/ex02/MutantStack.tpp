#ifndef _MUTANTSTACK_TPP__
# define _MUTANTSTACK_TPP__

# include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(void)
{
    // std::cout << "MutantStack Default Constructor Called" << '\n';
}

template<typename T>
MutantStack<T>::~MutantStack(void)
{
    // std::cout << "MutantStack Default Destructor Called" << '\n';
}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack& copy)
{
    *this = copy;
}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack& obj)
{
    if (&obj != this)
    {
        // this->container.clear();
        this->container = obj;
    }
    return (*this);
}

// template<typename T>
// T& MutantStack<T>::top(void)
// {
//     return (container[container.size() - 1]);
// }

// template<typename T>
// const T& MutantStack<T>::top(void) const
// {
//     return (container[container.size() - 1]);
// }

// template<typename T>
// bool MutantStack<T>::empty(void) const
// {
//     return (container.empty());
// }

// template<typename T>
// size_t MutantStack<T>::size(void) const
// {
//     return (container.size());
// }

// template<typename T>
// void MutantStack<T>::push(const T& value)
// {
//     container.push_back(value);
// }

// template<typename T>
// void MutantStack<T>::push(T& value)
// {
//     container.push_back(value);
// }

// template<typename T>
// void MutantStack<T>::pop(void)
// {
//     container.pop_back();
// }

// template<typename T>
// typename MutantStack<T>::iterator MutantStack<T>::begin(void)
// {
//     return (container.begin());
// }

// template<typename T>
// typename MutantStack<T>::iterator MutantStack<T>::end(void)
// {
//     return (container.end());
// }

#endif