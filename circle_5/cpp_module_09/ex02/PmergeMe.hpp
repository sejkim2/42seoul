#ifndef _PMERGEME_HPP__
# define _PMERGEME_HPP__

# include <iostream>
# include <vector>
# include <list>
# include <set>
# include <sstream>

class PmergeMe
{
    public:
        PmergeMe(void);
        ~PmergeMe(void);
        PmergeMe(const PmergeMe& copy);
        PmergeMe& operator=(const PmergeMe& obj);
    
        void ford_johnson_by_vector(std::vector<int>& vector);
        void ford_johnson_by_list(std::list<int>& list);
};

#endif
