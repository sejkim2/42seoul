NAME = ex01
CC = c++
HEADER = Span.hpp
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = main.cpp \
	Span.cpp

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