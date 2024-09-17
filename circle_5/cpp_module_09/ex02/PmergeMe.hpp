#ifndef _PMERGEME_HPP__
# define _PMERGEME_HPP__

# include <iostream>

class PmergeMe
{
    public:
        PmergeMe(void);
        ~PmergeMe(void);
        PmergeMe(const PmergeMe& copy);
        PmergeMe& operator=(const PmergeMe& obj);
};

#endif
