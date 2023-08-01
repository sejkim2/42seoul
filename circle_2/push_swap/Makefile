# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 16:27:04 by sejkim2           #+#    #+#              #
#    Updated: 2023/07/26 13:08:48 by sejkim2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
C_FLAGS = -Wall -Werror -Wextra
SRCS = \
srcs/main.c \
srcs/parsing_argument.c \
srcs/change_string_to_num_utils.c \
srcs/change_string_to_num.c \
srcs/check_integer_and_duplicate.c \
srcs/stack_utils.c \
srcs/push_swap_command_pa_pb.c \
srcs/push_swap_command_ra_rb_rr.c \
srcs/push_swap_command_rra_rrb_rrr.c \
srcs/push_swap_command_sa_sb_ss.c \
srcs/move_a_to_b.c \
srcs/sorting_if_size_is_three_utils.c \
srcs/move_b_to_a.c \
srcs/rb_and_ra.c \
srcs/rb_and_rra.c \
srcs/rrb_and_ra.c \
srcs/rrb_and_rra.c \
srcs/sorting.c \
srcs/run_push_swap.c \
srcs/sorting_utils.c

SRCS_BONUS = \
bonus_srcs/main_bonus.c \
bonus_srcs/parsing_argument_bonus.c \
bonus_srcs/change_string_to_num_utils_bonus.c \
bonus_srcs/change_string_to_num_bonus.c \
bonus_srcs/check_integer_and_duplicate_bonus.c \
bonus_srcs/stack_utils_bonus.c \
bonus_srcs/push_swap_command_pa_pb_bonus.c \
bonus_srcs/push_swap_command_ra_rb_rr_bonus.c \
bonus_srcs/push_swap_command_rra_rrb_rrr_bonus.c \
bonus_srcs/push_swap_command_sa_sb_ss_bonus.c \
bonus_srcs/sorting_bonus.c \
bonus_srcs/run_push_swap_bonus.c

OBJS = $(SRCS:%.c=%.o)
NAME = push_swap

ifdef BONUS
	SRC = $(SRCS_BONUS)
	OBJ = $(SRC:%.c=%.o)
	NAME = checker
else
	OBJ = $(OBJS)
	SRC = $(SRCS)
endif

all : $(NAME)

$(NAME) : $(OBJ)
	make -C ./mylib
	$(CC) $(C_FLAGS) $(SRC) -o $@ mylib/mylib.a

bonus:
	make BONUS=1

clean :
	make clean -C ./mylib
	rm -rf $(SRCS:%.c=%.o) $(SRCS_BONUS:%.c=%.o)

fclean : clean
	make fclean -C ./mylib
	rm -rf $(NAME) checker

re :
	make fclean
	make all

.PHONY : all bonus clean fclean re