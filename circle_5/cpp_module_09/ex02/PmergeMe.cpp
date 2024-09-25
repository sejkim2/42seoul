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
    std::vector<int> jacobsthal = generateJacobsthal_vector(n);
    std::vector<int> sorted_arr = mergeInsertion_vector(vector, jacobsthal);
    
    return (sorted_arr);
}

std::list<int> PmergeMe::ford_johnson_by_list(std::list<int>& list)
{
    int n = list.size();
    std::vector<int> jacobsthal = generateJacobsthal_list(n);
    std::list<int> sorted_list = mergeInsertion_list(list, jacobsthal);

    return (sorted_list);
}

std::vector<int> PmergeMe::generateJacobsthal_vector(int n)
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

std::vector<int> PmergeMe::mergeInsertion_vector(std::vector<int>& d, const std::vector<int>& jacobsthal)
{
    int n = d.size();

    if (n <= 1)
        return (d);

    std::vector<int> mainChain;
    std::vector<int> pendingChain;

    initChain_vector(mainChain, pendingChain, d, n);
    mainChain = mergeInsertion_vector(mainChain, jacobsthal);
    
    // std::vector<int> sorted_arr;
    // sorted_arr.insert(sorted_arr.end(), mainChain.begin(), mainChain.end());

    size_t previousJacobsthal = jacobsthal[0];
    binaryInsertion_vector(mainChain, pendingChain[previousJacobsthal]);

    for(size_t i = 1; i < jacobsthal.size(); i++)
    {
        int flag = true;
        size_t curentJacobsthal = jacobsthal[i];
        for(size_t j = curentJacobsthal; j > previousJacobsthal; j--)
        {
            if (j < pendingChain.size())
                binaryInsertion_vector(mainChain, pendingChain[j]);
            else
                flag = false;
        }
        if (!flag)
            break ;
        previousJacobsthal = curentJacobsthal;
    }

    return (mainChain);
}

void PmergeMe::initChain_vector(std::vector<int>& mainChain, std::vector<int>& pendingChain, const std::vector<int>& d, int _size)
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

void PmergeMe::binaryInsertion_vector(std::vector<int>& d, int value)
{
    std::vector<int>::iterator it = std::lower_bound(d.begin(), d.end(), value);
    d.insert(it, value);
}

std::vector<int> PmergeMe::generateJacobsthal_list(int n)
{
    std::vector<int> jacobsthal(n + 1);
    if (n > 0) jacobsthal[0] = 1;
    if (n > 1) jacobsthal[1] = 3;

    for (int i = 2; i <= n; i++)
        jacobsthal[i] = jacobsthal[i - 1] + 2 * jacobsthal[i - 2];

    return jacobsthal;
}

std::list<int> PmergeMe::mergeInsertion_list(std::list<int>& d, const std::vector<int>& jacobsthal)
{
    int n = d.size();
    if (n <= 1) return d;

    std::list<int> mainChain, pendingChain;
    initChain_list(mainChain, pendingChain, d, n);

    mainChain = mergeInsertion_list(mainChain, jacobsthal);

    std::list<int> sorted_array;
    sorted_array.insert(sorted_array.end(), mainChain.begin(), mainChain.end());

    int previousJacobsthal = jacobsthal[0];
    std::list<int>::iterator it = pendingChain.begin();
    std::list<int>::iterator tmp;
    binaryInsertion_list(sorted_array, *it);
    int i = 1;

    while (1)
    {
        size_t curentJacobsthal = jacobsthal[i];
        i++;
        tmp = it;
        int cnt = curentJacobsthal;
        while (cnt > previousJacobsthal && tmp != pendingChain.end())
        {
            tmp++;
            cnt--;
        }
        if (tmp == pendingChain.end())
        {
            tmp--;
            break ;
        }
        std::list<int>::iterator tmp2 = tmp;
        while (tmp != it)
        {
            binaryInsertion_list(sorted_array, *tmp);
            tmp--;
        }
        it = tmp2;
    }
    while (tmp != it)
    {
        binaryInsertion_list(sorted_array, *tmp);
        tmp--;
    }

    return sorted_array;
}

void PmergeMe::initChain_list(std::list<int>& mainChain, std::list<int>& pendingChain, const std::list<int>& d, int _size)
{
    int cnt = 0;
    std::list<int>::const_iterator prev = d.begin();

    while (1)
    {
        if (cnt + 1 < _size)
        {
            std::list<int>::const_iterator next = prev;
            next++;
            if (*prev > *next)
            {
                mainChain.push_back(*prev);
                pendingChain.push_back(*next);
            }
            else
            {
                mainChain.push_back(*next);
                pendingChain.push_back(*prev);
            }
        }
        else
        {
            if (prev != d.end())
                pendingChain.push_back(*prev);
            break ;
        }
        cnt += 2;
        prev++;
        prev++;
    }
}

void PmergeMe::binaryInsertion_list(std::list<int>& d, int value)
{
    std::list<int>::iterator it = std::lower_bound(d.begin(), d.end(), value);
    d.insert(it, value);
}