/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:02:28 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/13 21:44:41 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_cam_left(t_game *game)
{
	if (game->movement.cam_left)
	{
		game->raycasting.oldDirX = game->player.dir_x;
		game->player.dir_x = game->player.dir_x
			* cos(game->player.rotation_speed) - game->player.dir_y
			* sin(game->player.rotation_speed);
		game->player.dir_y = game->raycasting.oldDirX
			* sin(game->player.rotation_speed) + game->player.dir_y
			* cos(game->player.rotation_speed);
		game->raycasting.oldPlaneX = game->player.plane_x;
		game->player.plane_x = game->player.plane_x
			* cos(game->player.rotation_speed) - game->player.plane_y
			* sin(game->player.rotation_speed);
		game->player.plane_y = game->raycasting.oldPlaneX
			* sin(game->player.rotation_speed) + game->player.plane_y
			* cos(game->player.rotation_speed);
	}
}

static void	ft_cam_move(t_game *game)
{
	if (game->movement.cam_right)
	{
		game->raycasting.oldDirX = game->player.dir_x;
		game->player.dir_x = game->player.dir_x
			* cos(-game->player.rotation_speed)
			- game->player.dir_y * sin(-game->player.rotation_speed);
		game->player.dir_y = game->raycasting.oldDirX
			* sin(-game->player.rotation_speed) + game->player.dir_y
			* cos(-game->player.rotation_speed);
		game->raycasting.oldPlaneX = game->player.plane_x;
		game->player.plane_x = game->player.plane_x
			* cos(-game->player.rotation_speed) - game->player.plane_y
			* sin(-game->player.rotation_speed);
		game->player.plane_y = game->raycasting.oldPlaneX
			* sin(-game->player.rotation_speed) + game->player.plane_y
			* cos(-game->player.rotation_speed);
	}
	ft_cam_left(game);
}

static void	ft_move_support(t_game *game, int **map)
{
	if (game->movement.up)
	{
		if ((map[(int)(game->player.pos_x + game->player.dir_x
					* game->player.speed)]
			[(int)game->player.pos_y]) != 1)
			game->player.pos_x += game->player.dir_x * game->player.speed;
		if ((map[(int)game->player.pos_x][(int)(game->player.pos_y
				+ game->player.dir_y * game->player.speed)]) != 1)
			game->player.pos_y += game->player.dir_y * game->player.speed;
	}
	if (game->movement.down)
	{
		if ((map[(int)(game->player.pos_x - game->player.dir_x
					* game->player.speed)]
			[(int)(game->player.pos_y)]) != 1)
			game->player.pos_x -= game->player.dir_x * game->player.speed;
		if ((map[(int)(game->player.pos_x)][(int)(game->player.pos_y
			- game->player.dir_y * game->player.speed)]) != 1)
			game->player.pos_y -= game->player.dir_y * game->player.speed;
	}
}

void	ft_move(t_game *game, int **map)
{
	if (game->movement.right)
	{
		if ((map[(int)(game->player.pos_x + game->player.dir_y
					* game->player.speed)]
			[(int)(game->player.pos_y)]) != 1)
			game->player.pos_x += game->player.dir_y * game->player.speed;
		if ((map[(int)(game->player.pos_x)][(int)(game->player.pos_y
			- game->player.dir_x * game->player.speed)]) != 1)
			game->player.pos_y -= game->player.dir_x * game->player.speed;
	}
	if (game->movement.left)
	{
		if ((map[(int)(game->player.pos_x - game->player.dir_y
					* game->player.speed)]
			[(int)(game->player.pos_y)]) != 1)
			game->player.pos_x -= game->player.dir_y * game->player.speed;
		if ((map[(int)(game->player.pos_x)][(int)(game->player.pos_y
			+ game->player.dir_x * game->player.speed)]) != 1)
			game->player.pos_y += game->player.dir_x * game->player.speed;
	}
	ft_move_support(game, map);
	ft_cam_move(game);
}
