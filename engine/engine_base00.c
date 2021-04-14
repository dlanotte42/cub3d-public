/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_base00.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:43:47 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/15 00:41:09 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	ft_init_texture(t_game *game)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		game->textures[i].texture = mlx_xpm_file_to_image(game->vars.mlx, \
			game->textures[i].texture_path, &game->textures[i].width, \
			&game->textures[i].height);
		game->textures[i].texture_addr = mlx_get_data_addr \
			(game->textures[i].texture, &game->textures[i].bits_per_pixel, \
			&game->textures[i].line_length, &game->textures[i].endian);
		i++;
	}
}

static	void	ft_print_w_a_t(t_game *game, int drawStart, int drawEnd, int lineHeight, int texX)
{
	int				texY;
	double			step;
	double			texPos;
	unsigned int	color;

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

static	void	ft_print_floor(t_game *game, int y)
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

void	ft_raycasting(t_game *game)
{
	double wallX;
	int texX; 
	int numSprites;
	double *ZBuffer;
	int *spriteOrder;
	double *spriteDistance;
	int y;
	int	i;

	ZBuffer = malloc(sizeof(double) * game->camera.ris_x);
	numSprites = game->sprites_counter;
	spriteOrder = malloc(sizeof(int) * numSprites);
	spriteDistance = malloc(sizeof(double) * numSprites);
	ft_init_texture(game);
	y = game->camera.ris_y / 2 + 1;
    while( y < game->camera.ris_y)
    {
		ft_floor_casting(game, y);
		y++;
    }
	game->raycasting.x = 0;
	ft_init_texture(game);
	while(game->raycasting.x < game->camera.ris_x)
	{
		game = ft_raycast_zero(game, game->map);
		if (game->mods.Wall_rotate)
		{
			if(game->raycasting.side == 0) 
				wallX = game->player.pos_x + game->raycasting.perpWallDist * game->raycasting.rayDirY; 
			else          					
				wallX = game->player.pos_x + game->raycasting.perpWallDist * game->raycasting.rayDirX; 
		}
		else
		{
			if(game->raycasting.side == 0) 
				wallX = game->player.pos_y + game->raycasting.perpWallDist * game->raycasting.rayDirY;
			else          					
				wallX = game->player.pos_x + game->raycasting.perpWallDist * game->raycasting.rayDirX;
		}
		wallX -= floor((wallX));
		texX = (int)(wallX * (double)(game->textures[game->raycasting.textNum].width));
		if(game->raycasting.side == 0 && game->raycasting.rayDirX > 0) 
			texX = game->textures[game->raycasting.textNum].width - texX - 1;
		if(game->raycasting.side == 1 && game->raycasting.rayDirY < 0) 
			texX = game->textures[game->raycasting.textNum].width - texX - 1;
		ft_print_w_a_t(game, game->raycasting.Addvalues.drawStart, 
			game->raycasting.Addvalues.drawEnd, game->raycasting.Addvalues.lineheight, texX);
		ft_move(game, game->map);
		ZBuffer[game->raycasting.x] = game->raycasting.perpWallDist;
		game->raycasting.x++;
	}
	i = 0;
	while(i < numSprites)
    {
      	spriteOrder[i] = i;
      	spriteDistance[i] = ((game->player.pos_x - game->sprites[i].x) \
		  * (game->player.pos_x - game->sprites[i].x) + (game->player.pos_y \
		  - game->sprites[i].y) * (game->player.pos_y - game->sprites[i].y));
		i++;
	}
    sortSprites(spriteOrder, spriteDistance, numSprites);
	ft_sprite_create(game, numSprites, ZBuffer, spriteOrder);
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->img.img, 0, 0);
}