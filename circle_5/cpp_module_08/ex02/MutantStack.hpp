#ifndef _MUTANTSTACK_HPP__
# define _MUTANTSTACK_HPP__

# include <iostream>
# include <vector>
# include <list>
# include <deque>
# include <stack>

template<typename T, typename C = std::deque<T>>
class MutantStack : public std::stack<T, C>
{
    public:
        MutantStack(void);
        ~MutantStack(void);
        MutantStack(const MutantStack& copy);
        MutantStack<T>& operator=(const MutantStack& obj);

        T& top(void);
        const T& top(void) const;

        bool empty() const;
        size_t size() const;
        
        void push(const T& value);
        void push(T& value);

        void pop(void);

        typedef typename std::vector<T>::iterator iterator;
        typedef typename std::vector<T>::const_iterator const_iterator;

        iterator begin(void);
        iterator end(void);
        const_iterator begin(void) const;
        const_iterator end(void) const;

    private:
        std::vector<T> container;
};

# include "MutantStack.tpp"

#endif