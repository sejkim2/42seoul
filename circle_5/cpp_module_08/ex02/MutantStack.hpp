#ifndef _MUTANTSTACK_HPP__
# define _MUTANTSTACK_HPP__

# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <stack>

template<typename T>
class MutantStack : public std::stack<T, std::vector<T> >
{
    public:
        // MutantStack(void);
        // ~MutantStack(void);
        // MutantStack(const MutantStack& copy);
        // MutantStack<T>& operator=(const MutantStack& obj);

        // T& top(void);
        // const T& top(void) const;

        // bool empty() const;
        // size_t size() const;
        
        // void push(const T& value);
        // void push(T& value);

        // void pop(void);

        // typename MutantStack<T>::iterator begin(void);
        // typename MutantStack<T>::iterator end(void);

    // private:
    //     std::vector<T> container;
};

# include "MutantStack.tpp"

#endif