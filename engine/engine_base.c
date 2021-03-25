/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:43:47 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/25 01:53:16 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void		ft_init_texture(t_game *game)
{
	int a,b,c;
	int i;

	i = 0;
	while (i < 10)
	{
		game->textures[i].texture = mlx_xpm_file_to_image(game->vars.mlx, game->textures[i].texture_path, 
			&game->textures[i].width, &game->textures[i].height);
		game->textures[i].texture_addr = mlx_get_data_addr(game->textures[i].texture, &a, &b, &c);
		i++;
	}
}

static	void	ft_print_w_a_t(t_game *game, int drawStart, int drawEnd, int lineHeight, int texX)
{
	int texY; 
	double step;
	double texPos;

	step = 1.0 * game->textures[1].height / lineHeight;
    texPos = (drawStart - game->camera.ris_y / 2 + lineHeight / 2) * step;

	while(game->raycasting.y < drawStart)
	{
		ft_put_pixel_base(&game->img, game->raycasting.x, game->raycasting.y, 0x888c8d);
		if (game->mods.Drunk)
			game->img.addr[game->raycasting.x * 4 + game->raycasting.y * game->camera.ris_x * 4 + 3] = (char)200; 
		game->raycasting.y++;
	}
	game->raycasting.y = drawStart;
	while(game->raycasting.y < drawEnd)
	{
		texY = (int)texPos & (game->textures[game->raycasting.textNum].height - 1);
		texPos += step;
		
		game->img.addr[(game->raycasting.x) * 4 + (4 * game->camera.ris_x * (game->raycasting.y))] = (int)(game->textures[game->raycasting.textNum].texture_addr[texX * 4 + 4 * game->textures[game->raycasting.textNum].width * texY ]);
		game->img.addr[(game->raycasting.x) * 4 + (4 * game->camera.ris_x * (game->raycasting.y)) + 1] = (int)(game->textures[game->raycasting.textNum].texture_addr[texX * 4 + 4 * game->textures[game->raycasting.textNum].width * texY + 1]);
		game->img.addr[(game->raycasting.x) * 4 + (4 * game->camera.ris_x * (game->raycasting.y)) + 2] = (int)(game->textures[game->raycasting.textNum].texture_addr[texX * 4 + 4 * game->textures[game->raycasting.textNum].width * texY + 2]);				
		if (game->mods.Drunk)
			game->img.addr[(game->raycasting.x) * 4 + (4 * game->camera.ris_x * (game->raycasting.y)) + 3] = (char) 200;
		game->raycasting.y++;
	}
	while(game->raycasting.y < game->camera.ris_y)
	{
		ft_put_pixel_base(&game->img, game->raycasting.x, game->raycasting.y, 0xcaa472);
		if (game->mods.Drunk)
			game->img.addr[game->raycasting.x * 4 + game->raycasting.y * game->camera.ris_x * 4 + 3] = (char)200; 
		game->raycasting.y++;
	}
}

void	ft_raycasting(t_game *game)
{
	int map[24][24]=
	{
		{1,1,1,1,1,1,2,3,4,5,6,7,8,1,1,1,1,1,1,1,1,1,1,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,8,8,8,8,8,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,8,0,0,0,0,3,0,0,0,3,0,0,0,1},
		{1,0,0,0,0,0,2,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,2,10,0,10,8,0,0,0,0,3,0,3,0,3,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	game->raycasting.x = 0;

	ft_init_texture(game);
	while(game->raycasting.x < game->camera.ris_x)
	{
		double wallX;
		int texX; 

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