/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:58:08 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/25 00:07:42 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H

# include "cub3d.h"

int				onPressButton(int keycode, t_game *game);
int				onReleseButton(int keycode, t_game *game);
void			ft_move(t_game *game, int map[24][24]);

#endif