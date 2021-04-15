/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_texture00.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 23:03:12 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/15 23:58:23 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < 7)
	{
		game->textures[i].texture = mlx_xpm_file_to_image(game->vars.mlx, \
			game->textures[i].texture_path, &game->textures[i].width, \
			&game->textures[i].height);
		game->textures[i].texture_addr = mlx_get_data_addr \
			(game->textures[i].texture, &game->textures[i].bits_per_pixel, \
			&game->textures[i].line_length, &game->textures[i].endian);
		i++;
	}
}

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
