#include "Span.hpp"
#include "vector"

int main()
{
    {
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
        Span sp = Span(5);
        try {
            sp.addNumber(6);
            sp.addNumber(3);
            sp.addNumber(17);
            sp.addNumber(9);
            sp.addNumber(11);
            sp.addNumber(14);
        }
        catch (std::overflow_error& e) {
            std::cerr << "Exception : " << e.what() << '\n';
        }
        try {
            std::cout << sp.shortestSpan() << std::endl;
            std::cout << sp.longestSpan() << std::endl;
        } catch(std::logic_error& e) {
            std::cerr << "Exception : " << e.what() << '\n';
        }
    }

    {
        Span sp = Span(5);
        std::vector<int> v;

        v.push_back(1);
        v.push_back(2);
        v.push_back(3);
        v.push_back(5);
        v.push_back(67);
        try {
            sp.addNumbers(v.begin(), v.end(), v.size());
        } catch(std::overflow_error& e) {
            std::cerr << "Exception : " << e.what() << '\n';
        }
    }
}