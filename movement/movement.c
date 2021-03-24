/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:02:28 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/24 16:00:40 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		onPressButton(int keycode, t_game *game)
{
	//printf("Hello from keycode: %d key_hook!\n", keycode);
	if (keycode == 53)
		mlx_destroy_window(game->vars.mlx, game->vars.win);
	if (keycode == A_KEY)
		game->movement.cam_left = TRUE;
	if (keycode == S_KEY)
		game->movement.down = TRUE;
	if (keycode == D_KEY)
		game->movement.cam_right = TRUE;
	if (keycode == W_KEY)
		game->movement.up = TRUE;
	if (keycode == RIGHT_KEY)
		game->movement.cam_right = TRUE;
	if (keycode == LEFT_KEY)
		game->movement.cam_left = TRUE;
	return (0);
}

int		onReleseButton(int keycode, t_game *game)
{
	if (keycode == 53)
		mlx_destroy_window(game->vars.mlx, game->vars.win);
	if (keycode == A_KEY)
		game->movement.cam_left = FALSE;
	if (keycode == S_KEY)
		game->movement.down = FALSE;
	if (keycode == D_KEY)
		game->movement.cam_right = FALSE;
	if (keycode == W_KEY)
		game->movement.up = FALSE;
	if (keycode == RIGHT_KEY)
		game->movement.cam_right = FALSE;
	if (keycode == LEFT_KEY)
		game->movement.cam_left = FALSE;
	return (0);
}
