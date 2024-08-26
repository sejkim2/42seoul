NAME = ex01
CC = c++
HEADER = Serializer.hpp Data.hpp
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = Serializer.cpp \
	Data.cpp \
	main.cpp

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