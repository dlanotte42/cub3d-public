/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:56:09 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/15 02:10:46 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H

# include "cub3d.h"

void			ft_put_pixel_base(t_data *data, int x, int y, int color);
void			ft_re_create_img(t_game *game);
void			ft_raycasting(t_game *game);
t_game			*ft_raycast_zero(t_game *game, int **map);
unsigned int	ft_get_pixel(t_textures *data, int x, int y);
void			screenshot(t_game *s);
unsigned int	ft_get_pixel_camera(t_data *data, int x, int y);
void			ft_check_texture(t_game *game, t_config *config);
void			ft_cs(t_game *game, int numSprites, double \
					*ZBuffer, int *spriteOrder);
double			*ft_raycasting_extra(t_game *game, double *ZBuffer, int texX);
void			ft_init_texture(t_game *game);
void			ft_print_floor(t_game *game, int y);
void			ft_cs_one(t_game *game, int *spriteOrder);
void			ft_cs_check(t_game *game);
void			ft_put_sprite(t_game *game);

#endif