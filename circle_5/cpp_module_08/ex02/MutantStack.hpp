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
        // typedef typename C::const_iterator const_iterator;
        typedef typename C::reverse_iterator reverse_iterator;
        // typedef typename C::const_reverse_iterator const_reverse_iterator;

        iterator begin(void);
        iterator end(void);
        reverse_iterator rbegin(void);
        reverse_iterator rend(void);
        // const_iterator begin(void) const;
        // const_iterator end(void) const;
};

# include "MutantStack.tpp"

#endif