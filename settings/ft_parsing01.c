/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:53:45 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/15 19:35:09 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_custom_isdigit(char c)
{
	if (ft_isdigit(c))
		if (((c - 48) > -1 && (c - 48) < 3))
			return (1);
	return (0);
}

int	ft_check_maps(char *maps)
{	
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	if (maps)
	{
		while (i < (int)ft_strlen(maps))
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

void	ft_recover_support(int map_line, t_config *config, char *str)
{
	char	**recover;
	int		i;

	i = 0;
	recover = ft_calloc(map_line, sizeof(char *));
	while (i < map_line)
	{
		recover[i] = ft_strcpy_custom(config->map[i]);
		i++;
	}
	free(config->map);
	config->map = ft_calloc(map_line + 1, sizeof(char *));
	i = 0;
	while (i < map_line)
	{
		config->map[i] = ft_strcpy_custom(recover[i]);
		i++;
	}
	config->map[i] = ft_strcpy_custom(str);
	free(recover);
}

char 	**ft_create_map(t_config config, char *str, int map_line)
{
	if (map_line != 0)
		ft_recover_support(map_line, &config, str);
	else
	{
		config.map = ft_calloc(map_line + 1, sizeof(char *));
		config.map[0] = ft_strcpy_custom(str);
	}
	return (config.map);
}

t_config	ft_parsing(int ac, char **av)
{
	t_pars		pars;
	t_config	config;

	pars.x = 1;
	config.map_line = 0;
	config.start_game = FALSE;
	config.screenshot = FALSE;
	config.start_x = 0;
	config.start_y = 0;
	if (ac == 2 || ac == 3)
	{
		config = ft_init_parse_one(ac, av, pars, config);
		config.map_def = ft_convert(&config);
		printf("Mappa Caricata: \n");
		printf("\nMappa Valida: %d", is_map_valid(&config));
		fflush(stdout);
		if (config.map_line)
			config.start_game = TRUE;
		return (config);
	}
	else
		write(1, "wrong number of arguments\n", 26);
	return (config);
}
