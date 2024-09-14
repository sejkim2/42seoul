#include "Data.hpp"

Data::Data(void)
{
    // std::cout << "Data Default Constructor Called" << '\n';
}

Data::~Data(void)
{
    // std::cout << "Data Default Destructor Called" << '\n';
}

Data::Data(const Data& copy)
{
    *this = copy;
}

Data& Data::operator=(const Data& obj)
{
    if (&obj != this)
    {
        this->data_member = obj.getDataMember();
    }
    return (*this);
}

const std::string& Data::getDataMember(void) const
{
    return (this->data_member);
}

Data::Data(std::string str)
{
    this->data_member = str;
}
