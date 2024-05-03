NAME = megaphone
CC = c++
C_FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

SRC = megaphone.cpp

OBJ = $(SRC:.cpp=.o)

$(NAME) : $(OBJ)
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