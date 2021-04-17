/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:43:02 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/17 18:48:35 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_support_set_change_direction(t_game *game, char direction)
{
	if (direction == 'W')
	{
		game->player.dir_x = 0;
		game->player.dir_y = 1;
		game->player.plane_x = 0.66;
		game->player.plane_y = 0;
	}
	else if (direction == 'E')
	{
		game->player.dir_x = 0;
		game->player.dir_y = -1;
		game->player.plane_x = -0.66;
		game->player.plane_y = 0;
	}
}

static void	ft_set_direction(t_game *game, char direction)
{
	if (direction == 'N')
	{
		game->player.dir_x = 1;
		game->player.dir_y = 0.0;
		game->player.plane_x = 0;
		game->player.plane_y = -0.66;
	}
	else if (direction == 'S')
	{
		game->player.dir_x = -1;
		game->player.dir_y = 0.0;
		game->player.plane_x = 0;
		game->player.plane_y = 0.66;
	}
	else if (direction == 'W' || direction == 'E')
		ft_support_set_change_direction(game, direction);
}

static void	ft_support_set_params(t_game *game, t_config config)
{
	game->player.pos_x = config.start_x;
	game->player.pos_y = config.start_y + 0.5;
	ft_set_direction(game, config.direction);
	game->player.rotation_speed = 0.000080;
	game->player.speed = 0.000180;
	game->mods.Drunk = FALSE;
	game->mods.Wall_rotate = FALSE;
	game->movement.up = FALSE;
	game->movement.down = FALSE;
	game->movement.left = FALSE;
	game->movement.right = FALSE;
	game->movement.cam_right = FALSE;
	game->movement.cam_left = FALSE;
}

void	ft_set_parameters(t_game *game, int argc, char **argv)
{
	t_config	config;

	config = ft_parsing(argc, argv);
	ft_support_set_params(game, config);
	game->start = config.start_game;
	game->camera.screenshot_game = config.screenshot;
	game->map = config.map_def;
	game->textures[0].texture_path = config.n_wall;
	game->textures[1].texture_path = config.s_wall;
	game->textures[2].texture_path = config.w_wall;
	game->textures[3].texture_path = config.e_wall;
	game->textures[4].texture_path = "./texture/wood.xpm";
	game->textures[5].texture_path = config.sprite_tex;
	game->textures[6].texture_path = "./texture/redbrick.xpm";
	game->camera.ris_x = config.ris_x;
	game->camera.ris_y = config.ris_y;
	game->sprites = malloc(config.number_sprite * sizeof(t_sprite));
	game->f_color = config.f_color;
	game->c_color = config.c_color;
	ft_check_texture(game, &config);
	if (game->start)
	{
		free(config.map);
	}
}

t_game	*ft_raycast_set_block(t_game *game)
{
	if (game->raycasting.side == 0)
	{
		if (game->raycasting.stepX > 0)
			game->raycasting.textNum = 0;
		else
			game->raycasting.textNum = 1;
	}	
	else
	{
		if (game->raycasting.stepY > 0)
			game->raycasting.textNum = 2;
		else
			game->raycasting.textNum = 3;
	}
	return (game);
}
