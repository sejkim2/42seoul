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
        std::list<int> ford_johnson_by_list(std::list<int>& list);

    private:
        std::vector<int> generateJacobsthal_vector(int n);
        std::vector<int> mergeInsertion_vector(std::vector<int>& d, const std::vector<int>& jacobsthal);
        void initChain_vector(std::vector<int>& mainChain, std::vector<int>& pendingChain, const std::vector<int>& d, int _size);
        void binaryInsertion_vector(std::vector<int>& d, int value);

        std::vector<int> generateJacobsthal_list(int n);
        std::list<int> mergeInsertion_list(std::list<int>& d, const std::vector<int>& jacobsthal);
        void initChain_list(std::list<int>& mainChain, std::list<int>& pendingChain, const std::list<int>& d, int _size);
        void binaryInsertion_list(std::list<int>& d, int value);
};

#endif
