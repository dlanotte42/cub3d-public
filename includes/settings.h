/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 23:43:58 by zxcvbinz          #+#    #+#             */
/*   Updated: 2021/04/03 17:03:04 by dlanotte         ###   ########.fr       */
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
t_config 	ft_parsing(int ac, char **av);
void		*ft_calloc(size_t count, size_t size);
char 		*ft_strcpy(char *src);
char		*ft_strdup(const char *src);

#endif