#ifndef _UTILS_HPP__
# define _UTILS_HPP__

# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"
# include <ctime>
# include <unistd.h>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif