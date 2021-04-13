/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_button.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 21:43:46 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/13 21:44:58 by zxcvbinz         ###   ########.fr       */
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

int	onPressButton(int keycode, t_game *game)
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

int	onReleseButton(int keycode, t_game *game)
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
