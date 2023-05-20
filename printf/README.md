<!-- 라이브러리 불러오기 -->
<!-- 실행 시 라이브러리도 같이 컴파일 -->

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
ft_putnbr_base.c

OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
INC = ft_printf.h

all: $(NAME)

$(NAME) : $(OBJS)
    make -C ./libft
    cp ./libft/libft.a $(NAME)
    ar rcs $(NAME) $(OBJS)

.c.o:
    $(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

clean:
    make clean -C ./libft
    rm -rf $(OBJS)

fclean: clean
    make fclean -C ./libft
    rm -rf $(NAME)

re:
    make fclean
    make all

.PHONY: all bonus clean fclean re
