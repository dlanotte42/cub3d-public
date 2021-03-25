# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 14:19:58 by dlanotte          #+#    #+#              #
#    Updated: 2021/03/25 00:05:40 by zxcvbinz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_OFF   = "\033[0m"       # Text Reset
GREEN       = "\033[0;32m"        # Green
WHITE       = "\033[0;37m"        # White
#-*-*-*-*--*-*- Makefile -*-*-*-*--*-*-

NAME = cub3D
ENGINE = engine/
SETTINGS = settings/
MOVEMENT = movement/
GNL =	get_next_line/
CC = gcc
LIB = libmlx.dylib
CFLAGS = -Wall -Wextra -Werror
SRCS = ${wildcard *.c} $(wildcard $(ENGINE)*.c) $(wildcard $(GNL)*.c) $(wildcard $(MOVEMENT)*.c) $(wildcard $(SETTINGS)*.c)
OBJS =  $(SRCS:.c=.o)
%.o: %.c
	@ $(CC) $(CFLAGS) -Imlx -c $< -o $@
$(NAME): $(OBJS)
	@ echo "Building the project..."
	@ make -s -C mlx
	@ mv mlx/${LIB} .
	@ $(CC) $(CFLAGS) -Lmlx  ${LIB} -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)
	@ echo  "\nBuilding" ${GREEN} "[OK]"
	@ make clean
	@ echo ${COLOR_OFF} "\nDeleted *.o files" ${GREEN} "[OK]\n" 
	@ ./cub3D
debug: 
	@ $(CC) $(CFLAGS) -g $(SRCS) -Lmlx -lmlx ${LIB} -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)
clean:
	@ rm -f ${OBJS}
	@ make clean -C mlx 
fclean: clean
	@ rm -f ${LIB}
	@ rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re debug
