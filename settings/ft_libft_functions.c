/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_functions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 17:49:42 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/13 19:44:07 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(const char *str)
{
	int						is_negative;
	unsigned long long		result;

	result = 0;
	is_negative = 1;
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t'
			|| *str == '\v' || *str == '\f' || *str == '\r'))
		str++;
	if (*str == '-')
		is_negative = -1;
	if (*str == '+' || *str == '-')
		str++;
	while (*str && ft_isdigit(*str))
	{
		result = result * 10 + (*str - 48);
		if (result >= 9223372036854775808ULL)
		{
			if (is_negative == 1)
				return (-1);
			else
				return (0);
		}
		str++;
	}
	return ((int)result * is_negative);
}

static void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char	*pointer;

	pointer = str;
	while (n)
	{
		*pointer = c;
		pointer++;
		n--;
	}
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*home;

	home = malloc(count * size);
	if (home)
		ft_memset(home, 0, (count * size));
	return (home);
}
