# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 16:27:04 by sejkim2           #+#    #+#              #
#    Updated: 2023/08/21 19:02:10 by sejkim2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
C_FLAGS = -Wall -Werror -Wextra

SRCS = srcs/main.c
HEADER = includes/philo.h
SRCS_BONUS =

OBJS = $(SRCS:%.c=%.o)
NAME = philo

ifdef BONUS
	SRC = $(SRCS_BONUS)
	OBJ = $(SRC:%.c=%.o)
else
	OBJ = $(OBJS)
	SRC = $(SRCS)
endif

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(C_FLAGS) $(SRC) -o $@

bonus:
	make BONUS=1

clean :
	rm -rf $(SRCS:%.c=%.o) $(SRCS_BONUS:%.c=%.o)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re