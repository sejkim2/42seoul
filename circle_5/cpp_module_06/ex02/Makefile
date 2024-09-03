NAME = ex02
CC = c++
HEADER = Base.hpp A.hpp B.hpp C.hpp Utils.hpp
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = Base.cpp \
	A.cpp \
	B.cpp \
	C.cpp \
	Utils.cpp \
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