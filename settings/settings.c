/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:43:02 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/03 01:00:54 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_set_parameters(t_game *game, int argc, char **argv)
{
	t_config config;

	config = ft_parsing(argc, argv);
	game->player.pos_x = 12;
	game->player.pos_y = 10;
	game->player.dir_x = -1.0;
	game->player.dir_y = 0.0;
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
	game->player.rotation_speed = 0.000080;
	game->player.speed = 0.000090;

	game->textures[0].texture_path = ft_strcpy(config.n_wall);
	game->textures[1].texture_path = "./texture/greystone.xpm";
	game->textures[2].texture_path = "./texture/colorstone.xpm";
	game->textures[3].texture_path = "./texture/Dkstnrgt.xpm";
	game->textures[4].texture_path = "./texture/mossy.xpm";
	game->textures[5].texture_path = "./texture/redbrick.xpm";
	game->textures[6].texture_path = "./texture/wood.xpm";
	game->textures[7].texture_path = "./texture/purplestone.xpm";
	game->textures[8].texture_path = "./texture/swastika.xpm";
	game->textures[9].texture_path = "./texture/swastika-2.xpm";
	game->textures[10].texture_path = "./texture/pillar.xpm";

	game->camera.ris_x = config.ris_x;
	game->camera.ris_y = config.ris_y;
	game->camera.destroy = FALSE;

	game->mods.Drunk = FALSE;
	game->mods.Wall_rotate = FALSE;

	game->movement.up = FALSE;
	game->movement.down = FALSE;
	game->movement.left = FALSE;
	game->movement.right = FALSE;
	game->movement.cam_right = FALSE;
	game->movement.cam_left = FALSE;	
	//printf("%s", config.n_wall);
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