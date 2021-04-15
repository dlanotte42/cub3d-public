/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_base00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:43:47 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/15 17:52:09 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_support_floor_casting(t_game *game)
{
	game->raycasting.floor.floorStepX = game->raycasting.floor.rowDistance \
		 * (game->raycasting.floor.rayDirX1 - game->raycasting.floor.rayDirX0) \
		 / game->camera.ris_x;
	game->raycasting.floor.floorStepY = game->raycasting.floor.rowDistance \
		 * (game->raycasting.floor.rayDirY1 - game->raycasting.floor.rayDirY0) \
		 / game->camera.ris_x;
	game->raycasting.floor.floorX = game->player.pos_x \
		 + game->raycasting.floor.rowDistance \
		 * game->raycasting.floor.rayDirX0;
	game->raycasting.floor.floorY = game->player.pos_y \
		 + game->raycasting.floor.rowDistance \
		 * game->raycasting.floor.rayDirY0;
	game->raycasting.floor.x = 0;
}

static void	ft_floor_casting(t_game *game, int y)
{
	game->raycasting.floor.rayDirX0 = game->player.dir_x \
		 - game->player.plane_x;
	game->raycasting.floor.rayDirY0 = game->player.dir_y \
		 - game->player.plane_y;
	game->raycasting.floor.rayDirX1 = game->player.dir_x \
		 + game->player.plane_x;
	game->raycasting.floor.rayDirY1 = game->player.dir_y \
		 + game->player.plane_y;
	game->raycasting.floor.p = y - game->camera.ris_y / 2;
	game->raycasting.floor.posZ = 0.5 * game->camera.ris_y;
	game->raycasting.floor.rowDistance = game->raycasting.floor.posZ \
	 	 / game->raycasting.floor.p;
	ft_support_floor_casting(game);
	ft_print_floor(game, y);
}

static void	ft_support_route_casting(t_game *game)
{
	sortSprites(game->raycasting.sprite_casting.spriteOrder, \
		game->raycasting.sprite_casting.spriteDistance, \
		game->raycasting.sprite_casting.numSprites);
	ft_cs(game, game->raycasting.sprite_casting.numSprites, \
		game->raycasting.sprite_casting.ZBuffer, \
		game->raycasting.sprite_casting.spriteOrder);
}

void	ft_route_casting(t_game *game)
{
	int	i;

	while (game->raycasting.sprite_casting.y < game->camera.ris_y)
	{
		ft_floor_casting(game, game->raycasting.sprite_casting.y);
		game->raycasting.sprite_casting.y++;
	}
	game->raycasting.x = 0;
	ft_init_texture(game);
	game->raycasting.sprite_casting.ZBuffer = \
		ft_raycasting_extra(game, game->raycasting.sprite_casting.ZBuffer, 0);
	i = 0;
	while (i < game->raycasting.sprite_casting.numSprites)
	{
		game->raycasting.sprite_casting.spriteOrder[i] = i;
		game->raycasting.sprite_casting.spriteDistance[i] = \
			((game->player.pos_x - game->sprites[i].x) * (game->player.pos_x \
			 - game->sprites[i].x) + (game->player.pos_y \
			 - game->sprites[i].y) * (game->player.pos_y - game->sprites[i].y));
		i++;
	}
	ft_support_route_casting(game);
}

void	ft_raycasting(t_game *game)
{
	game->raycasting.sprite_casting.ZBuffer = malloc(sizeof(double) \
			 * game->camera.ris_x);
	game->raycasting.sprite_casting.numSprites = game->sprites_counter;
	game->raycasting.sprite_casting.spriteOrder = malloc(sizeof(int) \
			 * game->sprites_counter);
	game->raycasting.sprite_casting.spriteDistance = malloc(sizeof(double) \
		 * game->sprites_counter);
	ft_init_texture(game);
	game->raycasting.sprite_casting.y = game->camera.ris_y / 2 + 1;
	ft_route_casting(game);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, \
		game->img.img, 0, 0);
	free(game->raycasting.sprite_casting.ZBuffer);
	free(game->raycasting.sprite_casting.spriteOrder);
	free(game->raycasting.sprite_casting.spriteDistance);
}
