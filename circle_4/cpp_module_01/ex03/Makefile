NAME = ex03
CC = g++
HEADER = HumanA.hpp HumanB.hpp Weapon.hpp
C_FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = Human.cpp \
	HumanA.cpp \
	HumanB.cpp \
	main.cpp \
	Weapon.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(C_FLAGS) $(SRC) -o $@

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re