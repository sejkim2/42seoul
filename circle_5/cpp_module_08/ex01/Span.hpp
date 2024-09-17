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

        unsigned int getSize(void) const;
        unsigned int getCountNumber(void) const;
        const std::set<int> getSet(void) const;

    private:
        unsigned int _size;
        unsigned int _countNumber;
        std::set<int> set;
};

template <typename T>
void Span::addNumbers(T iter1, T iter2, unsigned int _size)
{
    if (this->_countNumber + _size > this->_size)
        throw (std::overflow_error("set has reached its maximum size!"));
    this->set.insert(iter1, iter2);
}

#endif