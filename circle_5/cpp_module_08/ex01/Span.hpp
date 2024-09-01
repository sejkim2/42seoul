#ifndef _SPAN_HPP__
# define _SPAN_HPP__

# include <iostream>
# include <set>
# include <vector>
class Span
{
    public:
        Span(void);
        ~Span(void);
        Span(const Span& copy);
        Span& operator=(const Span& obj);

        Span(unsigned int n);
        void addNumber(int newNumber);
        
        template <typename T>
        void addNumbers(T iter1, T iter2, unsigned int _size);
        
        unsigned int shortestSpan(void);
        unsigned int longestSpan(void);

    private:
        unsigned int _size;
        unsigned int _countNumber;
        std::set<int> set;
};

# include "Span.tpp"

#endif