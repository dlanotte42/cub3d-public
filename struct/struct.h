/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlanotte <dlanotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/16 16:29:11 by dlanotte          #+#    #+#             */
/*   Updated: 2021/03/16 18:53:53 by dlanotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct  s_data {
    void        *img;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
}               t_data;

typedef struct  s_vars {
    void        *mlx;
    void        *win;
}               t_vars;

typedef struct	s_posi {
	int			X;
	int			Y;
}				t_posi;

typedef struct	s_player {
	int			up;
	int			down;
	int			right;
	int			left;
}				t_player;

typedef struct	s_custom{
	t_posi		position;
	t_vars		vars;
	t_data		img;
	t_player	movement;
}				t_custom;

#endif