#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#define INITSIZE 1
#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <ctime>
#include <iomanip>
#include <algorithm>

class PmergeMe
{
    private:
        //  OCF
        PmergeMe();
        PmergeMe(const PmergeMe &ref);
        PmergeMe &operator=(const PmergeMe &ref);

        //  Time
        double _vecSortTime;
        double _lstSortTime;
    
        std::vector<int> vec;
        std::list<int> lst;

    public:
        //  OCF
        PmergeMe(char *argv[]);
        ~PmergeMe();

        //  Check Utils
        static void CheckArgumentsValidity(int argc, char *argv[]);
        static void IsDecimal(const std::string token);
        static void ProcessError(const std::string &errorStr);

        //  Utils
        int ft_atoi(const std::string &str);
        void InsertToContainers(int value);
        void ShowStatusContainer(const std::string &status);
        void ShowTime();

        //  Algorithm
        void FordJohnsonAlgorithm();
        size_t Jacobsthal(int num);
        int GetJacobsthalLimit(std::vector<int> Jacob, size_t idx);
        void GetJacobsthal(std::vector<int> &Jacob, size_t JacobSize);
        //  Vector
        void MergeInsertionSortVector(size_t pre_size);
        void GroupMainSubChain(std::vector<int> &MainChain, std::vector<int> &SubChain, size_t pre_size);
        int BinarySearch(std::vector<int> MainChain, int target, size_t size);
        void BinarySearchInsertion(std::vector<int> &MainChain, std::vector<int> &SubChain, std::vector<int> &Jacob, size_t pre_size);
        //  List
        void MergeInsertionSortList(size_t pre_size);
        void GroupMainSubChain(std::list<int> &MainChain, std::list<int> &SubChain, size_t pre_size);
        int BinarySearch(std::list<int> MainChain, int target, size_t size);
        void BinarySearchInsertion(std::list<int> &MainChain, std::list<int> &SubChain, std::vector<int> &Jacob, size_t pre_size);
        //  List Jacobsthal
        template <typename T>
        void show(T _con, std::string _name)
        {
            std::cout << _name + " : ";
            for (typename T::iterator it = _con.begin(); it != _con.end(); ++it)
                std::cout << *it << " ";
            std::cout << std::endl;
        }
};

#endif