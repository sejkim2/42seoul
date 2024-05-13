NAME = ex01
CC = c++
HEADER = AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp
CXXFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = AMateria.cpp \
		Ice.cpp \
		Cure.cpp \
		ICharacter.cpp \
		IMateriaSource.cpp \ 
		MateriaSource.cpp

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