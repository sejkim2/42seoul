NAME = ex03
CC = c++
HEADER = HumanA.hpp HumanB.hpp Weapon.hpp
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = HumanA.cpp \
	HumanB.cpp \
	main.cpp \
	Weapon.cpp

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