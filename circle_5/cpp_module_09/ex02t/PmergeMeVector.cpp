#include "PmergeMe.hpp"

void PmergeMe::MergeInsertionSortVector(size_t pre_size)
{
    size_t size = pre_size * 2;
    size_t idx = 0;

    while (idx <= vec.size() - size) {
        if (vec[idx] < vec[idx + pre_size]) {
            size_t jdx = 0;
            while (jdx < pre_size) {
                std::swap(vec[idx + jdx], vec[idx + pre_size + jdx]); jdx++;
            }
        }
        idx += size;
    }
    if (size * 2 <= vec.size())
        MergeInsertionSortVector(size);
    std::vector<int> MainChain, SubChain;
    GroupMainSubChain(MainChain, SubChain, pre_size);
    std::vector<int> Jacob;
    GetJacobsthal(Jacob, SubChain.size() / pre_size);
    BinarySearchInsertion(MainChain, SubChain, Jacob, pre_size);
    std::copy(MainChain.begin(), MainChain.end(), vec.begin());
}

void PmergeMe::GroupMainSubChain(std::vector<int> &MainChain, std::vector<int> &SubChain, size_t pre_size)
{
    size_t size = pre_size * 2;
    size_t idx = 0;

    while (idx < vec.size() / size * size) {
        MainChain.insert(MainChain.end(), vec.begin() + idx, vec.begin() + idx + pre_size);
        SubChain.insert(SubChain.end(), vec.begin() + idx + pre_size, vec.begin() + idx + size);
        idx += size;
    }

    if (vec.size() - idx >= pre_size)
        SubChain.insert(SubChain.end(), vec.begin() + idx, vec.begin() + idx + pre_size);
}

int PmergeMe::BinarySearch(std::vector<int> MainChain, int target, size_t size)
{
    size_t mid;
    size_t left = 0;
    size_t right = MainChain.size() / size - 1;

    if (right == 0)
        return 0;
    while (left < right)
    {
        mid = left + (right - left) / 2;
        if (MainChain[mid * size] < target)
            left = mid + 1;
        else
            right = mid;
    }
    if (MainChain[left * size] < target)
        return (left + 1) * size;
    return left * size;
}

void PmergeMe::BinarySearchInsertion(std::vector<int> &MainChain, std::vector<int> &SubChain, std::vector<int> &Jacob, size_t pre_size)
{
    size_t idx = 0, cnt = 0;
    int found;

    while (idx < Jacob.size()) {
        int limit = GetJacobsthalLimit(Jacob, idx);
        while (limit < Jacob[idx]) {
            // cout << "제한: " << limit << " 야콥 수: " << Jacob[idx] << " 조정 값: " << cnt << "\n";
            int adjdx = (Jacob[idx] - 1 - cnt);
            if (adjdx < 0)
                adjdx = 0;
            found = BinarySearch(MainChain, SubChain[adjdx * pre_size], pre_size);
            // show(MainChain, "바이너리 전 Main");
            // show(SubChain, "바이너리 전 Sub");
            MainChain.insert(MainChain.begin() + found, SubChain.begin() + adjdx * pre_size, SubChain.begin() + adjdx * pre_size + pre_size);
            SubChain.erase(SubChain.begin() + adjdx * pre_size, SubChain.begin() + adjdx * pre_size + pre_size);
            // show(MainChain, "바이너리 후 Main");
            // show(SubChain, "바이너리 후 Sub");
            ++cnt;
            Jacob[idx]--;
        }
        idx++;
    }
    while (SubChain.size()) {
        found = BinarySearch(MainChain, *(SubChain.end() - pre_size), pre_size);
        MainChain.insert(MainChain.begin() + found, SubChain.end() - pre_size, SubChain.end());
        SubChain.erase(SubChain.end() - pre_size, SubChain.end());
    }
    // show(MainChain, "반복 결과 Main");
    // show(SubChain, "반복 결과 Sub");
}