/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_engine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:00:35 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/16 19:49:15 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "engine.h"

void            ft_put_pixel_base(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
	free(dst);
}

void			ft_re_create_img(t_custom *varsi)
{
	mlx_destroy_image(varsi->vars.mlx, varsi->img.img);
	varsi->img.img = mlx_new_image(varsi->vars.mlx, 1920, 1080);
	varsi->img.addr = mlx_get_data_addr(varsi->img.img, 
	&varsi->img.bits_per_pixel, &varsi->img.line_length, &varsi->img.endian);
}

int				select_color(char color)
{
	if (color == 'g')
		return (5016882);
	else if (color == 'r')
		return (217469);
	else if (color == 'b')
		return (390252);
	return (16711680);
}