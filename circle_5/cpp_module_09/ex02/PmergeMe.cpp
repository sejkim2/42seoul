#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
    // std::cout << "PmergeMe Default Constructor Called" << '\n';
}

PmergeMe::~PmergeMe(void)
{
    // std::cout << "PmergeMe Default Destructor Called" << '\n';
}

PmergeMe::PmergeMe(const PmergeMe& copy)
{
    *this = copy;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& obj)
{
    if (&obj != this)
    {
    }
    return (*this);
}
