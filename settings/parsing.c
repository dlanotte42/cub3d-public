/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:53:45 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/02 20:13:25 by dlanotte         ###   ########.fr       */
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

size_t		ft_strlen2(const char *str)
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
		if ((c - 48) > -1 && (c - 48) < 3)
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

void 	ft_create_map(char *line, int map_line, int **map)
{
	int 	**recover;

	map_line += 1;
	
	map = ft_calloc(4, map_line + 1);
	map[0] = ft_calloc(4, ft_strlen(line));
	map[0][0] = 3;
	printf("%d\n", map[0][0]);

	
	if (!map)
		printf("non valido\n");
	else 
		printf("valido");
	free(map);
}

t_config ft_parsing(int ac, char **av)
{
	char		*line;
	t_pars		pars;
	t_config	config;
	//t_str		*map_buffer;
	int			map_line;

	map_line = 0;
	pars.x = 1;
	if (ac == 2 || ac == 3)
	{
		if (ac == 3 && ft_strcmp(av[pars.x], "--save") == 1)
		{
			write(1, "screenshot\n", 11);
			pars.x = 2;
		}				
		if (!ft_check_file(av[pars.x]))
		{
			write(1, "Il file selezionato non è corretto.\n", 37);
			return (config);
		}
		if ((pars.c_fd = open(av[pars.x], O_RDONLY)) < 0)
			return (config);
		//map_buffer = NULL;
		line = NULL;
		config_init(&config);
		while (get_next_line(pars.c_fd, &line) > 0)
		{
			config.array = ft_split(line, ' ');
			if (ft_check_maps(*config.array))
			{
				ft_create_map(line, map_line, config.map);	
				map_line++;
			}
			else
				parse_line(config.array, &config);
			free(line);
			free(config.array);
			//line = NULL;
		}
		//printf("%s", line);
		free(line);
		line = NULL;

		//if (r && ft_strlen(line) > 0)
		//	r = !!str_add_back(&map_buffer, ft_strdup(line));
		close(pars.c_fd);
		//if (!r || !parse_map(config, map_buffer))
		//	return (str_clear(&map_buffer));
		//str_clear(&map_buffer);
		return (config);
	}
	else
		write(1, "wrong number of arguments\n", 26);
	return (config);
}