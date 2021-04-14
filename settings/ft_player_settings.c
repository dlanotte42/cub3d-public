/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_player_settings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 21:11:55 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/14 22:28:43 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_config	*ft_s_pla_start(int map_position, t_config *config, int x, int y)
{
	if (map_position == 'N' || map_position == 'S' \
		 || map_position == 'W' || map_position == 'E')
	{
		config->start_x = x;
		config->start_y = y;
		config->direction = map_position;
	}
	return (config);
}
