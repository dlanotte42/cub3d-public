/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:43:02 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/13 22:42:32 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_support_set_params(t_game *game)
{
	game->player.pos_x = 2;
	game->player.pos_y = 10;
	game->player.dir_x = -1.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
	game->player.rotation_speed = 0.000080;
	game->player.speed = 0.000090;
	game->camera.destroy = FALSE;
	game->mods.Drunk = FALSE;
	game->mods.Wall_rotate = FALSE;
	game->movement.up = FALSE;
	game->movement.down = FALSE;
	game->movement.left = FALSE;
	game->movement.right = FALSE;
	game->movement.cam_right = FALSE;
	game->movement.cam_left = FALSE;
}

void	ft_set_parameters(t_game *game, int argc, char **argv)
{
	t_config	config;

	config = ft_parsing(argc, argv);
	ft_support_set_params(game);
	game->map = config.map_def;
	game->textures[0].texture_path = config.n_wall;
	game->textures[1].texture_path = config.s_wall;
	game->textures[2].texture_path = config.w_wall;
	game->textures[3].texture_path = config.e_wall;
	game->textures[4].texture_path = "./texture/wood.xpm";
	game->textures[5].texture_path = config.sprite_tex;
	game->camera.ris_x = config.ris_x;
	game->camera.ris_y = config.ris_y;
}

t_game	*ft_raycast_set_block(t_game *game)
{
	if (game->raycasting.side == 0)
	{
		if (game->raycasting.stepX > 0)
			game->raycasting.textNum = 0;
		else
			game->raycasting.textNum = 1;
	}	
	else
	{
		if (game->raycasting.stepY > 0)
			game->raycasting.textNum = 2;
		else
			game->raycasting.textNum = 3;
	}
	return (game);
}
