#ifndef _RPN_HPP__
# define _RPN_HPP__

# include <iostream>
# include <sstream>
# include <stack>

class Rpn
{
    public:
        ~Rpn(void);
        Rpn(const Rpn& copy);
        Rpn& operator=(const Rpn& obj);
    
        Rpn(std::string str);
        void calculation();

        static const int MAX_INT = 2147483647;
        static const int MIN_INT = -2147483648;

    private:
        Rpn(void);
        std::string expression;

};

#endif
