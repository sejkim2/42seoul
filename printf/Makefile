# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sejkim2 <sejkim2@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/02 14:09:42 by sejkim2           #+#    #+#              #
#    Updated: 2023/04/03 14:39:19 by sejkim2          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf_conversions.c \
ft_printf_c.c \
ft_printf_s.c \
ft_printf_p.c \
ft_printf_d_i.c \
ft_printf_u.c \
ft_printf_x.c \
ft_printf.c \
ft_putnbr_base.c \
ft_strlen.c

OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
INC = ft_printf.h

all: $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re:
	make fclean
	make all

.PHONY: all bonus clean fclean re
