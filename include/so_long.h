/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 17:29:39 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/06/08 20:55:56 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define SCALE 32
# define ESC 65307   // key escape
# define UP 65362   // key "arrow up"
# define DOWN 65364 // key "arrow down"
# define LEFT 65361 // key "arrow left"
# define RIGHT 65363 // key "arrow right"
# define W 119
# define S 115
# define A 97
# define D 100

# include <mlx.h>
# include "mlx.h"
# include "libft.h"
# include "get_next_line_bonus.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_win {
	void	*mlx_ptr;
	void	*win_ptr;
	int		w;
	int		h;
}	t_win;

typedef struct s_img {
	void	*img_ptr;
	char	*addr;
	int		w;
	int		h;
	int		bpp;
	int		endian;
	int		size_line;
}	t_img;

typedef struct s_point {
	int	x;
	int	y;
}	t_point;

typedef struct s_map {
	char	**mtx;
	int		w;
	int		h;
	int		player;
	int		colectibles;
	int		exit;
}	t_map;

typedef struct s_rect {
	double				x;
	double				y;
	unsigned short int	w;
	unsigned short int	h;
	int					color;
}	t_rect;

typedef struct s_circle {
	double				x;
	double				y;
	unsigned short int	r;
	int					color;
}	t_circle;

typedef struct s_keys {
	int	moves;
	int	up;
	int	down;
	int	left;
	int	right;
}	t_keys;

typedef struct s_sprite {
	char	*spt_path;
	t_img	img;
}	t_sprite;

typedef struct s_spts {
	t_sprite	floor;
	t_sprite	wall;
	t_sprite	player;
	t_sprite	colectibles;
	t_sprite	exit;
	t_sprite	ladder;
}	t_spts;

typedef struct s_vars {
	char	*map_path;
	void	*mlx_ptr;
	t_map	map;
	t_map	map_cpy;
	t_win	win;
	t_img	img;
	t_spts	spts;
	t_point	begin;
	t_keys	keys;
}	t_vars;

void				game_init(t_vars *vars);
void				get_map(t_vars *vars, int fd, int count);
void				parse_map(t_vars *vars, t_point p0);
void				map_dup(t_vars *vars);
void				f_fill(t_vars *vars, int hrz, int vrt);
void				flood_fill(t_vars *vars);
void				put_pixel_img(t_img img, int x, int y, int color);
void				def_paths(t_vars *vars);
void				draw_rect(t_rect rect, t_img img);
void				draw_circle(t_circle circle, t_img img);
void				new_sprite(t_vars *vars, t_sprite *sprite);
void				get_sprite(t_vars *vars, t_sprite *sprite, int j, int i);
void				draw_sprite(t_vars *vars, t_sprite *sprite, int j, int i);
void				draw_map(t_vars *vars);
void				new_win(t_vars *vars, char *str);
void				moves(t_vars *vars);
void				del_all_img(t_vars *vars);
void				free_paths(t_vars *vars);
void				free_all(t_vars *vars);
void				error_exit(t_vars *vars, char *error_str);

int					exit_win(t_vars *vars);
int					open_maps(t_vars *vars, const char *pathname);
int					read_pkeys(int key_pressed, void *param);
int					read_rkeys(int key_rleased, void *param);
int					render(t_vars *vars);

unsigned int		get_pixel_img(t_img img, int x, int y);

t_img				new_img(t_vars *vars, int w, int h);

#endif