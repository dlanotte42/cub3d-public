/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsec.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 14:45:41 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/27 16:42:31 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*ft_jump_space(char *str)
{
	while (*str && (*str == ' ' || *str == '\n' || *str == '\t' ||
		*str == '\v' || *str == '\f' || *str == '\r'))
	str++;
	return (str);
}

int		ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

int		ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int				ft_find_number(char *str)
{
	int		number = 0;
	int		j = 0;
    while(ft_isdigit(*str))
    {
        number = number * 10 + (*str - 48);
        str++;
    }
	return (number);
}


void	ft_check_resolution(char *str)
{
	int cameraX;
	int	cameraY;

	cameraY = 0;
	cameraX = 0;
	str = ft_jump_space(str);
	while(ft_isalpha(*str))
	{
		if (*str == 'R')
		{
			str++;
			str = ft_jump_space(str);
			if (ft_isdigit(*str))
				cameraX = ft_find_number(str);
			else 
				; //ERROR
			while(ft_isdigit(*str))
				str++;
			str = ft_jump_space(str);
			
			if (ft_isdigit(*str))
				cameraY = ft_find_number(str);
			else
				;//ERRROR
		}
		str++;
	}
	printf("X: %d\nY: %d", cameraX, cameraY);
}

int 	main(void)
{
	int		fd;
	char 	*line;
	int		r;

	r = 0;
	fd = 0;
	r = get_next_line(fd, &line);
	ft_check_resolution(line);

	/*while((r = get_next_line(fd, &line)) > 0)
	{
		printf("%s\n", line);
		r = 0;
		free(line);
	}*/
	return (0);
}