/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_base01.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 00:00:59 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/15 00:41:22 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_sprite_create(t_game *game, int numSprites, double *ZBuffer, int *spriteOrder)
{
	int i;
	int stripe;
	double spriteX;
	double spriteY;
	double invDet;
	double transformX;
	double transformY;
	int color;
	int y;

	i = 0;
	while( i < numSprites)
    {
      spriteX = game->sprites[spriteOrder[i]].x - game->player.pos_x;
      spriteY = game->sprites[spriteOrder[i]].y - game->player.pos_y;

      	invDet = 1.0 / (game->player.plane_x * game->player.dir_y - game->player.dir_x * game->player.plane_y); 
      	transformX = invDet * (game->player.dir_y * spriteX - game->player.dir_x * spriteY);
      	transformY = invDet * (-game->player.plane_y * spriteX + game->player.plane_x * spriteY); 
      	int spriteScreenX = (int)((game->camera.ris_x / 2) * (1 + transformX / transformY));
      	int spriteHeight = fabs((game->camera.ris_y / (transformY)));
      	int drawStartY = -spriteHeight / 2 + game->camera.ris_y / 2;
      	if(drawStartY < 0) 
			drawStartY = 0;
      	int drawEndY = spriteHeight / 2 +game->camera.ris_y / 2;
      	if(drawEndY >= game->camera.ris_y) 
		  	drawEndY = game->camera.ris_y - 1;
      	int spriteWidth = fabs((game->camera.ris_y / (transformY)));
      	int drawStartX = -spriteWidth / 2 + spriteScreenX;
      	if(drawStartX < 0)
		  	drawStartX = 0;
      	int drawEndX = spriteWidth / 2 + spriteScreenX;
      	if(drawEndX >= game->camera.ris_x) 
			drawEndX = game->camera.ris_x - 1;
		stripe = drawStartX;
      while( stripe < drawEndX)
      {
        int texX = (int)(256 * (stripe - (-spriteWidth / 2 + spriteScreenX)) * game->textures[5].width / spriteWidth) / 256;
        if(transformY > 0 && stripe > 0 && stripe < game->camera.ris_x && transformY < ZBuffer[stripe])
        {
			y = drawStartY;
			while(y < drawEndY) 
        	{
        		int d = y * 256 - game->camera.ris_y * 128 + spriteHeight * 128; 
        		int texY = ((d * game->textures[5].height) / spriteHeight) / 256;
				color = ft_get_pixel(&game->textures[5], texX, texY);
        		if((color & 0xFFFFFF) != 0) 
					ft_put_pixel_base(&game->img, stripe, y, color);
				y++;
        	}
	  	}
		stripe++;
	  }
	  i++;
	}
}