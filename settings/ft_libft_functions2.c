/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_functions2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 19:34:58 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/13 19:41:46 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_strcpy(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	dest = ft_calloc(ft_strlen(src) + 1, 1);
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*new_src;
	size_t	size;
	size_t	i;

	size = ft_strlen(src);
	new_src = malloc((size + 1) * sizeof(char));
	if (!new_src)
		return (NULL);
	i = 0;
	while (src[i])
	{
		new_src[i] = src[i];
		i++;
	}
	new_src[i] = '\0';
	return (new_src);
}

static void	swap_double(double *xp, double *yp)
{
	double	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

static void	swap_int(int *xp, int *yp)
{
	int	temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void	sortSprites(int *order, double *dist, int amount)
{
	int	i;
	int	j;
	int	swapped;

	i = 0;
	while (i < (amount - 1))
	{
		swapped = 0;
		j = 0;
		while (j < (amount - i - 1))
		{
			if (dist[j] < dist[j + 1])
			{
				swap_int(&order[j], &order[j + 1]);
				swap_double(&dist[j], &dist[j + 1]);
				swapped = 1;
			}
			 j++;
		}
		if (swapped == 0)
			break ;
		i++;
	}
}
