/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_base02.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 01:56:16 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/17 18:55:21 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_put_sprite(t_game *game)
{
	game->raycasting.sprite_create.y = \
		game->raycasting.sprite_create.drawStartY;
	while (game->raycasting.sprite_create.y < \
		game->raycasting.sprite_create.drawEndY)
	{
		game->raycasting.sprite_create.d = game->raycasting.sprite_create.y \
			 * 256 - game->camera.ris_y * 128 + \
			game->raycasting.sprite_create.spriteHeight * 128;
		game->raycasting.sprite_create.texY = \
			((game->raycasting.sprite_create.d * game->textures[5].height) \
			 / game->raycasting.sprite_create.spriteHeight) / 256;
		game->raycasting.sprite_create.color = \
			ft_get_pixel(&game->textures[5], \
			game->raycasting.sprite_create.texX, \
			game->raycasting.sprite_create.texY);
		if ((game->raycasting.sprite_create.color & 0xFFFFFF) != 0)
			ft_put_pixel_base(&game->img, \
				game->raycasting.sprite_create.stripe, \
				game->raycasting.sprite_create.y, \
				game->raycasting.sprite_create.color);
		game->raycasting.sprite_create.y++;
	}
}

void	ft_cs_check(t_game *game)
{
	if (game->raycasting.sprite_create.drawStartY < 0)
		game->raycasting.sprite_create.drawStartY = 0;
	game->raycasting.sprite_create.drawEndY = \
		game->raycasting.sprite_create.spriteHeight \
		 / 2 + game->camera.ris_y / 2;
	if (game->raycasting.sprite_create.drawEndY >= game->camera.ris_y)
		game->raycasting.sprite_create.drawEndY = game->camera.ris_y - 1;
	game->raycasting.sprite_create.spriteWidth = fabs((game->camera.ris_y \
		 / (game->raycasting.sprite_create.transformY)));
	game->raycasting.sprite_create.drawStartX = \
		 - game->raycasting.sprite_create.spriteWidth / 2 \
		 + game->raycasting.sprite_create.spriteScreenX;
	if (game->raycasting.sprite_create.drawStartX < 0)
		game->raycasting.sprite_create.drawStartX = 0;
	game->raycasting.sprite_create.drawEndX = \
		game->raycasting.sprite_create.spriteWidth / 2 \
		 + game->raycasting.sprite_create.spriteScreenX;
	if (game->raycasting.sprite_create.drawEndX >= game->camera.ris_x)
		game->raycasting.sprite_create.drawEndX = game->camera.ris_x - 1;
	game->raycasting.sprite_create.stripe = \
		game->raycasting.sprite_create.drawStartX;
}

void	ft_cs_one(t_game *game, int *spriteOrder)
{
	game->raycasting.sprite_create.spriteX = \
		game->sprites[spriteOrder[game->raycasting.sprite_create.i]].x \
		 - game->player.pos_x;
	game->raycasting.sprite_create.spriteY = \
		game->sprites[spriteOrder[game->raycasting.sprite_create.i]].y \
		 - game->player.pos_y;
	game->raycasting.sprite_create.invDet = 1.0 / (game->player.plane_x \
		 * game->player.dir_y - game->player.dir_x * game->player.plane_y);
	game->raycasting.sprite_create.transformX = \
		game->raycasting.sprite_create.invDet * (game->player.dir_y \
		 * game->raycasting.sprite_create.spriteX - game->player.dir_x \
		 * game->raycasting.sprite_create.spriteY);
	game->raycasting.sprite_create.transformY = \
		game->raycasting.sprite_create.invDet * (-game->player.plane_y \
		 * game->raycasting.sprite_create.spriteX + game->player.plane_x \
		 * game->raycasting.sprite_create.spriteY);
	game->raycasting.sprite_create.spriteScreenX = (int)((game->camera.ris_x \
		 / 2) * (1 + game->raycasting.sprite_create.transformX \
		 / game->raycasting.sprite_create.transformY));
	game->raycasting.sprite_create.spriteHeight = fabs((game->camera.ris_y \
		 / (game->raycasting.sprite_create.transformY)));
	game->raycasting.sprite_create.drawStartY = \
		 - game->raycasting.sprite_create.spriteHeight / 2 \
		 + game->camera.ris_y / 2;
}
