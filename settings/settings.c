/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:43:02 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/03/25 00:56:09 by zxcvbinz         ###   ########.fr       */
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
	game->textures[3].texture_path = "./texture/eagle.xpm";
	game->textures[4].texture_path = "./texture/mossy.xpm";
	game->textures[5].texture_path = "./texture/redbrick.xpm";
	game->textures[6].texture_path = "./texture/wood.xpm";
	game->textures[7].texture_path = "./texture/purplestone.xpm";
	game->textures[8].texture_path = "./texture/swastika.xpm";
	game->textures[9].texture_path = "./texture/swastika-2.xpm";
	game->textures[10].texture_path = "./texture/fake_door.xpm";

	game->camera.ris_x = 1280;
	game->camera.ris_y = 720;

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

t_game	*ft_raycast_set_block(t_game *game, int map[24][24])
{
	if (map[game->raycasting.mapX][game->raycasting.mapY] == 1)
		game->raycasting.textNum = 0;
	else if (map[game->raycasting.mapX][game->raycasting.mapY] == 2)
		game->raycasting.textNum = 1;
	else if (map[game->raycasting.mapX][game->raycasting.mapY] == 3)
		game->raycasting.textNum = 2;
	else if (map[game->raycasting.mapX][game->raycasting.mapY] == 4)
		game->raycasting.textNum = 3;
	else if (map[game->raycasting.mapX][game->raycasting.mapY] == 5)
		game->raycasting.textNum = 4;
	else if (map[game->raycasting.mapX][game->raycasting.mapY] == 6)
		game->raycasting.textNum = 5;
	else if (map[game->raycasting.mapX][game->raycasting.mapY] == 7)
		game->raycasting.textNum = 6;
	else if (map[game->raycasting.mapX][game->raycasting.mapY] == 8)
		game->raycasting.textNum = 7;
	else if (map[game->raycasting.mapX][game->raycasting.mapY] == 9)
		game->raycasting.textNum = 8;
	else if (map[game->raycasting.mapX][game->raycasting.mapY] == 10)
		game->raycasting.textNum = 9;
	else
		game->raycasting.textNum = 10;
	return (game);
}