/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:14:12 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/14 17:35:17 by dlanotte         ###   ########.fr       */
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

static char	*support_get(int fd, char **line)
{
	char	*buff;

	if (fd < 0 || !line)
		return (NULL);
	buff = malloc(sizeof(char) * (32 + 1));
	if (!buff)
		return (NULL);
	return (buff);
}

int	get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*save_c;
	int				reader;

	buff = support_get(fd, line);
	if (!buff)
		return (-1);
	reader = 1;
	while (!ft_return(save_c) && reader != 0)
	{
		reader = read(fd, buff, 32);
		if (reader == -1)
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
