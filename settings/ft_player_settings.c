/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_settings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:11:55 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/15 19:46:23 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	support_is_valid(t_config *config, char vers, int i, int j)
{
	if (vers == 'D')
	{
		while(config->map[i][j] != '\0'  && i < config->map_line)
		{
			if (config->map[i][j] != '1')
				i++;
			else
				return (1);
		}
	}
 	if (vers == 'U')
	{
		while(config->map[i][j] != '\0')
		{
			if (config->map[i][j] != '1')
				i--;
			else
				return (1);
		}
	}
	if (vers == 'L')
	{
		while(config->map[i][j] != '\0')
		{
			if (config->map[i][j] != '1')
				j--;
			else
				return (1);
		}
	}
	if (vers == 'R')
	{
		while(config->map[i][j] != '\0' && j < (int)ft_strlen(config->map[i]))
		{
			if (config->map[i][j] != '1')
				j++;
			else
				return (1);
		}
	}
	return (0); 
}

int	is_map_valid(t_config *config)
{
	int	i;
	int	j;
	int	len;
	int	found_wall;

	found_wall = FALSE;
	i = 0;
	j = 0;
	while (i < config->map_line)
	{
		len = ft_strlen(config->map[i]);
		while (j < len)
		{
			if (config->map[i][j] == '0' && found_wall == TRUE)
			{
				if (config->map[i - 1][j] == '\0' || config->map[i - 1][j] == '0')
				{
					if (!support_is_valid(config, 'U', i, j))
						return (0);
				}
				else if (config->map[i + 1][j] == '\0' || config->map[i + 1][j] == '0')
				{
					if (!support_is_valid(config, 'D', i, j))
						return (0);
				}
				else if (config->map[i][j - 1] == '\0' || config->map[i][j - 1] == '0')
				{
					if (!support_is_valid(config, 'L', i, j))
						return (0);
				}
				else if (config->map[i][j + 1] == '\0' || config->map[i][j + 1] == '0')
				{
					if (!support_is_valid(config, 'R', i, j))
						return (0);
				}
			}
			else 
			{
				if (config->map[i][j] == '1' || config->map[i][j] == '2' \
					 || config->map[i][j] == 'N' || config->map[i][j] == 'S' \
					 || config->map[i][j] == 'W' || config->map[i][j] == 'E')
						found_wall = TRUE;
			}
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
	return (1);
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
