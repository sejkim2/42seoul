#ifndef _MUTANTSTACK_HPP__
# define _MUTANTSTACK_HPP__

# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <stack>

template<typename T, typename C = std::deque<T> >
class MutantStack : public std::stack<T, C>
{
    public:
        MutantStack(void);
        ~MutantStack(void);
        MutantStack(const MutantStack& copy);
        MutantStack<T, C>& operator=(const MutantStack& obj);

        typedef typename C::iterator iterator;
        typedef typename C::const_iterator const_iterator;

        iterator begin(void);
        iterator end(void);
        const_iterator cbegin(void) const;
        const_iterator cend(void) const;

};

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
        std::stack<T, C>::operator=(obj);
    }
    return (*this);
}

template<typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::begin(void)
{
    return (this->c.begin());
}

template<typename T, typename C>
typename MutantStack<T, C>::const_iterator MutantStack<T, C>::cbegin(void) const
{
    return (this->c.begin());
}

template<typename T, typename C>
typename MutantStack<T, C>::iterator MutantStack<T, C>::end(void)
{
    return (this->c.end());
}

template<typename T, typename C>
typename MutantStack<T, C>::const_iterator MutantStack<T, C>::cend(void) const
{
    return (this->c.end());
}

#endif