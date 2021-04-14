/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing03.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 20:58:03 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/14 21:38:11 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_ris(t_config *config)
{
	int				x;
	int				y;

	x = ft_atoi(config->array[1]);
	y = ft_atoi(config->array[2]);
	if ((x > 0 && x <= 2560) && (y >= 0 && y <= 1440))
	{
		config->ris_x = x;
		config->ris_y = y;
		return (0);
	}
	else
	{	
		write(1, "Risoluzione non valida\n", 23);
		return (-1);
	}
}

int	check_texture(char **array, t_config *config)
{
	if (array[0][0] == 'N' && array[0][1] == 'O')
		config->n_wall = ft_strdup(array[1]);
	else if (array[0][0] == 'S' && array[0][1] == 'O')
		config->s_wall = ft_strdup(array[1]);
	else if (array[0][0] == 'W' && array[0][1] == 'E')
		config->w_wall = ft_strdup(array[1]);
	else if (array[0][0] == 'E' && array[0][1] == 'A')
		config->e_wall = ft_strdup(array[1]);
	else if (array[0][0] == 'S' && array[0][1] == 0)
		config->sprite_tex = ft_strdup(array[1]);
	return (0);
}

int	parse_line(char **array, t_config *config)
{
	if (*config->array == NULL)
		return (0);
	if (config->array[0][0] == 'R' && array[0][1] == 0)
		check_ris(config);
	else if (config->array[0][0] == 'F' && array[0][1] == 0)
		check_floor(config);
	else if (config->array[0][0] == 'C' && array[0][1] == 0)
		check_cielo(config);
	else if (config->array[0][0] == 'N' && config->array[0][1] == 'O')
		check_texture(array, config);
	else if (config->array[0][0] == 'S' && config->array[0][1] == 'O')
		check_texture(array, config);
	else if (config->array[0][0] == 'W' && config->array[0][1] == 'E')
		check_texture(array, config);
	else if (config->array[0][0] == 'E' && config->array[0][1] == 'A')
		check_texture(array, config);
	else if (config->array[0][0] == 'S')
		check_texture(array, config);
	return (0);
}

size_t	ft_intlen(int *str)
{
	size_t	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}
