#include "Span.hpp"

Span::Span(void)
{
    // std::cout << "Span Default Constructor Called" << '\n';
}

Span::~Span(void)
{
    // std::cout << "Span Default Destructor Called" << '\n';
}

Span::Span(const Span& copy)
{
    *this = copy;
}

Span& Span::operator=(const Span& obj)
{
    if (&obj != this)
    {
    }
    return (*this);
}

Span::Span(unsigned int n)
{
    this->_size = n;
    this->_countNumber = 0;
}

void Span::addNumber(int newNumber)
{
    if (this->_size == this->_countNumber)
        throw (std::overflow_error("set has reached its maximum size!"));

    std::pair<std::set<int>::iterator, bool> result = this->set.insert(newNumber);
    if (result.second == true)
        this->_countNumber++;
}

unsigned int Span::shortestSpan(void)
{
    if (this->_countNumber <= 1)
        throw (std::logic_error("Not enough numbers to calculate a span!"));
   
   std::set<unsigned int> diff;
   std::set<int>::iterator it = this->set.begin();

   for(unsigned int i = 0; i < this->_countNumber; i++)
   {
        int tmp1 = *it;
        it++;
        int tmp2 = *it;
        diff.insert(tmp2 - tmp1);
   }

   return (*(diff.begin()));
}

unsigned int Span::longestSpan(void)
{
    if (this->_countNumber <= 1)
        throw (std::logic_error("Not enough numbers to calculate a span!"));
    
    return (*(this->set.rbegin()) - *(this->set.begin()));
}