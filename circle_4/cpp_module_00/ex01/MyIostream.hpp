#ifndef _MYIO
# define _MYIO

# include <iostream>
# include <cstdlib>
# define BUF_SIZE 1024

class MyIostream
{
    public:
        static void    ioError();
};

#endif