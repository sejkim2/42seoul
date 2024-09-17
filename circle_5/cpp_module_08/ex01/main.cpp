#include "Span.hpp"
#include "vector"

int main()
{
    {
        std::cout << "test 1" << '\n';
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }

    {
        std::cout << "test 2" << '\n';
        Span sp = Span(5);
        try {
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            sp.addNumber(14);
        }
        catch (std::exception& e) {
            std::cerr << "Exception : " << e.what() << '\n';
        }
    }

    {
        std::cout << "test 3" << '\n';
        Span sp = Span(4);
        std::vector<int> v;

        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(5);
        v.push_back(67);
        try {
            sp.addNumbers(v.begin(), v.end(), v.size());
        } catch(std::exception& e) {
            std::cerr << "Exception : " << e.what() << '\n';
        }
    }

    {
        std::cout << "test 4" << '\n';
        Span sp = Span(5);
        sp.addNumber(14);
        try {
            std::cout << sp.shortestSpan() << '\n';
        }
        catch (std::exception& e) {
            std::cerr << "Exception : " << e.what() << '\n';
        }
    }
}