/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing00.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/03 17:49:05 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/17 18:44:22 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_config	ft_init_parse_two(t_pars pars, t_config config, char *line)
{
	while (get_next_line(pars.c_fd, &line) > 0)
	{
		config.array = ft_split(line, ' ');
		if (ft_check_maps(*config.array))
		{
			config.map = ft_create_map(config, line, config.map_line);
			config.map_line++;
		}
		else
			parse_line(config.array, &config);
		free(line);
		free(config.array);
	}
	free(line);
	line = NULL;
	close(pars.c_fd);
	return (config);
}

t_config	ft_init_parse_one(int ac, char **av, t_pars pars, t_config config)
{
	char		*line;

	if (ac == 3 && ft_strcmp(av[2], "--save") == 0)
	{
		printf("screenshot saved to /screenshot/screenshot.bmp\n");
		config.screenshot = TRUE;
	}
	if (!ft_check_file(av[pars.x]))
	{
		write(1, "the selected file is not correct.\n", 37);
		return (config);
	}
	pars.c_fd = open(av[pars.x], O_RDONLY);
	if (pars.c_fd < 0)
		return (config);
	line = NULL;
	config_init(&config);
	config = ft_init_parse_two(pars, config, line);
	return (config);
}

static t_config	*ft_support_convert(t_config *config, int j, int i, int len)
{
	while (j < len)
	{
		config = ft_s_pla_start(config->map[i][j], config, i, j);
		if (config->map[i][j] == ' ')
			config->map_def[i][j] = 1;
		else if (config->map[i][j] == '2')
			config->number_sprite++;
		else if (config->map[i][j] == 'N' || config->map[i][j] == 'S'
			|| config->map[i][j] == 'W' || config->map[i][j] == 'E')
			config->map_def[i][j] = 0;
		else
			config->map_def[i][j] = (config->map[i][j] - 48);
		j++;
	}
	return (config);
}

int	**ft_convert(t_config *config)
{
	int		i;
	int		len;
	int		j;

	j = 0;
	i = 0;
	len = 0;
	config->number_sprite = 0;
	config->map_def = ft_calloc(config->map_line, sizeof(int *));
	while (i < config->map_line)
	{
		len = ft_strlen(config->map[i]);
		config->map_def[i] = ft_calloc(len, sizeof(int));
		config = ft_support_convert(config, j, i, len);
		j = 0;
		i++;
	}
	return (config->map_def);
}

char	*ft_strcpy_custom(char *src)
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
