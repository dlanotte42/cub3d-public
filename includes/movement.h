/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:58:08 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/03 18:10:46 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H

# include "cub3d.h"

int				onPressButton(int keycode, t_game *game);
int				onReleseButton(int keycode, t_game *game);
void			ft_move(t_game *game, int **map);

#endif