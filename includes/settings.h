/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:43:58 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/17 17:56:31 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETTINGS_H
# define SETTINGS_H

# include "cub3d.h"

void		ft_set_parameters(t_game *game, int argc, char **argv);
t_game		*ft_raycast_set_block(t_game *game);
int			ft_atoi(const char *str);
int			ft_isdigit(int c);
char		**ft_split(char const *s, char c);
t_config	ft_parsing(int ac, char **av);
void		*ft_calloc(size_t count, size_t size);
char		*ft_strcpy(char *src);
char		*ft_strdup(const char *src);
int			**ft_convert(t_config *config);
void		sortSprites(int *order, double *dist, int amount);
int			ft_strcmp(const char *s1, const char *s2);
void		config_init(t_config *config);
void		check_floor(t_config *config);
int			ft_check_file(char *file);
void		check_cielo(t_config *config);
int			parse_line(char **array, t_config *config);
t_config	ft_init_parse_one(int ac, char **av, t_pars pars, t_config config);
char		**ft_create_map(t_config config, char *str, int map_line);
int			ft_check_maps(char *maps);
char		*ft_strcpy_custom(char *src);
t_config	*ft_s_pla_start(int map_position, t_config \
				*config, int x, int y);
size_t		ft_intlen(int *str);
int			is_map_valid(t_config *config);
t_config	is_valid(t_config config);
int			ft_check_array(char **array);
int			ft_check_rgb(int r, int g, int b);

#endif