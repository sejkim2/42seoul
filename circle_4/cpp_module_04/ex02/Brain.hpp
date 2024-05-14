#ifndef _BRAIN
# define _BRAIN

# include <iostream>
# include <string>
# define IDEASIZE 10

class Brain
{
    public:
        /*canonical form*/
        Brain(void);
        ~Brain(void);
        Brain(const Brain& brain);
        Brain& operator=(const Brain& brain);

        Brain(std::string idea);
        std::string getIdeas(int index) const;
        
    private:
        std::string ideas[IDEASIZE];
};

#endif