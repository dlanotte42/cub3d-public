NAME = cub3D
LIBFT =	libft/
GNL =	get_next_line/
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
SRC =	main.c \
		map.c \
		engine.c \
		raycasting.c \
SRCL = 	$(wildcard $(LIBFT)*.c)
SRCG = 	$(wildcard $(GNL)*.c)
OBJ := ${SRC:.c=.o}
OBJL := $(SRCL:.c=.o)
OBJG := $(SRCG:.c=.o)
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(SRCL) $(SRCG) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
	make clean -C $(LIBFT)
	rm -f ${OBJ} ${OBJL} ${OBJG}
fclean: clean
	make fclean -C $(LIBFT)
	rm -f $(NAME)