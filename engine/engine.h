/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:27:20 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/16 17:18:27 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENGINE_H
# define ENGINE_H
# include "../cub3d.h"
# include "../struct/struct.h"

void            ft_put_pixel_base(t_data *data, int x, int y, int color);
void			ft_re_create_img(t_custom *varsi);
int				select_color(char color);

#endif