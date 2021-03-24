/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 14:43:47 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/24 16:00:33 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_print_wall(t_game *game)
{
	int map[24][24]=
	{
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
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
	};
	int 		y;
	int 		x = 0;
	double		cameraX;
	double		rayDirX;
	double		rayDirY;

	int 		mapX;
    int 		mapY;

	double 		sideDistX;
    double 		sideDistY;

	double 		deltaDistX;
    double 		deltaDistY;
    double 		perpWallDist;

	int 		stepX;
	int 		stepY;

	int			hit;
	int 		side;

	double 		oldDirX;
	double 		oldPlaneX;
	while(x < game->camera.ris_x)
	{
		y = 0;
		cameraX = 2 * x / (double)game->camera.ris_x - 1;	
		rayDirX = game->player.dir_x + game->player.plane_x * cameraX; 
		rayDirY = game->player.dir_y + game->player.plane_y * cameraX;

		mapX = (int)game->player.pos_x;
		mapY = (int)game->player.pos_y;

		deltaDistX = fabs(1 / rayDirX);
		deltaDistY = fabs(1 / rayDirY);
		hit = 0;

		if(rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->player.pos_x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->player.pos_x) * deltaDistX;
		}
		
		if(rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->player.pos_y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->player.pos_y) * deltaDistY;
		}

		while (hit == 0)
		{
			if(sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if(map[mapX][mapY] > 0) 
				hit = 1;
		}

		if(side == 0) 
			perpWallDist = (mapX - game->player.pos_x + (1 - stepX) / 2) / rayDirX;
		else          
			perpWallDist = (mapY - game->player.pos_y + (1 - stepY) / 2) / rayDirY;
		int lineHeight = (int)(game->camera.ris_y / perpWallDist);

		int drawStart = -lineHeight / 2 + game->camera.ris_y / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + game->camera.ris_y / 2;
		if(drawEnd >= game->camera.ris_y)
			drawEnd = game->camera.ris_y - 1;

		int color;
		switch(map[mapX][mapY])
		{
			case 1:  color = 0xFF9021;   break; //orange
			case 2:  color = 0x00ff00;  break; //green
			case 3:  color = 0x0000ff;   break; //blue
			case 4:  color = 0xffffff;  break; //white
			default: color = 0x000000; break; //yellow
		}

		if(side == 1)
			color = color / 2;

		while(y < drawStart)
		{
			ft_put_pixel_base(&game->img, x, y, 0x6D98FF);
			y++;
		}
		y = drawStart;
		while (y < drawEnd)
		{
			ft_put_pixel_base(&game->img, x, y, color);
			y++;
		}
		while(y < game->camera.ris_y)
		{
			ft_put_pixel_base(&game->img, x, y, 0xFFFF00);
			y++;
		}

		if (game->movement.right)
		{
			if(!(map[(int)(game->player.pos_x + game->player.dir_y * game->player.speed)][(int)(game->player.pos_y)]))
				game->player.pos_x += game->player.dir_y * game->player.speed;
			if(!(map[(int)(game->player.pos_x)][(int)(game->player.pos_y - game->player.dir_x * game->player.speed)]))
				game->player.pos_y -= game->player.dir_x * game->player.speed;
		}

		if (game->movement.left)
		{
			if(!(map[(int)(game->player.pos_x - game->player.dir_y * game->player.speed)][(int)(game->player.pos_y)]))
				game->player.pos_x -= game->player.dir_y * game->player.speed;
			if(!(map[(int)(game->player.pos_x)][(int)(game->player.pos_y + game->player.dir_x * game->player.speed)]))
				game->player.pos_y += game->player.dir_x * game->player.speed;
		}

		if (game->movement.up)
		{
			if(!(map[(int)(game->player.pos_x + game->player.dir_x * game->player.speed)][(int)game->player.pos_y]))
			 	game->player.pos_x += game->player.dir_x * game->player.speed;
			if(!(map[(int)(game->player.pos_x)][(int)(game->player.pos_x + game->player.dir_y * game->player.speed)]))
				 game->player.pos_y += game->player.dir_y * game->player.speed;
		}
		if (game->movement.down)
		{
			if(!(map[(int)(game->player.pos_x - game->player.dir_x * game->player.speed)][(int)(game->player.pos_y)])) 
				game->player.pos_x -= game->player.dir_x * game->player.speed;
      		if(!(map[(int)(game->player.pos_x)][(int)(game->player.pos_y - game->player.dir_y * game->player.speed)])) 
			  	game->player.pos_y -= game->player.dir_y * game->player.speed;
		}

		if (game->movement.cam_right)
		{
			oldDirX = game->player.dir_x;
			game->player.dir_x = game->player.dir_x * cos(-game->player.rotation_speed) - game->player.dir_y * sin(-game->player.rotation_speed);
			game->player.dir_y = oldDirX * sin(-game->player.rotation_speed) + game->player.dir_y * cos(-game->player.rotation_speed);
			oldPlaneX = game->player.plane_x;
			game->player.plane_x = game->player.plane_x * cos(-game->player.rotation_speed) - game->player.plane_y * sin(-game->player.rotation_speed);
			game->player.plane_y = oldPlaneX * sin(-game->player.rotation_speed) + game->player.plane_y * cos(-game->player.rotation_speed);
		}
		if (game->movement.cam_left)
		{
			oldDirX = game->player.dir_x;
			game->player.dir_x = game->player.dir_x * cos(game->player.rotation_speed) - game->player.dir_y * sin(game->player.rotation_speed);
			game->player.dir_y = oldDirX * sin(game->player.rotation_speed) + game->player.dir_y * cos(game->player.rotation_speed);
			oldPlaneX = game->player.plane_x;
			game->player.plane_x = game->player.plane_x * cos(game->player.rotation_speed) - game->player.plane_y * sin(game->player.rotation_speed);
			game->player.plane_y = oldPlaneX * sin(game->player.rotation_speed) + game->player.plane_y * cos(game->player.rotation_speed);
		}
		x++;
	}
	mlx_put_image_to_window(game->vars.mlx, game->vars.win, game->img.img, 0, 0); 
}