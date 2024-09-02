#ifndef _DATA_HPP__
# define _DATA_HPP__

# include <iostream>

class Data
{
    public:
        Data(void);
        ~Data(void);
        Data(const Data& copy);
        Data& operator=(const Data& obj);
        
        Data(std::string str);
    private:
        std::string data_member;
};

#endif