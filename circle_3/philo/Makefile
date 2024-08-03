# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 16:27:04 by sejkim2           #+#    #+#              #
#    Updated: 2024/01/23 15:35:12 by sejkim2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
C_FLAGS = -Wall -Werror -Wextra -I$(HEADER)
HEADER = includes
PHILO_DIR = srcs

PHILO_SRCS = main.c \
	parse_argument.c \
	philo_utils.c \
	init_philosophers.c \
	init_shared_info.c \
	run_simulation.c \
	philo_message.c \
	thread_function.c \
	run_eating.c \
	run_sleeping.c \
	run_thinking.c \
	checking_is_die.c

SRCS = $(addprefix $(PHILO_DIR)/,$(PHILO_SRCS))

OBJS = $(SRCS:.c=.o)

%.o : %.c $(HEADER)
	$(CC) $(C_FLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(C_FLAGS) $(SRCS) -o $@

all : $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re