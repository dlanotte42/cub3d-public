/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_base01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 00:00:59 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/15 19:39:59 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_print_floor(t_game *game, int y)
{
	int	color;
	int	cellX;
	int	cellY;
	int	tx;
	int	ty;

	while (game->raycasting.floor.x < game->camera.ris_x)
	{
		cellX = (int)(game->raycasting.floor.floorX);
		cellY = (int)(game->raycasting.floor.floorY);
		tx = (int)(game->textures[4].width * (game->raycasting.floor.floorX - cellX)) \
			 & (game->textures[4].width - 1);
		ty = (int)(game->textures[4].height * (game->raycasting.floor.floorY - cellY)) \
			 & (game->textures[4].height - 1);
		game->raycasting.floor.floorX += game->raycasting.floor.floorStepX;
		game->raycasting.floor.floorY += game->raycasting.floor.floorStepY;
		color = ft_get_pixel(&game->textures[4], tx, ty);
		ft_put_pixel_base(&game->img, game->raycasting.floor.x, y, color);
		color = ft_get_pixel(&game->textures[4], tx, ty);
		ft_put_pixel_base(&game->img, game->raycasting.floor.x, \
			(game->camera.ris_y - y - 1), 0x00ccff);
		game->raycasting.floor.x++;
	}
}

static void	ft_print_w_a_t(t_game *game, int drawStart, int drawEnd, int texX)
{
	int				texY;
	double			step;
	double			texPos;
	unsigned int	color;
	int				lineHeight;

	lineHeight = game->raycasting.Addvalues.lineheight;
	step = 1.0 * game->textures[game->raycasting.textNum].height / lineHeight;
	texPos = (drawStart - game->camera.ris_y / 2 + lineHeight / 2) * step;
	game->raycasting.y = drawStart;
	while (game->raycasting.y < drawEnd)
	{
		texY = (int)texPos \
			 & (game->textures[game->raycasting.textNum].height - 1);
		texPos += step;
		color = ft_get_pixel(&game->textures[game->raycasting.textNum], \
			texX, texY);
		ft_put_pixel_base(&game->img, game->raycasting.x, \
			game->raycasting.y, color);
		game->raycasting.y++;
	}
}

double	*ft_raycasting_extra(t_game *game, double *ZBuffer, int texX)
{
	double	wallX;

	while (game->raycasting.x < game->camera.ris_x)
	{
		game = ft_raycast_zero(game, game->map);
		if (game->raycasting.side == 0)
			wallX = game->player.pos_y + game->raycasting.perpWallDist \
				 * game->raycasting.rayDirY;
		else
			wallX = game->player.pos_x + game->raycasting.perpWallDist \
				 * game->raycasting.rayDirX;
		wallX -= floor((wallX));
		texX = (int)(wallX * (double) \
		(game->textures[game->raycasting.textNum].width));
		if (game->raycasting.side == 0 && game->raycasting.rayDirX > 0)
			texX = game->textures[game->raycasting.textNum].width - texX - 1;
		if (game->raycasting.side == 1 && game->raycasting.rayDirY < 0)
			texX = game->textures[game->raycasting.textNum].width - texX - 1;
		ft_print_w_a_t(game, game->raycasting.Addvalues.drawStart, \
			game->raycasting.Addvalues.drawEnd, texX);
		ft_move(game, game->map);
		ZBuffer[game->raycasting.x] = game->raycasting.perpWallDist;
		game->raycasting.x++;
	}
	return (ZBuffer);
}

void	ft_cs(t_game *game, int numSprites, double *ZBuffer, int *spriteOrder)
{
	game->raycasting.sprite_create.i = 0;
	while (game->raycasting.sprite_create.i < numSprites)
	{
		ft_cs_one(game, spriteOrder);
		ft_cs_check(game);
		while (game->raycasting.sprite_create.stripe < \
		game->raycasting.sprite_create.drawEndX)
		{
			game->raycasting.sprite_create.texX = (int)(256 * \
				(game->raycasting.sprite_create.stripe - \
				(-game->raycasting.sprite_create.spriteWidth / 2 \
				 + game->raycasting.sprite_create.spriteScreenX)) \
				 * game->textures[5].width / \
				game->raycasting.sprite_create.spriteWidth) / 256;
			if (game->raycasting.sprite_create.transformY > 0 && \
			game->raycasting.sprite_create.stripe > 0 && \
			game->raycasting.sprite_create.stripe < game->camera.ris_x && \
			game->raycasting.sprite_create.transformY < \
			ZBuffer[game->raycasting.sprite_create.stripe])
				ft_put_sprite(game);
			game->raycasting.sprite_create.stripe++;
		}
		game->raycasting.sprite_create.i++;
	}
}
