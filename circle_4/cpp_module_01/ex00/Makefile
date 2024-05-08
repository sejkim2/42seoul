NAME = ex00
CC = c++
HEADERS = Zombie.hpp
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp \
	newZombie.cpp \
	randomChump.cpp \
	Zombie.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME) : $(OBJ) $(HEADERS)
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