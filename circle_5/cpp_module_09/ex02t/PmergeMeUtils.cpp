#include "PmergeMe.hpp"

void PmergeMe::ProcessError(const std::string &errorStr)
{
    std::cout << errorStr << std::endl;
    std::exit(1);
}

void PmergeMe::IsDecimal(const std::string token)
{
    if (token.size() == 0)
        ProcessError("Argument Error");
    for (size_t idx = 0; idx < token.length(); ++idx)
        if (!std::isdigit(token[idx]))
            ProcessError("\"" + token + "\" is not a positive number");
}

void PmergeMe::CheckArgumentsValidity(int argc, char *argv[])
{
    if (argc == 1)
        ProcessError("Argument Error");
    for (int idx = 1; idx < argc; ++idx)
        IsDecimal(argv[idx]);
}

int PmergeMe::ft_atoi(const std::string &str)
{
    long inum = 0;
    size_t idx = 0;

    while (std::isdigit(str[idx]))
    {
        inum *= 10;
        inum += str[idx] - '0';
        if (inum > INT_MAX || inum < INT_MIN)
            return -1;
        ++idx;
    }
    return static_cast<int>(inum);
}

void PmergeMe::InsertToContainers(int value)
{
    std::vector<int>::iterator it = std::find(vec.begin(), vec.end(), value);
    if (it == vec.end())
    {
        vec.push_back(value);
        lst.push_back(value);
    }
    // else
    //     processError("duplicated number");
}

void PmergeMe::ShowStatusContainer(const std::string &status)
{
    std::cout << status << std::endl;
    std::cout << "Vector:   ";
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
    std::cout << "List:     ";
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::ShowTime()
{
    std::cout << std::fixed << std::setprecision(5);
    std::cout   << "Time to process a range of " \
                << vec.size() \
                << " elements with std::vector : " \
                << _vecSortTime
                << " ms\n";
    std::cout   << "Time to process a range of " \
                << lst.size() \
                << " elements with std::list : " \
                << _lstSortTime
                << " ms\n";
}
