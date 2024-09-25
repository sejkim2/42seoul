#include "PmergeMe.hpp"
#include <ctime>   

bool allUnique(const std::vector<int>& numbers, std::set<int>& sortedNumbers) 
{
    for (std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); ++it) {
        if (sortedNumbers.find(*it) != sortedNumbers.end()) {
            return false;
        }
        sortedNumbers.insert(*it);
    }

    return true;
}

bool stringToPositiveInt(const std::string& str, int& number) 
{
    std::istringstream iss(str);
    char c;

    if (iss >> number)
        return (number > 0) && !(iss >> c);
    return false;
}

void printNumbersBeforeSort(const std::vector<int>& numbers)
{
    std::cout << "Before: ";
    for(std::vector<int>::const_iterator it = numbers.begin(); it != numbers.end(); it++)
        std::cout << *it << ' ';
    std::cout << '\n';
}

template <typename T>
void printNumbersAfterSort(const T& numbers)
{
    std::cout << "After: ";
    for(typename T::const_iterator it = numbers.begin(); it != numbers.end(); it++)
        std::cout << *it << ' ';
    std::cout << '\n';
}

template <typename T>
bool isSorted(const T& numbers, const std::set<int>& sortedNumbers)
{
    if (numbers.size() != sortedNumbers.size())
        return (false);
    
    std::vector<int> set2Vector(sortedNumbers.begin(), sortedNumbers.end());
    return (numbers == set2Vector);
}

int main(int argc, char* argv[])
{
    if (argc < 2) 
    {
        std::cout << "Invalid Argument" << '\n';
        return 1;
    }

    std::vector<int> numbers;
    std::list<int> list;
    std::set<int> sortedNumbers;
    
    for (int i = 1; i < argc; ++i)
    {
        int number;

        if (!stringToPositiveInt(argv[i], number)) 
        {
            std::cout << "There are not invalid integer" << '\n';
            return 1;
        }
        numbers.push_back(number);
        list.push_back(number);
    }

    if (!allUnique(numbers, sortedNumbers))
        std::cout << "There are duplicate numbers" << '\n';
    else
    {
        printNumbersBeforeSort(numbers);
        PmergeMe pm;
        std::clock_t start;
        std::clock_t end;
        double elapsed_time;
        
        start = std::clock();
        std::vector<int> sorted_vector = pm.ford_johnson_by_vector(numbers);
        end = std::clock();
        elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1e6;
        std::cout << "Time to process a range of " << sorted_vector.size() << " elements with std::vector: " << elapsed_time << " us" << '\n';

        start = std::clock();
        std::list<int> sorted_list = pm.ford_johnson_by_list(list);
        end = std::clock();
        elapsed_time = double(end - start) / CLOCKS_PER_SEC * 1e6;
        std::cout << "Time to process a range of " << sorted_list.size() << " elements with std::list: " << elapsed_time << " us" << '\n';

        // printNumbersAfterSort(sorted_vector);
        // printNumbersAfterSort(sorted_list);
    }

    return 0;
}
