/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:43:47 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/29 17:27:13 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		ft_init_texture(t_game *game)
{
	int i;

	i = 0;
	while (i < 10)
	{
		game->textures[i].texture = mlx_xpm_file_to_image(game->vars.mlx, game->textures[i].texture_path, 
			&game->textures[i].width, &game->textures[i].height);
		game->textures[i].texture_addr = mlx_get_data_addr(game->textures[i].texture, &game->textures[i].bits_per_pixel, &game->textures[i].line_length, &game->textures[i].endian);
		i++;
	}
}

static	void	ft_print_w_a_t(t_game *game, int drawStart, int drawEnd, int lineHeight, int texX)
{
	int 			texY; 
	double 			step;
	double 			texPos;
	unsigned int 	color;


	step = 1.0 * game->textures[game->raycasting.textNum].height / lineHeight;
    texPos = (drawStart - game->camera.ris_y / 2 + lineHeight / 2) * step;

	game->raycasting.y = drawStart;
	while(game->raycasting.y < drawEnd)
	{
		texY = (int)texPos & (game->textures[game->raycasting.textNum].height - 1);
		texPos += step;
		color = ft_get_pixel(&game->textures[game->raycasting.textNum], texX, texY);
		ft_put_pixel_base(&game->img, game->raycasting.x, game->raycasting.y, color);
		game->raycasting.y++;
	}
}

void	ft_raycasting(t_game *game)
{
	double wallX;
	int texX; 
	int map[24][24] = {
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,3,3,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,3,0,0,0,3,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,3,3,3,3,3,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	ft_init_texture(game);
    for(int y = game->camera.ris_y / 2 + 1; y < game->camera.ris_y; ++y)
    {
		game->raycasting.floor.rayDirX0 = game->player.dir_x - game->player.plane_x;
		game->raycasting.floor.rayDirY0 = game->player.dir_y - game->player.plane_y;
		game->raycasting.floor.rayDirX1 = game->player.dir_x + game->player.plane_x;
		game->raycasting.floor.rayDirY1 = game->player.dir_y + game->player.plane_y;
		game->raycasting.floor.p = y - game->camera.ris_y / 2;
		game->raycasting.floor.posZ = 0.5 * game->camera.ris_y;
		game->raycasting.floor.rowDistance = game->raycasting.floor.posZ / game->raycasting.floor.p;
		game->raycasting.floor.floorStepX = game->raycasting.floor.rowDistance * (game->raycasting.floor.rayDirX1 - game->raycasting.floor.rayDirX0) / game->camera.ris_x;
		game->raycasting.floor.floorStepY = game->raycasting.floor.rowDistance * (game->raycasting.floor.rayDirY1 - game->raycasting.floor.rayDirY0) / game->camera.ris_x;
		game->raycasting.floor.floorX = game->player.pos_x + game->raycasting.floor.rowDistance * game->raycasting.floor.rayDirX0;
		game->raycasting.floor.floorY = game->player.pos_y + game->raycasting.floor.rowDistance * game->raycasting.floor.rayDirY0;
		game->raycasting.floor.x = 0;
		
		while( game->raycasting.floor.x < game->camera.ris_x)
		{
			int cellX = (int)(game->raycasting.floor.floorX);
			int cellY = (int)(game->raycasting.floor.floorY);

			int tx = (int)(game->textures[5].width * (game->raycasting.floor.floorX - cellX)) & (game->textures[5].width - 1);
			int ty = (int)(game->textures[5].height * (game->raycasting.floor.floorY - cellY)) & (game->textures[5].height - 1);

			game->raycasting.floor.floorX += game->raycasting.floor.floorStepX;
			game->raycasting.floor.floorY += game->raycasting.floor.floorStepY;

			int checkerBoardPattern = (int)(cellX + cellY) & 1;
			int floorTexture;
			if(checkerBoardPattern == 0) floorTexture = 3;
			else floorTexture = 4;
			int color;

			color = ft_get_pixel(&game->textures[6], tx, ty);
			ft_put_pixel_base(&game->img, game->raycasting.floor.x, y, color);

			color = ft_get_pixel(&game->textures[6], tx, ty);
			ft_put_pixel_base(&game->img, game->raycasting.floor.x, (game->camera.ris_y - y - 1), 0x00ccff);
			game->raycasting.floor.x++;
		}
    }
	game->raycasting.x = 0;
	ft_init_texture(game);
	while(game->raycasting.x < game->camera.ris_x)
	{
		game = ft_raycast_zero(game, map);
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
		ft_move(game, map);
		game->raycasting.x++;
	}
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->img.img, 0, 0); 
}