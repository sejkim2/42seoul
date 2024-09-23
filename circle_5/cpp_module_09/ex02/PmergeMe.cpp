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

std::vector<int> PmergeMe::ford_johnson_by_vector(std::vector<int>& vector)
{
    int n = vector.size();
    std::vector<int> jacobsthal = generateJacobsthal(n);
    std::vector<int> sorted_arr = mergeInsertion(vector, jacobsthal);
    
    return (sorted_arr);
}

void PmergeMe::ford_johnson_by_list(std::list<int>& list)
{

}

std::vector<int> PmergeMe::generateJacobsthal(int n)
{
    std::vector<int> jacobsthal(n + 1);
    if (n > 0)
        jacobsthal[0] = 1;
    if (n > 1)
        jacobsthal[1] = 3;

    for(int i = 2; i <= n; i++)
        jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];
    
    for(int i = 0; i <= n; i++)
        jacobsthal[i] -= 1;
    
    return (jacobsthal);
}

std::vector<int> PmergeMe::mergeInsertion(std::vector<int>& d, const std::vector<int>& jacobsthal)
{
    int n = d.size();

    if (n <= 1)
        return (d);

    std::vector<int> mainChain;
    std::vector<int> pendingChain;

    initChain(mainChain, pendingChain, d, n);
    mainChain = mergeInsertion(mainChain, jacobsthal);
    
    std::vector<int> sorted_arr;
    sorted_arr.insert(sorted_arr.end(), mainChain.begin(), mainChain.end());

    int previousJacobsthal = jacobsthal[0];
    binaryInsertion(sorted_arr, pendingChain[previousJacobsthal]);

    for(int i = 1; i < jacobsthal.size(); i++)
    {
        int curentJacobsthal = jacobsthal[i];
        for(int j = curentJacobsthal; j > previousJacobsthal; j--)
        {
            if (j < pendingChain.size())
                binaryInsertion(sorted_arr, pendingChain[j]);
        }
        previousJacobsthal = curentJacobsthal;
    }

    return (sorted_arr);
}

void PmergeMe::initChain(std::vector<int>& mainChain, std::vector<int>& pendingChain, const std::vector<int>& d, int _size)
{
    for(int i = 0; i < _size; i += 2)
    {
        if (i + 1 < _size)
        {
            if (d[i] > d[i + 1])
            {
                mainChain.push_back(d[i]);
                pendingChain.push_back(d[i + 1]);
            }
            else
            {
                mainChain.push_back(d[i + 1]);
                pendingChain.push_back(d[i]);
            }
        }
        else
            pendingChain.push_back(d[i]);
    }
}

void PmergeMe::binaryInsertion(std::vector<int>& d, int value)
{
    std::vector<int>::iterator it = std::lower_bound(d.begin(), d.end(), value);
    d.insert(it, value);
}