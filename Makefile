# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/22 14:19:58 by dlanotte          #+#    #+#              #
#    Updated: 2021/04/17 18:24:08 by dlanotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COLOR_OFF   = "\033[0m"       # Text Reset
GREEN       = "\033[0;32m"        # Green
WHITE       = "\033[0;37m"        # White
#-*-*-*-*--*-*- Makefile -*-*-*-*--*-*-
# ▄████▄      █    ██     ▄▄▄▄        █████▓    ▓█████▄ 
#▒██▀ ▀█      ██  ▓██▒   ▓█████▄      ▀   █▓    ▒██▀ ██▌
#▒▓█    ▄    ▓██  ▒██░   ▒██▒ ▄██       ███▒    ░██   █▌
#▒▓▓▄ ▄██▒   ▓▓█  ░██░   ▒██░█▀       ▄  █▓▒    ░▓█▄   ▌
#▒ ▓███▀ ░   ▒▒█████▓    ░▓█  ▀█▓    ▒████▒░    ░▒████▓ 
#░ ░▒ ▒  ░   ░▒▓▒ ▒ ▒    ░▒▓███▀▒    ░ ░▒ ░░     ▒▒▓  ▒ 
#  ░  ▒      ░░▒░ ░ ░    ▒░▒   ░     ░  ░ ░      ░ ▒  ▒ 
#░            ░░░ ░ ░     ░    ░       ░        
#░ ░     by      ░        ░ dlanotte░  ░        
#░                             ░          
#-*-*-*-*--*-*- Makefile -*-*-*-*--*-*-

NAME = cub3D
ENGINE = engine/engine_base_extra.c \
		 engine/engine_base00.c \
		 engine/engine_base02.c \
		 engine/engine_base03.c \
		 engine/engine_texture00.c
		 
SETTINGS = settings/ft_libft_functions00.c \
		   settings/ft_libft_functions01.c \
		   settings/ft_parsing00.c \
		   settings/ft_parsing01.c \
		   settings/ft_parsing02.c \
		   settings/ft_parsing03.c \
		   settings/ft_player_settings.c \
		   settings/ft_split_files.c \
		   settings/settings.c \
		   settings/check_config.c

MOVEMENT = movement/ft_movement.c \
		   movement/ft_button.c

SCREENSHOT = screenshot/ft_bitmap.c

GNL =	get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c
		
CC = gcc
LIB = libmlx.dylib
CFLAGS = -Wall -Wextra -Werror
SRCS = cub3d_main.c $(ENGINE) $(GNL) $(MOVEMENT) $(SETTINGS) $(SCREENSHOT)
SRCSB = bonus/bonus_engine.c
SRCSS = engine/engine_base01.c
OBJS =  $(SRCS:.c=.o)
OBJSS = $(SRCSS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@
	
$(NAME): $(OBJS) $(OBJSS)
	@ sed -n 17,26p Makefile | cut -c 2-;
	@ echo "\nBuilding the project..."
	@ make -s -C mlx
	@ mv mlx/${LIB} .
	@ $(CC) -Lmlx  ${LIB} -framework OpenGL -framework AppKit $(OBJS) $(OBJSS) -o $(NAME)
	@ echo  "\nBuilding" ${GREEN} "[OK]"
	@ make clean
	@ echo ${COLOR_OFF} "\nDeleted *.o files" ${GREEN} "[OK]\n" 
	@ ./cub3D maps/map.cub
	
debug:
	@ sed -n 17,26p Makefile | cut -c 2-;
	@ echo "\nBuilding the bonus project..."
	@ make -s -C mlx
	@ mv mlx/${LIB} .
	@ $(CC) -Lmlx -g ${LIB} -framework OpenGL -framework AppKit $(SRCS) $(SRCSS) -o $(NAME)
clean:
	@ rm -f ${OBJS} ${OBJSB} $(OBJSS)
	@ make clean -C mlx 
	
fclean: clean
	@ rm -f ${LIB}
	@ rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re