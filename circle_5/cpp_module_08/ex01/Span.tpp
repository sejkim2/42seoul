#ifndef _SPAN_TPP
# define _SPAN_TPP

# include "Span.hpp"

template <typename T>
void Span::addNumbers(T iter1, T iter2, unsigned int _size)
{
    if (this->_countNumber + _size > this->_size)
        throw (std::overflow_error("set has reached its maximum size!"));
    this->set.insert(iter1, iter2);
}

#endif
