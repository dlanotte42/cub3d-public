/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:43:37 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/22 18:43:31 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

void	ft_init_struct(t_game *game)
{
	game->player.pos_x = 12;
	game->player.pos_y = 10;
	game->player.dir_x = -1;
	game->player.dir_y = 0;
	game->player.plane_x = 0;
	game->player.plane_y = 0.66;
	game->player.rotation_speed = 0.000030;
	game->player.speed = 0.15;

	game->camera.ris_y = 1080;
	game->camera.ris_x = 1920;
	
	game->movement.up = FALSE;
	game->movement.down = FALSE;
	game->movement.left = FALSE;
	game->movement.right = FALSE;
	game->movement.cam_right = FALSE;
	game->movement.cam_left = FALSE;
}

void	ft_init_mlx(t_game *game)
{
	game->vars.mlx = mlx_init();
	game->vars.win = mlx_new_window(game->vars.mlx, game->camera.ris_x, game->camera.ris_y, "min3d");
}

int		render_game_loop(t_game *game)
{
	//ft_move(game);
	ft_print_wall(game);
	ft_re_create_img(game);
	return (0);
}

int		main(void)
{
	t_game game;

	ft_init_struct(&game);
	ft_init_mlx(&game);
	mlx_hook(game.vars.win, 2, 0L, onPressButton, &game);
	mlx_hook(game.vars.win, 3, 0L, onReleseButton, &game);
	game.img.img = mlx_new_image(game.vars.mlx, game.camera.ris_x, game.camera.ris_y);
	game.img.addr = mlx_get_data_addr(game.img.img, &game.img.bits_per_pixel, &game.img.line_length, &game.img.endian);
	mlx_loop_hook(game.vars.mlx, render_game_loop, &game);
	mlx_loop(game.vars.mlx);
	return (0);
}