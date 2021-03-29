/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:43:37 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/27 15:51:06 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_init_mlx(t_game *game)
{
	game->vars.mlx = mlx_init();
	game->vars.win = mlx_new_window(game->vars.mlx, game->camera.ris_x, game->camera.ris_y, "min3d");
}

int		render_game_loop(t_game *game)
{
	int x,y;

	ft_raycasting(game);
	ft_re_create_img(game);
	mlx_mouse_hide();
	mlx_mouse_get_pos(game->vars.win, &x, &y);
	printf("\nX: %d\nY: %d", x, y);
	if (game->camera.destroy == TRUE)
		mlx_destroy_window(game->vars.mlx, game->vars.win);
	return (0);
}

int		main(void)
{
	t_game game;

	ft_set_parameters(&game);
	ft_init_mlx(&game);
	mlx_hook(game.vars.win, 2, 0L, onPressButton, &game);
	mlx_hook(game.vars.win, 3, 0L, onReleseButton, &game);	
	game.img.img = mlx_new_image(game.vars.mlx, game.camera.ris_x, game.camera.ris_y);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length, &game.img.endian);
	mlx_loop_hook(game.vars.mlx, render_game_loop, &game);
	mlx_loop(game.vars.mlx);
	return (0);
}
