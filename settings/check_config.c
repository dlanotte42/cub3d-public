/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 16:04:50 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/17 18:51:32 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	errorn(int number)
{
	if (number == 1)
		printf("\n\x1b[31mRisoluzione non valida\033[0m");
	else if (number == 2)
		printf("\n\x1b[31mColore del cielo o del pavimento non valido\033[0m");
	else if (number == 3)
		printf("\n\x1b[31mUna delle texture dei muri non e' valida\033[0m");
	else if (number == 4)
		printf("\n\x1b[31mLa mappa non e' valida\033[0m");
	else if (number == 5)
		printf("\n\x1b[31mLa mappa o la sprite non e' valida\033[0m");
	else if (number == 6)
		printf("\n\x1b[31mErrore nello spawn del player\033[0m");
	else
		printf("\n\x1b[31mErrore sconosciuto\033[0m");
	return (0);
}

static int	is_config_valid(t_config config)
{
	if (config.ris_x == 0 || config.ris_x > 2560)
		return (errorn(1));
	if (config.ris_y == 0 || config.ris_y > 1440)
		return (errorn(1));
	if (config.f_color == 0 || config.c_color == 0)
		return (errorn(2));
	if (!config.n_wall || !config.s_wall || !config.e_wall || !config.w_wall)
		return (errorn(3));
	if (!config.sprite_tex || !config.map)
		return (errorn(5));
	if (config.map_line == 0)
		return (errorn(4));
	if (config.start_x == 0 && config.direction == '\0')
		return (errorn(6));
	return (1);
}

t_config	is_valid(t_config config)
{
	int	valid;

	valid = is_map_valid(&config);
	fflush(stdout);
	if (valid == 1)
	{
		if (is_config_valid(config))
			config.start_game = TRUE;
		else
			printf("\nConfigurazione non valida");
	}
	else
		printf("\nMappa non valida");
	return (config);
}

int	ft_check_rgb(int r, int g, int b)
{
	if ((r < 0 || r > 255))
		return (errorn(2));
	if ((g < 0 || g > 255))
		return (errorn(2));
	if ((b < 0 || b > 255))
		return (errorn(2));
	return (1);
}

int	ft_check_array(char **array)
{
	if (array[0] && array[1] && array[2])
		return (1);
	return (0);
}
