#ifndef _BRAIN
# define _BRAIN

# include <iostream>
# include <string>

class Brain
{
    public:
        /*canonical form*/
        Brain(void);
        ~Brain(void);
        Brain(const Brain& brain);
        Brain& operator=(const Brain& brain);

        Brain(std::string idea);

    private:
        std::string ideas[100];
};

#endif