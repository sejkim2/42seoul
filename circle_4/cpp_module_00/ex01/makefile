# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 16:27:04 by sejkim2           #+#    #+#              #
#    Updated: 2024/02/14 21:28:38 by sejkim2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CC = g++
HEADER = Contact.hpp PhoneBook.hpp
C_FLAGS = -Wall -Werror -Wextra -std=c++98

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