/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:49:05 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/13 19:06:03 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int		ft_validate_map(t_config config)
{
	
	
	return (FALSE);
}

int		**ft_convert(t_config config)
{
	int i;
	int len;
	int j;

	j = 0;
	i = 0;
	len = 0;
	if (!ft_validate_map(config))
		return (FALSE);
	config.map_def = ft_calloc(config.map_line, sizeof(int *));
	while (i < config.map_line)
	{
		len = ft_strlen(config.map[i]);
		config.map_def[i] = ft_calloc(len, sizeof(int));
		while (j < len)
		{
			if (config.map[i][j] == ' ')
				config.map_def[i][j] = 1;
			else if (config.map[i][j] == 'N' || config.map[i][j] == 'S'
				|| config.map[i][j] == 'W' || config.map[i][j] == 'E')
				config.map_def[i][j] = 0;
			else
				config.map_def[i][j] = (config.map[i][j] - 48);
			j++;
		}
		j = 0;
		i++;
	}
	return (config.map_def);
}
