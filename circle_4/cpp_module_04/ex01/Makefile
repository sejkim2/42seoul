NAME = ex01
CC = c++
HEADER = Animal.hpp Cat.hpp Dog.hpp Brain.hpp
# CXXFLAGS = -Wall -Werror -Wextra -std=c++98
CXXFLAGS = -std=c++98

SRC = main.cpp \
	Animal.cpp \
	Cat.cpp \
	Dog.cpp \
	Brain.cpp

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