/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zxcvbinz <zxcvbinz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/22 16:52:41 by dlanotte          #+#    #+#             */
/*   Updated: 2021/04/03 00:48:51 by zxcvbinz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define W_KEY 13

# define UP_KEY 126
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define LEFT_KEY 123
# define RUN_KEY 257

# define DRUNK_KEY 32
# define TAP_KEY 17

# define TRUE 1
# define FALSE 0

typedef struct  s_data {
    void        	*img;
    char        	*addr;
    int         	bits_per_pixel;
    int         	line_length;
    int         	endian;
}               t_data;

typedef struct s_mod {
	int				Drunk;
	int				Wall_rotate;
}				t_mod;

typedef struct  s_vars {
    void        	*mlx;
    void        	*win;
}               t_vars;

typedef struct	s_movement {
	int				up;
	int				down;
	int				left;
	int				right;
	int				cam_right;
	int				cam_left;
}				t_movement;

typedef struct	s_player {
	t_movement		player_mov;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			rotation_speed;
	double			speed;
}				t_player;

typedef struct	s_camera {
	int				ris_x;
	int				ris_y;
	int				destroy;
}				t_camera;

typedef struct s_sprite
{
  double 			x;
  double 			y;
  int 				texture;
}				t_sprite;

typedef struct	s_floor {
	float			rayDirX0;
	float			rayDirY0;
	float			rayDirX1;
	float			rayDirY1;
	int 			p; 
	float 			posZ;
	float 			rowDistance;
	float 			floorStepX;
	float 			floorStepY;
	float 			floorX;
	float 			floorY;
	int 			x;
}				t_floor;

typedef struct 	s_textures {
	void			*texture;
	int				height;
	int				width;
	int				texture_endian;
	char			*texture_path;
	char			*texture_addr;
	int         	bits_per_pixel;
    int         	line_length;
    int         	endian;
}				t_textures;

typedef	struct	s_ray_value {
	int				drawStart;
	int				drawEnd;
	int				lineheight;
}				t_ray_value;

typedef struct s_raycasting {
	int 			y;
	int 			x;
	double			cameraX;
	double			rayDirX;
	double			rayDirY;
	int 			mapX;
    int 			mapY;
	double 			sideDistX;
    double 			sideDistY;
	double 			deltaDistX;
    double 			deltaDistY;
    double 			perpWallDist;
	int 			stepX;
	int 			stepY;
	int				hit;
	int 			side;
	int				textNum;
	double 			oldDirX;
	double 			oldPlaneX;
	t_ray_value		Addvalues;
	t_floor			floor;
}				t_raycasting;

typedef struct	s_game{
	t_vars			vars;
	t_data			img;
	t_movement		movement;
	t_player		player;
	t_camera		camera;
	t_textures		textures[11];
	t_mod			mods;
	t_raycasting	raycasting;
	int				**map;
	t_sprite		sprites[16];
	int				sprites_counter;
}				t_game;

typedef	struct		s_pars {
    int     		c_fd;
    int     		r;
    int     		x;
}					t_pars;

typedef struct	s_str
{
	char			*content;
	struct s_str	*next;
}				t_str;

typedef struct  s_config {
    int     		ris_x;
    int     		ris_y;
    int     		f_color;
    int     		c_color;
    char    		*n_wall;
	char			**map;
    char			**array;
}               t_config;


#endif