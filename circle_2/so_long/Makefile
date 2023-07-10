# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/05 16:27:04 by sejkim2           #+#    #+#              #
#    Updated: 2023/06/27 15:21:22 by sejkim2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
C_FLAGS = -Wall -Werror -Wextra
SRCS = \
srcs/main.c \
srcs/make_map.c \
srcs/run_window.c \
srcs/move_map.c \
srcs/check_error.c \
srcs/print_error_message.c \
srcs/free_memory.c \
srcs/init_game_object.c \
srcs/dfs.c \
srcs/move_map_utils.c \
srcs/so_long_utils.c
OBJS = $(SRCS:%.c=%.o)
MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
NAME = so_long

all : $(NAME)

$(NAME) : $(OBJS)
	make -C ./mylib
	make -C ./mlx
	$(CC) $(C_FLAGS) $(MLX_FLAGS) $(SRCS) -o $@ mylib/mylib.a
	install_name_tool -change libmlx.dylib mlx/libmlx.dylib $@

clean :
	make clean -C ./mylib
	rm -rf $(OBJS)

fclean : clean
	make clean -C ./mlx
	make fclean -C ./mylib
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re 