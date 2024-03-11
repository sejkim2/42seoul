#ifndef _MYSTREAM_HPP
# define _MYSTREAM_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <cstring>

class MyStream
{
    public:
        MyStream(char **argv);
        void setOrigin();
        void replaceString();
        bool    getOpenSucces();
    private:
        std::ifstream in;
        std::ofstream out;
        std::string outfile_name;
        std::string origin;
        char **argv;
        bool    openSuccess;
};

#endif
