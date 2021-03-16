# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 16:49:25 by dlanotte          #+#    #+#              #
#    Updated: 2021/03/16 16:06:28 by dlanotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile Bello -*-

NAME = cub3D
ENGINE =	engine/
GNL =	get_next_line/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ${wildcard *.c}
SRCL = 	$(wildcard $(ENGINE)*.c)
SRCG = 	$(wildcard $(GNL)*.c)
OBJ := ${SRC:.c=.o}
OBJL := $(SRCL:.c=.o)
OBJG := $(SRCG:.c=.o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRC) $(SRCL) $(SRCG) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
debug: 
	$(CC) $(CFLAGS) -g $(SRC) $(SRCL) $(SRCG) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
bau: 
	$(CC) -g $(SRC) $(SRCL) $(SRCG) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
	rm -f ${OBJ} ${OBJL} ${OBJG}
fclean: clean
	rm -f $(NAME)