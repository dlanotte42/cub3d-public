/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:02:28 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/22 17:44:59 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_move(t_game *game)
{
	if (game->movement.right == 1)
		game->player.pos_y += 0.15;
	if (game->movement.left == 1)
		game->player.pos_y -= 0.15;
	if (game->movement.up == 1)
		game->player.pos_x -= 0.15;
	if (game->movement.down == 1)
		game->player.pos_x += 0.15;
}

int		onPressButton(int keycode, t_game *game)
{
	//printf("Hello from keycode: %d key_hook!\n", keycode);
	if (keycode == 53)
		mlx_destroy_window(game->vars.mlx, game->vars.win);
	if (keycode == A_KEY)
		game->movement.left = TRUE;
	if (keycode == S_KEY)
		game->movement.down = TRUE;
	if (keycode == D_KEY)
		game->movement.right = TRUE;
	if (keycode == W_KEY)
		game->movement.up = TRUE;
	return (0);
}

int		onReleseButton(int keycode, t_game *game)
{
	if (keycode == 53)
		mlx_destroy_window(game->vars.mlx, game->vars.win);
	if (keycode == A_KEY)
		game->movement.left = FALSE;
	if (keycode == S_KEY)
		game->movement.down = FALSE;
	if (keycode == D_KEY)
		game->movement.right = FALSE;
	if (keycode == W_KEY)
		game->movement.up = FALSE;
	return (0);
}
