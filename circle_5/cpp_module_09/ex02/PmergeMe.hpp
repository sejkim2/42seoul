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
    
        std::vector<int> ford_johnson_by_vector(std::vector<int>& vector);
        void ford_johnson_by_list(std::list<int>& list);

    private:
        std::vector<int> generateJacobsthal(int n);
        std::vector<int> mergeInsertion(std::vector<int>& d, const std::vector<int>& jacobsthal);
        void initChain(std::vector<int>& mainChain, std::vector<int>& pendingChain, const std::vector<int>& d, int _size);
        void binaryInsertion(std::vector<int>& d, int value);
};

#endif
