/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:58:08 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/22 18:43:38 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H

# include "cub3d.h"

//void			ft_move(t_game *game);
int				onPressButton(int keycode, t_game *game);
int				onReleseButton(int keycode, t_game *game);

#endif