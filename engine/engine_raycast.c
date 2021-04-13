/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_raycast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 00:12:59 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/13 20:44:26 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static t_game	*ft_raycast_two(t_game *game, int lineHeight)
{
	game->raycasting.Addvalues.drawStart = -lineHeight / 2
		 + game->camera.ris_y / 2;
	if (game->raycasting.Addvalues.drawStart < 0)
		game->raycasting.Addvalues.drawStart = 0;
	game->raycasting.Addvalues.drawEnd = lineHeight / 2
		 + game->camera.ris_y / 2;
	if (game->raycasting.Addvalues.drawEnd >= game->camera.ris_y)
		game->raycasting.Addvalues.drawEnd = game->camera.ris_y - 1;
	game = ft_raycast_set_block(game);
	return (game);
}

static t_game	*ft_int_raycastone(t_game *game, int **map)
{
	if (game->raycasting.sideDistX < game->raycasting.sideDistY)
	{
		game->raycasting.sideDistX += game->raycasting.deltaDistX;
		game->raycasting.mapX += game->raycasting.stepX;
		game->raycasting.side = 0;
	}
	else
	{
		game->raycasting.sideDistY += game->raycasting.deltaDistY;
		game->raycasting.mapY += game->raycasting.stepY;
		game->raycasting.side = 1;
	}
	if (map[game->raycasting.mapX][game->raycasting.mapY] == 1)
		game->raycasting.hit = 1;
	else if (map[game->raycasting.mapX][game->raycasting.mapY] == 2)
	{
		game->sprites[game->sprites_counter].x = game->raycasting.mapX + 0.5;
		game->sprites[game->sprites_counter].y = game->raycasting.mapY + 0.5;
		game->sprites[game->sprites_counter].texture = 10;
		game->sprites_counter++;
	}
	return (game);
}

static t_game	*ft_raycast_one(t_game *game, int **map)
{
	while (game->raycasting.hit == 0)
	{
		game = ft_int_raycastone(game, map);
	}
	if (game->raycasting.side == 0)
		game->raycasting.perpWallDist = (game->raycasting.mapX
				 - game->player.pos_x + (1 - game->raycasting.stepX) / 2)
			 	 / game->raycasting.rayDirX;
	else
		game->raycasting.perpWallDist = (game->raycasting.mapY
				- game->player.pos_y + (1 - game->raycasting.stepY) / 2)
			/ game->raycasting.rayDirY;
	game->raycasting.Addvalues.lineheight
		 = (int)(game->camera.ris_y / game->raycasting.perpWallDist);
	game = ft_raycast_two(game, game->raycasting.Addvalues.lineheight);
	return (game);
}

static t_game	*ft_init_raycast_zero(t_game *game, int **map)
{
	if (game->raycasting.rayDirX < 0)
	{
		game->raycasting.stepX = -1;
		game->raycasting.sideDistX = (game->player.pos_x
				 - game->raycasting.mapX) * game->raycasting.deltaDistX;
	}
	else
	{
		game->raycasting.stepX = 1;
		game->raycasting.sideDistX = (game->raycasting.mapX + 1.0
				 - game->player.pos_x) * game->raycasting.deltaDistX;
	}
	if (game->raycasting.rayDirY < 0)
	{
		game->raycasting.stepY = -1;
		game->raycasting.sideDistY = (game->player.pos_y
				 - game->raycasting.mapY) * game->raycasting.deltaDistY;
	}
	else
	{
		game->raycasting.stepY = 1;
		game->raycasting.sideDistY = (game->raycasting.mapY + 1.0
				 - game->player.pos_y) * game->raycasting.deltaDistY;
	}
	return (game);
}

t_game	*ft_raycast_zero(t_game *game, int **map)
{
	game->raycasting.y = 0;
	game->raycasting.cameraX = 2 * game->raycasting.x
		 / (double)game->camera.ris_x - 1;
	game->raycasting.rayDirX = game->player.dir_x
		 + game->player.plane_x * game->raycasting.cameraX;
	game->raycasting.rayDirY = game->player.dir_y
		 + game->player.plane_y * game->raycasting.cameraX;
	game->raycasting.mapX = (int)game->player.pos_x;
	game->raycasting.mapY = (int)game->player.pos_y;
	game->raycasting.deltaDistX = fabs(1 / game->raycasting.rayDirX);
	game->raycasting.deltaDistY = fabs(1 / game->raycasting.rayDirY);
	game->raycasting.hit = 0;
	game = ft_init_raycast_zero(game, map);
	game = ft_raycast_one(game, map);
	return (game);
}
