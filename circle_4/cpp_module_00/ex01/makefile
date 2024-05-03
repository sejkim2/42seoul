NAME = phonebook
CC = c++
HEADER = Contact.hpp PhoneBook.hpp
C_FLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic

SRC = PhoneBook.cpp \
		main.cpp \
		Contact.cpp \
		MyIostream.cpp

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