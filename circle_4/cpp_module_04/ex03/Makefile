NAME = ex01
CC = c++
HEADER = AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp Character.hpp IMateriaSource.hpp MateriaSource.hpp
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = AMateria.cpp \
		Ice.cpp \
		Cure.cpp \
		MateriaSource.cpp \
		Character.cpp \
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