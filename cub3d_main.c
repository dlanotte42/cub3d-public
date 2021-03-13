/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 16:43:37 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/13 19:39:50 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilibx/mlx.h"
#include "includes/cub3d.h"
#include <stdio.h>

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

void ft_putpixel(t_posi position, t_data img )
{
	my_mlx_pixel_put(&img, position.X, position.Y, 0x006E50);
}

int				ft_action(int keycode)
{
	printf("Ciao");
	printf("Hello from key_hook %d!\n", keycode);
	
	// W = 13
	// A = 0
	// S = 1
	// D = 2

	
	return (1);
}

int             key_hook(int keycode, t_vars *vars)
{  
	if (keycode == 53)
		mlx_destroy_window(vars->mlx, vars->win);
	else{
		ft_action(keycode);
	}
	return (1);
}

int main(void)
{

    t_vars		vars;
	//t_posi		position;


    vars.mlx = mlx_init();
    vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	mlx_key_hook(vars.win, key_hook, &vars);	

    mlx_loop(vars.mlx);
}


