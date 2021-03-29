/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:43:02 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/03/27 15:51:40 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_set_parameters(t_game *game)
{
	game->player.pos_x = 12;
	game->player.pos_y = 10;
	game->player.dir_x = -1;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
	game->player.rotation_speed = 0.000050;
	game->player.speed = 0.000090;

	game->textures[0].texture_path = "./texture/bluestone.xpm";
	game->textures[1].texture_path = "./texture/greystone.xpm";
	game->textures[2].texture_path = "./texture/colorstone.xpm";
	game->textures[3].texture_path = "./texture/Dkstnrgt.xpm";
	game->textures[4].texture_path = "./texture/mossy.xpm";
	game->textures[5].texture_path = "./texture/redbrick.xpm";
	game->textures[6].texture_path = "./texture/wood.xpm";
	game->textures[7].texture_path = "./texture/purplestone.xpm";
	game->textures[8].texture_path = "./texture/swastika.xpm";
	game->textures[9].texture_path = "./texture/swastika-2.xpm";
	game->textures[10].texture_path = "./texture/fake_door.xpm";

	game->camera.ris_x = 1920;
	game->camera.ris_y = 1080;
	game->camera.destroy = FALSE;

	game->mods.Drunk = FALSE;
	game->mods.Wall_rotate = FALSE;

	game->movement.up = FALSE;
	game->movement.down = FALSE;
	game->movement.left = FALSE;
	game->movement.right = FALSE;
	game->movement.cam_right = FALSE;
	game->movement.cam_left = FALSE;

	//ft_create_map(game);
}

t_game	*ft_raycast_set_block(t_game *game)
{
	if (game->raycasting.side == 0)
		game->raycasting.textNum = (game->raycasting.stepX > 0) ? 0 : 1;
	else
		game->raycasting.textNum = (game->raycasting.stepY > 0) ? 2 : 3;
	return (game);
}