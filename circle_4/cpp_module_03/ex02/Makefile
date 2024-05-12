NAME = ex01
CC = c++
HEADER = ClapTrap.hpp FragTrap.hpp
CXXFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

SRC = main.cpp \
	ClapTrap.cpp \
	FragTrap.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(CXXFLAGS) $(SRC) -o $@

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re