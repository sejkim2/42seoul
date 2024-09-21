#include "PmergeMe.hpp"

void PmergeMe::MergeInsertionSortList(size_t pre_size)
{
    size_t size = pre_size * 2;
    size_t idx = 0;
    while (idx <= lst.size() - size) {
        std::list<int>::iterator it1 = lst.begin(); std::advance(it1, idx);
        std::list<int>::iterator it2 = lst.begin(); std::advance(it2, idx + pre_size);
        if (*it1 < *it2)
        {
            size_t jdx = 0;
            std::list<int>::iterator it3 = it1; std::advance(it3, pre_size);
            while (jdx < pre_size)
            {
                std::swap(*it1, *it3);
                ++it1; ++it3; ++jdx;
            }
        }
        idx += size;
    }
    if (size * 2 <= lst.size())
        MergeInsertionSortList(size);
    std::list<int> MainChain, SubChain;
    GroupMainSubChain(MainChain, SubChain, pre_size);
    std::vector<int> Jacob;
    GetJacobsthal(Jacob, SubChain.size() / pre_size);
    BinarySearchInsertion(MainChain, SubChain, Jacob, pre_size);
    std::copy(MainChain.begin(), MainChain.end(), lst.begin());
}

static std::list<int>::iterator ft_at(std::list<int>::iterator it, int n)
{
    std::advance(it, n);
    return it;
}

void PmergeMe::GroupMainSubChain(std::list<int> &MainChain, std::list<int> &SubChain, size_t pre_size)
{
    size_t size = pre_size * 2;
    size_t idx = 0;

    while (idx < lst.size() / size * size) {
        MainChain.insert(MainChain.end(), ft_at(lst.begin(), idx), ft_at(lst.begin(), (idx + pre_size)));
        SubChain.insert(SubChain.end(), ft_at(lst.begin(), idx + pre_size), ft_at(lst.begin(), (idx + size)));
        idx += size;
    }

    if (lst.size() - idx >= pre_size)
        SubChain.insert(SubChain.end(), ft_at(lst.begin(), idx), ft_at(lst.begin(), (idx + pre_size)));
}

int PmergeMe::BinarySearch(std::list<int> MainChain, int target, size_t size)
{
    size_t mid;
    size_t left = 0;
    size_t right = MainChain.size() / size - 1;

    if (right == 0)
        return 0;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (*ft_at(MainChain.begin(), mid * size) < target)
            left = mid + 1;
        else
            right = mid;
    }
    if (*ft_at(MainChain.begin(), left * size) < target)
        return (left + 1) * size;
    return left * size;
}

void PmergeMe::BinarySearchInsertion(std::list<int> &MainChain, std::list<int> &SubChain, std::vector<int> &Jacob, size_t pre_size)
{
    size_t idx = 0, cnt = 0;
    int found;

    while (idx < Jacob.size()) {
        int limit = GetJacobsthalLimit(Jacob, idx);
        while (limit < Jacob[idx]) {
            int adjdx = (Jacob[idx] - 1 - cnt);
            if (adjdx < 0)
                adjdx = 0;
            found = BinarySearch(MainChain, *ft_at(SubChain.begin(), adjdx * pre_size), pre_size);
            MainChain.insert(ft_at(MainChain.begin(), found), ft_at(SubChain.begin(),(adjdx * pre_size)), ft_at(SubChain.begin(), adjdx * pre_size + pre_size));
            SubChain.erase(ft_at(SubChain.begin(), adjdx * pre_size), ft_at(SubChain.begin(), adjdx * pre_size + pre_size));
            ++cnt;
            Jacob[idx]--;
        }
        idx++;
    }
    while (SubChain.size()) {
        found = BinarySearch(MainChain, *ft_at(SubChain.end(), static_cast<int>(pre_size) * -1), pre_size);
        MainChain.insert(ft_at(MainChain.begin(), found), ft_at(SubChain.end(), static_cast<int>(pre_size) * -1), SubChain.end());
        SubChain.erase(ft_at(SubChain.end(), static_cast<int>(pre_size) * -1), SubChain.end());
    }
}