# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/18 16:49:25 by dlanotte          #+#    #+#              #
#    Updated: 2021/03/24 20:23:29 by dlanotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# -*- Makefile Bello -*-

NAME = cub3D
ENGINE = engine/
MOVEMENT = movement/
GNL =	get_next_line/
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ${wildcard *.c} $(wildcard $(ENGINE)*.c) $(wildcard $(GNL)*.c) $(wildcard $(MOVEMENT)*.c)
OBJS =  $(SRCS:.c=.o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
debug: 
	$(CC) $(CFLAGS) -g $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
bau: 
	$(CC) -g $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
clean:
	rm -f ${OBJ} ${OBJL} ${OBJG}
fclean: clean
	rm -f $(NAME)