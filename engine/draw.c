/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:00:35 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/13 20:43:39 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_put_pixel_base(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_get_pixel(t_textures *data, int x, int y)
{
	char	*dst;

	dst = data->texture_addr + (y * data->line_length
			 + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

void	ft_re_create_img(t_game *game)
{
	mlx_destroy_image(game->vars.mlx, game->img.img);
	game->img.img = mlx_new_image(game->vars.mlx,
			game->camera.ris_x, game->camera.ris_y);
	game->img.addr = mlx_get_data_addr(game->img.img,
			&game->img.bits_per_pixel, &game->img.line_length,
			&game->img.endian);
}
