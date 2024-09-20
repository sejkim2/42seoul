#include "easyfind.hpp"

int main(void)
{
    {
        std::cout << "test 1 : ";
        std::vector<int> v;

        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(20);
        v.push_back(10);

        try
        {
            std::vector<int>::iterator it = easyfind(v, 20);
            std::cout << *it << " is find" << '\n';
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << "test 2 : ";
        std::vector<float> v;

        v.push_back(10.2);
        v.push_back(20.6);
        v.push_back(30.0);
        v.push_back(20.23);
        v.push_back(10.2);

        try
        {
            std::vector<float>::iterator it = easyfind(v, 20);
            std::cout << *it << " is find" << '\n';
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << "test 3 : ";
        std::list<int> v;

        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(20);
        v.push_back(10);

        try
        {
            std::list<int>::iterator it = easyfind(v, 20);
            std::cout << *it << " is find" << '\n';
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    } 

    {
        std::cout << "test 4 : ";
        std::deque<int> v;

        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(20);
        v.push_back(10);

        try
        {
            std::deque<int>::iterator it = easyfind(v, 20);
            std::cout << *it << " is find" << '\n';
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    }

    {
        std::cout << "test 5 : ";
        std::vector<int> v;

        v.push_back(10);
        v.push_back(20);
        v.push_back(30);
        v.push_back(20);
        v.push_back(10);

        const std::vector<int> const_v(v.begin(), v.end());

        try
        {
            std::vector<int>::iterator it = easyfind(v, 20);
            std::cout << *it << " is find" << '\n';
        }
        catch (std::exception &e)
        {
            std::cerr << e.what() << '\n';
        }
    } 
}