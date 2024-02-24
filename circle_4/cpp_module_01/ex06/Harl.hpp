#ifndef _HARL
# define _HARL

# include <iostream>
# include <string>

class Harl
{
    public:
        Harl();
        void complain(std::string level);
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
        std::string levels[4];
};

#endif