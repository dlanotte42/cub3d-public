/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing01.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:53:45 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/13 21:19:14 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int 	ft_check_file(char *file)
{
	while (*file)
	{
		if (*file == '.')
		{
			file++;
			if (*file == 'c')
			{
				file++;
				if (*file == 'u')
				{
					file++;
					if (*file == 'b')
					{
						file++;
						if (*file == 0)
							return (1);
					}
				}
			}
		}
		file++;
	}
	return (0);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((((unsigned char *)s1)[i] == ((unsigned char *)s2)[i])
			&& (s1[i] != '\0') && (s2[i] != '\0'))
		i++;
	if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		return ((int)(((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]));
	else
		return (0);
}

void	config_init(t_config *config)
{
	config->ris_x = 1920;
	config->ris_y = 1080;
	config->c_color = 0x89F1F1;
	config->f_color = 0xBABBBB;
	config->n_wall = "../textures/mariowall1.xpm";
}

void	check_floor(char **array, t_config *config)
{
	int				r;
	int				g;
	int				b;
	unsigned long	color;
	char			**array2;

	array2 = ft_split(config->array[1], ',');
	r = ft_atoi(array2[0]);
	g = ft_atoi(array2[1]);
	b = ft_atoi(array2[2]);
	color = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	config->f_color = color;
	free(array2);
}

void	check_cielo(char **array, t_config *config)
{
	int				r;
	int				g;
	int				b;
	unsigned long	color;
	char			**array2;

	array2 = ft_split(config->array[1], ',');
	r = ft_atoi(array2[0]);
	g = ft_atoi(array2[1]);
	b = ft_atoi(array2[2]);
	color = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	config->c_color = color;
	free(array2);
}
