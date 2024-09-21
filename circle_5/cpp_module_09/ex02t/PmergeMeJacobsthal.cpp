#include "PmergeMe.hpp"

size_t PmergeMe::Jacobsthal(int num)
{
    if (num == 0)
        return 0;
    if (num == 1)
        return 1;
    return (Jacobsthal(num - 1) + 2 * Jacobsthal(num - 2));
}

void PmergeMe::GetJacobsthal(std::vector<int> &Jacob, size_t JacobSize)
{
    size_t idx = 2;

    while (Jacobsthal(idx) <= JacobSize)
    {
        Jacob.push_back(Jacobsthal(idx));
        ++idx;
    }
}

int PmergeMe::GetJacobsthalLimit(std::vector<int> Jacob, size_t idx)
{
    int limit = 0;
    int start = 2;

    if (Jacob.size() == 1)
        return 0;
    while ((limit = Jacobsthal(start)) < Jacob[idx])
        start++;
    if (limit == 1)
        return 0;
    return Jacobsthal(start - 1);
}