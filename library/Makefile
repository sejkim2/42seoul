# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 16:27:04 by sejkim2           #+#    #+#              #
#    Updated: 2023/08/02 11:49:58 by sejkim2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
C_FLAGS = -Wall -Werror -Wextra

SRCS = 
HEADER = 
SRCS_BONUS =

OBJS = $(SRCS:%.c=%.o)
NAME = a.out

ifdef BONUS
	SRC = $(SRCS_BONUS)
	OBJ = $(SRC:%.c=%.o)
else
	OBJ = $(OBJS)
	SRC = $(SRCS)
endif

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	make -C ./mylib
	$(CC) $(C_FLAGS) $(SRC) -o $@ mylib/mylib.a

bonus:
	make BONUS=1

clean :
	make clean -C ./mylib
	rm -rf $(SRCS:%.c=%.o) $(SRCS_BONUS:%.c=%.o)

fclean : clean
	make fclean -C ./mylib
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re