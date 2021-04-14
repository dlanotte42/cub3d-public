/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_texture00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:03:12 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/14 23:53:01 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_check_texture(t_game *game, t_config *config)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	game->sprites_counter = 0;
	j = 0;
	len = 0;
	while (i < config->map_line)
	{
		len = ft_strlen(config->map[i]);
		while (j < len)
		{
			if (config->map[i][j] - 48 == 2)
			{
				game->sprites[game->sprites_counter].x = i + 0.5;
				game->sprites[game->sprites_counter].y = j + 0.5;
				game->sprites[game->sprites_counter].texture = 5;
				game->sprites_counter++;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
