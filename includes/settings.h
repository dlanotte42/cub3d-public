/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:43:58 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/03/25 00:29:07 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include "cub3d.h"

void		ft_set_parameters(t_game *game);
t_game		*ft_raycast_set_block(t_game *game, int map[24][24]);

#endif