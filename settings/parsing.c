/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:53:45 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/03 00:59:10 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int 	ft_check_file(char *file)
{
	while(*file)
	{
		if(*file == '.')
		{
			file++;
			if(*file == 'c')
			{
				file++;
				if(*file == 'u')
				{
					file++;
					if(*file == 'b')
					{
						file++;
						if(*file == 0)
							return (1);
					}
				
				}
			}
		}
		file++;
	}
	return (0);
}

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t			i;

	i = 0;
	while ((((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			&& (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		return ((int)(((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
	else
		return (0);
}

void	config_init(t_config *config)
{
	config->ris_x = 1920;
	config->ris_y = 1080;
	config->c_color = 0x89F1F1;
	config->f_color = 0xBABBBB;
	config->n_wall = "../textures/mariowall1.xpm";
}

void	check_floor(char **array, t_config *config)
{
	int r;
	int g;
	int b;
	unsigned long color;
	char **array2;

	array2 = ft_split(config->array[1], ',');
	r = ft_atoi(array2[0]);
	g = ft_atoi(array2[1]);
	b = ft_atoi(array2[2]);
	color = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	config->f_color = color;
	free(array2);
}

void	check_cielo(char **array, t_config *config)
{
	int r;
	int g;
	int b;
	unsigned long color;
	char **array2;

	array2 = ft_split(config->array[1], ',');
	r = ft_atoi(array2[0]);
	g = ft_atoi(array2[1]);
	b = ft_atoi(array2[2]);
	color = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	config->c_color = color;
	free(array2);
}

int		check_ris(char **array, t_config *config)
{
	int x;
	int y;

	x = ft_atoi(config->array[1]);
	y = ft_atoi(config->array[2]);
	if ((x > 0 && x <= 2560) && (y >= 0 && y <= 1600))
	{
		config->ris_x = x;
		config->ris_y = y;
		return (0);
	}
	else
	{	
		write(1, "Risoluzione non valida\n", 23);
		return (-1);
	}
}

int		parse_line(char **array, t_config *config)
{
	if (*config->array == NULL)
		return (0);
	if (config->array[0][0] == 'R')
		check_ris(array, config);
	else if (config->array[0][0] == 'F')
		check_floor(array, config);
	else if (config->array[0][0] == 'C')
		check_cielo(array, config);
	return 0;
}

size_t		ft_intlen(int *str)
{
	size_t size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

int	ft_custom_isdigit(char c)
{
	if (ft_isdigit(c))
		if (((c - 48) > -1 && (c - 48) < 3))
			return (1);
	return (0);
}

int		ft_check_maps(char *maps)
{	
	int i;
	int counter;

	i = 0;
	counter = 0;
	if (maps)
	{
		while(i < ft_strlen(maps))
		{
			if (ft_custom_isdigit(maps[i]))
				counter++;
			i++;
		}
	}
	if (counter > 3)
		return (1);
	return (0);
}

char *ft_strcpy_custom(char *src)
{
	int i;
	char *dest;

	i = 0;
	dest = ft_calloc(ft_strlen(src) + 1, 1);
	while (src[i] != '\0')
	{
		if (src[i] == ' ')
			dest[i] = '1';
		else
			dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char 	**ft_create_map(t_config config, char *str, int map_line)
{
	char	**recover;
	int		i;

	i = 0;
	if (map_line != 0)
	{
		recover  = ft_calloc(map_line, sizeof(char *));
		while(i < map_line - 1)
		{
			recover[i] = ft_strcpy_custom(config.map[i]);
			i++;
		}
		free(config.map);
		config.map = ft_calloc(map_line + 1, sizeof(char *));
		i = 0;
		while(i < map_line - 1)
		{
			config.map[i] = ft_strcpy_custom(recover[i]);
			i++;
		}
		config.map[i] = ft_strcpy_custom(str);
		free(recover);
	}
	else
	{
		config.map = ft_calloc(map_line + 1, sizeof(char *));
		config.map[0] = ft_strcpy_custom(str);
	}
	if (map_line > 0)
		printf("%s\n", config.map[map_line - 1]);
	else 
		printf("%s\n", config.map[map_line]);
	return (config.map);
}

t_config ft_parsing(int ac, char **av)
{
	char		*line;
	t_pars		pars;
	t_config	config;
	int			map_line;

	pars.x = 1;
	map_line = 0;
	if (ac == 2 || ac == 3)
	{
		if (ac == 3 && ft_strcmp(av[2], "--save") == 1)
		{
			write(1, "screenshot\n", 11);
			pars.x = 2;
		}				
		if (!ft_check_file(av[pars.x]))
		{
			write(1, "the selected file is not correct.\n", 37);
			return (config);
		}
		if ((pars.c_fd = open(av[pars.x], O_RDONLY)) < 0)
			return (config);
		line = NULL;
		config_init(&config);
		while (get_next_line(pars.c_fd, &line) > 0)
		{
			config.array = ft_split(line, ' ');
			if (ft_check_maps(*config.array))
			{
				config.map = ft_create_map(config, line, map_line);
				map_line++;
			}
			else
				parse_line(config.array, &config);
			free(line);
			free(config.array);
		}
		free(line);
		line = NULL;
		close(pars.c_fd);
		return (config);
	}
	else
		write(1, "wrong number of arguments\n", 26);
	return (config);
}
