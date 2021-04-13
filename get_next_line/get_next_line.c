/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:14:12 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/13 22:21:05 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_get_save_c(char *save_c)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save_c)
		return (0);
	while (save_c[i] && save_c[i] != '\n')
		i++;
	if (!save_c[i])
	{
		free(save_c);
		return (0);
	}
	result = (malloc(sizeof(char) * ((ft_strlen(save_c) - i) + 1)));
	if (!result)
		return (0);
	i++;
	while (save_c[i])
		result[j++] = save_c[i++];
	result[j] = '\0';
	free(save_c);
	return (result);
}

char	*ft_get_line(char *str)
{
	int		i;
	char	*result;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

int		get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*save_c;
	int				reader;
	int				buffer;

	buffer = 32;
	reader = 1;
	if (fd < 0 || !line || buffer <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (buffer + 1))))
		return (-1);
	while (!ft_return(save_c) && reader != 0)
	{
		if ((reader = read(fd, buff, buffer)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[reader] = '\0';
		save_c = join_str(save_c, buff);
	}
	free(buff);
	*line = ft_get_line(save_c);
	save_c = ft_get_save_c(save_c);
	if (reader == 0)
		return (0);
	return (1);
}