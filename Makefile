# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 14:19:58 by dlanotte          #+#    #+#              #
#    Updated: 2021/04/14 21:06:26 by zxcvbinz         ###   ########.fr        #
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
SCREENSHOT = screenshot/
GNL =	get_next_line/
CC = gcc
LIB = libmlx.dylib
CFLAGS = -Wall -Wextra -Werror
SRCS = ${wildcard *.c} $(wildcard $(ENGINE)*.c) $(wildcard $(GNL)*.c) $(wildcard $(MOVEMENT)*.c) $(wildcard $(SETTINGS)*.c) $(wildcard $(SCREENSHOT)*.c)
OBJS =  $(SRCS:.c=.o)
%.o: %.c
	@ $(CC) $(CFLAGS) -Imlx -c $< -o $@
$(NAME): $(OBJS)
	@ echo "Building the project..."
	@ make -s -C mlx
	@ mv mlx/${LIB} .
	@ $(CC) -Lmlx  ${LIB} -framework OpenGL -framework AppKit $(OBJS) -o $(NAME)
	@ echo  "\nBuilding" ${GREEN} "[OK]"
	@ make clean
	@ echo ${COLOR_OFF} "\nDeleted *.o files" ${GREEN} "[OK]\n" 
	@ ./cub3D maps/map.cub 
clean:
	@ rm -f ${OBJS}
	@ make clean -C mlx 
fclean: clean
	@ rm -f ${LIB}
	@ rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
