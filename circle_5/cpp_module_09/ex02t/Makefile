NAME = PmergeMe
CPP = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp PmergeMe.cpp PmergeMeUtils.cpp PmergeMeVector.cpp PmergeMeList.cpp PmergeMeJacobsthal.cpp
OBJS = $(SRCS:.cpp=.o)

%.o : %.cpp %.hpp
	$(CPP) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME) : $(OBJS)
	$(CPP) $(CXXFLAGS) -o $@ $(OBJS)

clean:
	rm -rf $(OBJS)

fclean:
	$(MAKE) clean
	rm -rf $(NAME)

re:
	$(MAKE) fclean 
	$(MAKE) all

.PHONY: all clean fclean re