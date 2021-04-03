/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:56:09 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/03 18:10:15 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "cub3d.h"

void            ft_put_pixel_base(t_data *data, int x, int y, int color);
void			ft_re_create_img(t_game *game);
void			ft_raycasting(t_game *game);
t_game			*ft_raycast_zero(t_game *game, int **map);
unsigned int    ft_get_pixel(t_textures *data, int x, int y);

#endif