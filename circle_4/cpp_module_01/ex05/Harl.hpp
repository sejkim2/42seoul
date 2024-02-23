#ifndef _HARL
# define _HARL

# include <iostream>
# include <string>

const std::string DEBUG = "DEBUG";
const std::string INFO = "INFO";
const std::string WARNING = "WARNING";
const std::string ERROR = "ERROR";

class Harl
{
    private:
        void debug( void );
        void info( void );
        void warning( void );
        void error( void );
    public:
        void complain(std::string level);
};

#endif