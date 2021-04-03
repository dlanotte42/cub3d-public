/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:02:28 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/03 17:18:18 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_mods(int keycode, t_game *game)
{
	if (keycode == DRUNK_KEY && !game->mods.Drunk)
		game->mods.Drunk = TRUE;
	else if (keycode == DRUNK_KEY && game->mods.Drunk)
		game->mods.Drunk = FALSE;
	else if (keycode == TAP_KEY && !game->mods.Wall_rotate)
		game->mods.Wall_rotate = TRUE;
	else if (keycode == TAP_KEY && game->mods.Wall_rotate)
		game->mods.Wall_rotate = FALSE;
}

static	void ft_cam_move(t_game *game)
{
	if (game->movement.cam_right)
	{
		game->raycasting.oldDirX = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(-game->player.rotation_speed) - game->player.dir_y * sin(-game->player.rotation_speed);
		game->player.dir_y = game->raycasting.oldDirX * sin(-game->player.rotation_speed) + game->player.dir_y * cos(-game->player.rotation_speed);
		game->raycasting.oldPlaneX = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(-game->player.rotation_speed) - game->player.plane_y * sin(-game->player.rotation_speed);
		game->player.plane_y = game->raycasting.oldPlaneX * sin(-game->player.rotation_speed) + game->player.plane_y * cos(-game->player.rotation_speed);
	}
	if (game->movement.cam_left)
	{
		game->raycasting.oldDirX = game->player.dir_x;
		game->player.dir_x = game->player.dir_x * cos(game->player.rotation_speed) - game->player.dir_y * sin(game->player.rotation_speed);
		game->player.dir_y = game->raycasting.oldDirX * sin(game->player.rotation_speed) + game->player.dir_y * cos(game->player.rotation_speed);
		game->raycasting.oldPlaneX = game->player.plane_x;
		game->player.plane_x = game->player.plane_x * cos(game->player.rotation_speed) - game->player.plane_y * sin(game->player.rotation_speed);
		game->player.plane_y = game->raycasting.oldPlaneX * sin(game->player.rotation_speed) + game->player.plane_y * cos(game->player.rotation_speed);
	}
}

void		ft_move(t_game *game, int map[24][24])
{
	if (game->movement.right)
	{
		if((map[(int)(game->player.pos_x + game->player.dir_y * game->player.speed)][(int)(game->player.pos_y)]) != 1)
				game->player.pos_x += game->player.dir_y * game->player.speed;
		if((map[(int)(game->player.pos_x)][(int)(game->player.pos_y - game->player.dir_x * game->player.speed)]) != 1)
				game->player.pos_y -= game->player.dir_x * game->player.speed;
	}

	if (game->movement.left)
	{
		if((map[(int)(game->player.pos_x - game->player.dir_y * game->player.speed)][(int)(game->player.pos_y)]) != 1)
        	game->player.pos_x -= game->player.dir_y * game->player.speed;
      	if((map[(int)(game->player.pos_x)][(int)(game->player.pos_y + game->player.dir_x * game->player.speed)]) != 1)
        	game->player.pos_y += game->player.dir_x * game->player.speed;
	}

	if (game->movement.up)
	{
		if((map[(int)(game->player.pos_x + game->player.dir_x * game->player.speed)][(int)game->player.pos_y]) != 1) 
      		game->player.pos_x += game->player.dir_x * game->player.speed;
		if((map[(int)game->player.pos_x][(int)(game->player.pos_y + game->player.dir_y * game->player.speed)]) != 1)
      		game->player.pos_y += game->player.dir_y * game->player.speed;
	}
	if (game->movement.down)
	{
		if((map[(int)(game->player.pos_x - game->player.dir_x * game->player.speed)][(int)(game->player.pos_y)]) != 1) 
      		game->player.pos_x -= game->player.dir_x * game->player.speed;
    	if((map[(int)(game->player.pos_x)][(int)(game->player.pos_y - game->player.dir_y * game->player.speed)]) != 1)
      		game->player.pos_y -= game->player.dir_y * game->player.speed;
	}
	ft_cam_move(game);
}

int			onPressButton(int keycode, t_game *game)
{	
	if (keycode == 53)
	{
		mlx_destroy_window(game->vars.mlx, game->vars.win);
		exit(0);
	}
	if (keycode == A_KEY)
		game->movement.left = TRUE;
	if (keycode == S_KEY)
		game->movement.down = TRUE;
	if (keycode == D_KEY)
		game->movement.right = TRUE;
	if (keycode == W_KEY)
		game->movement.up = TRUE;
	if (keycode == RIGHT_KEY)
		game->movement.cam_right = TRUE;
	if (keycode == LEFT_KEY)
		game->movement.cam_left = TRUE;
	if (keycode == RUN_KEY)
		game->player.speed += 0.000090;
	if (keycode == DRUNK_KEY)
		ft_mods(keycode, game);
	if (keycode == TAP_KEY)
		ft_mods(keycode, game);
	return (0);
}

int			onReleseButton(int keycode, t_game *game)
{
	if (keycode == A_KEY)
		game->movement.left = FALSE;
	if (keycode == S_KEY)
		game->movement.down = FALSE;
	if (keycode == D_KEY)
		game->movement.right = FALSE;
	if (keycode == W_KEY)
		game->movement.up = FALSE;
	if (keycode == RIGHT_KEY)
		game->movement.cam_right = FALSE;
	if (keycode == LEFT_KEY)
		game->movement.cam_left = FALSE;
	if (keycode == RUN_KEY)
		game->player.speed = 0.000090;
	return (0);
}
