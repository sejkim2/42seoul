NAME = ex01
CC = c++
HEADER = AMateria.hpp Ice.hpp Cure.hpp ICharacter.hpp IMateriaSource.hpp MateriaSource.hpp
C_FLAGS = -Wall -Werror -Wextra -std=c++98

SRC = AMateria.cpp \
		Ice.cpp \
		Cure.cpp \
		ICharacter.cpp \
		IMateriaSource.cpp \ 
		MateriaSource.cpp

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