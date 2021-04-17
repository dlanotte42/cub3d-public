/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_settings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:11:55 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/17 18:53:38 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	ft_is(int n, char c)
{
	if (n == 1 && (c == '1' || c == '2'))
		return (1);
	else if (n == 2 && (c == 'N' || c == 'S' || c == 'E' || c == 'W'))
		return (1);
	else if (n == 0 && (c == '0' || c == 'O' || c == 'X'))
		return (1);
	else
		return (0);
}

static int	ft_mapcheck(t_config *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < s->map_line)
	{
		j = 0;
		while (j < (int)ft_strlen(s->map[i]))
		{
			if (ft_is(1, s->map[i][j]) == 0 && i == 0)
				return (-1);
			else if (ft_is(1, s->map[i][j]) == 0 && i == s->map_line - 1)
				return (-1);
			else if (ft_is(1, s->map[i][j]) == 0 && j == 0)
				return (-1);
			else if (ft_is(1, s->map[i][j]) == 0 && j == \
				(int)(ft_strlen(s->map[i]) - (size_t) 1))
				return (-1);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_map_valid(t_config *config)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	while (i < config->map_line)
	{
		len = ft_strlen(config->map[i]);
		while (j < len)
		{
			if (config->map[i][j] == ' ')
				config->map[i][j] = '1';
			if (config->map[i][j] == 'N')
				printf("\x1b[31m%c\033[0m", config->map[i][j]);
			else
				printf("\033[0m%c", config->map[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	return (ft_mapcheck(config));
}

t_config	*ft_s_pla_start(int map_position, t_config *config, int x, int y)
{
	if (map_position == 'N' || map_position == 'S' \
		 || map_position == 'W' || map_position == 'E')
	{
		config->start_x = x;
		config->start_y = y;
		config->direction = map_position;
	}
	return (config);
}
