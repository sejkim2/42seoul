NAME = ex01
CC = clang++
HEADER = Fixed.hpp
C_FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp \
	Fixed.cpp

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