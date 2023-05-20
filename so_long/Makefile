CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = test.c
OBJS = $(SRCS:%.c=%.o)
CLIB = -Lmlx -lmlx -framework OpenGL -framework Appkit -Imlx
NAME = a.out

all : $(NAME)

%.o.o : 
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(CLIB) $(SRCS) -o $@
#install_name_tool -change libmlx.dylib mlx/libmlx.dylib $@

clean : 
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re :
	make fclean
	make all
