# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 16:27:04 by sejkim2           #+#    #+#              #
#    Updated: 2023/08/18 18:24:13 by sejkim2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
C_FLAGS = -Wall -Werror -Wextra

SRCS = srcs/main.c \
srcs/parsing_cmd_and_check_heredoc.c \
srcs/init_path_env.c \
srcs/run_pipex.c \
srcs/parent_process.c \
srcs/child_process.c \
srcs/free.c

SRCS_BONUS = srcs_bonus/main_bonus.c \
srcs_bonus/parsing_cmd_and_check_heredoc_bonus.c \
srcs_bonus/init_path_env_bonus.c \
srcs_bonus/run_pipex_bonus.c \
srcs_bonus/parent_process_bonus.c \
srcs_bonus/child_process_bonus.c \
srcs_bonus/free_bonus.c

NAME = pipex

ifdef BONUS
	SRC = $(SRCS_BONUS)
	OBJ = $(SRCS_BONUS:%.c=%.o)
	HEADER = includes/pipex_bonus.h
else
	SRC = $(SRCS)
	OBJ = $(SRCS:%.c=%.o)
	HEADER = includes/pipex.h
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