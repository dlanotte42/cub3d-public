/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:43:37 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/18 19:06:32 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void ft_print(t_posi position, t_data img, int color)
{
	ft_put_pixel_base(&img, position.X, position.Y, color);
}

void	ft_create_square(t_custom *varsi, int height, char color)
{
	int i;
	int	j;
	t_posi original_position; 

	i = 0;
	j = 0;
	original_position = varsi->position;
	while(i < height)
	{
		while(j < height)
		{
			ft_print(varsi->position, varsi->img, select_color(color));
			varsi->position.X += 1;
			j++;
		}
		j = 0;
		varsi->position.X -= height;
		varsi->position.Y += 1;
		i++;
	}
	mlx_put_image_to_window(varsi->vars.mlx, varsi->vars.win, varsi->img.img, 0, 0);
	varsi->position = original_position;
}


int             onRelease(int keycode, t_custom *varsi)
{
	if (keycode == 13)
	{
		varsi->movement.up = 0;
	}
	else if(keycode == 1)
	{
		varsi->movement.down = 0;
	}
	else if(keycode == 0)
	{
		varsi->movement.left = 0;
	}
	else if(keycode == 2)
	{
		varsi->movement.right = 0;
	}
	return (1);
}

int             onPress(int keycode, t_custom *varsi)
{  
	if (keycode == 13)
	{
		varsi->movement.up = 1;
	}
	else if(keycode == 1)
	{
		varsi->movement.down = 1;
	}
	else if(keycode == 0)
	{
		varsi->movement.left = 1;
	}
	else if(keycode == 2)
	{
		varsi->movement.right = 1;
	}
	else if(keycode == 69)
	{
		varsi->movement.size++;
		varsi->movement.speed++;
	}
	else if(keycode == 78)
	{
		varsi->movement.size--;
		varsi->movement.speed--;
	}else if (keycode == 53){
		mlx_destroy_window(varsi->vars.mlx, varsi->vars.win);
	}
	printf("Code: %d! |  Position: X: %d. Y: %d\n", keycode, varsi->position.X, varsi->position.Y);
	return (0);
}

int		render_next_frame(t_custom *varsi)
{
	if (varsi->position.X > 1910)
		varsi->position.X = 11;
	if (varsi->position.Y > 1000)
		varsi->position.Y = 11;
	if (varsi->position.X < 10)
		varsi->position.X = 1910;
	if (varsi->position.Y < 10)
		varsi->position.Y = 1000;

	if (varsi->movement.up)
	{
		varsi->position.Y -= varsi->movement.speed;
	}
	if(varsi->movement.down)
	{
		varsi->position.Y += varsi->movement.speed;
	}
	if(varsi->movement.left)
	{
		varsi->position.X -= varsi->movement.speed;
	}
	if(varsi->movement.right)
	{
		varsi->position.X += varsi->movement.speed;
	}
	ft_create_square(varsi, varsi->movement.size, 'g');
	ft_re_create_img(varsi);
	return (0);
}

void	ft_init(t_custom varsi)
{
	varsi.vars.mlx = mlx_init();
    varsi.vars.win = mlx_new_window(varsi.vars.mlx, 1920, 1080, "Flavio Boomer!");
	varsi.img.img = mlx_new_image(varsi.vars.mlx, 1920, 1080);
	varsi.img.addr = mlx_get_data_addr(varsi.img.img, &varsi.img.bits_per_pixel, &varsi.img.line_length,
                                 &varsi.img.endian);
	mlx_put_image_to_window(varsi.vars.mlx, varsi.vars.win, varsi.img.img, 0, 0);
	mlx_hook(varsi.vars.win,2, 1L<<0, onPress, &varsi);	
	mlx_hook(varsi.vars.win,3, 1L<<0, onRelease, &varsi);	
	mlx_loop_hook(varsi.vars.mlx, render_next_frame, &varsi);
    mlx_loop(varsi.vars.mlx);
}


int main(void)
{
	t_custom		varsi;

	varsi.position.X = 100;
	varsi.position.Y = 100;
	varsi.movement.up = 0;
	varsi.movement.down = 0;
	varsi.movement.right = 0;
	varsi.movement.left = 0;
	varsi.movement.size = 50;
	varsi.movement.speed = 50;
	ft_init(varsi);
	free(varsi.img.img);	
	free(varsi.img.addr);
	free(varsi.vars.win);
}	


