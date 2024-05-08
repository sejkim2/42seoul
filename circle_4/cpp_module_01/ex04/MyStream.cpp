#include "MyStream.hpp"

MyStream::MyStream(char **argv) : in(argv[1]), out((std::string(argv[1]) + ".replace").c_str())
{
    this->argv = argv;
    openSuccess = in.is_open();
}

void MyStream::setOrigin()
{
    std::string s;

    while (in)
    {
        getline(in, s);
        origin.append(s);
        if (in.eof())
            break ;
        origin.append("\n");
    }
}

void MyStream::replaceString()
{
    int find_index = 0;
    std::string new_string;
    std::string argv_2 = argv[2];
    std::string argv_3 = argv[3];

    while (find_index < (int)origin.length())
    {
        int pos = origin.find(argv_2, find_index);
        if (pos != (int)std::string::npos)
        {
            new_string += origin.substr(find_index, pos - find_index);
            new_string += argv_3;
            find_index = pos + argv_2.length();
        }
        else
        {
            new_string += origin.substr(find_index);
            break;
        }
    }
    out << new_string;
}

bool    MyStream::getOpenSucces()
{
    return (openSuccess);
}
