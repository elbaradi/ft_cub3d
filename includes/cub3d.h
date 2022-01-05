/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/04 16:10:01 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 23:07:00 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# define W 13
# define A 0
# define S 1
# define D 2
# define L_ARR 123
# define R_ARR 124
# define ESC 53

typedef struct s_vec2d
{
	double			x;
	double			y;
}				t_vec2d;

typedef struct s_vec2i
{
	int				x;
	int				y;
}				t_vec2i;

typedef struct s_id_init
{
	int				res_id;
	int				north_id;
	int				south_id;
	int				west_id;
	int				east_id;
	int				sprite_id;
	int				ceiling_id;
	int				floor_id;
	int				map_start;
}				t_id_init;

typedef struct s_input
{
	int				y_render_size;
	int				x_render_size;
	char			*n_texture;
	char			*s_texture;
	char			*w_texture;
	char			*e_texture;
	char			*spr_texture;
	int				ceiling_r;
	int				ceiling_g;
	int				ceiling_b;
	int				floor_r;
	int				floor_g;
	int				floor_b;
	char			*map;
	int				map_width;
	int				map_heigth;
	int				f_color;
	int				c_color;
	t_vec2i			spawn;
	char			spawn_dir;
	t_id_init		init;
	int				sprite_count;
}				t_input;

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				ll;
	int				ed;
	t_vec2i			pos;
	t_vec2i			dim;
	double			ratio;
	double			shading;
}				t_img;

typedef struct s_tex
{
	t_img			n;
	t_img			s;
	t_img			w;
	t_img			e;
	t_img			spr;
	double			shading;
}				t_tex;

typedef struct s_mlx
{
	void			*ptr;
	void			*wdw;
	t_img			new;
	t_img			old;
}				t_mlx;

typedef struct s_keys
{
	int				w;
	int				a;
	int				s;
	int				d;
	int				l_arr;
	int				r_arr;
	int				esc;
}				t_keys;

typedef struct s_sprites
{
	t_vec2d			pos;
	double			dist;
}				t_sprites;

typedef struct s_sprite_calc
{
	t_vec2d			sprite;
	double			inv;
	t_vec2d			transform;
	int				screen_x;
	t_vec2i			dim;
	int				tex_x;
}				t_sprite_calc;

typedef struct s_settings
{
	char			*n_texture;
	char			*s_texture;
	char			*w_texture;
	char			*e_texture;
	char			*spr_texture;
	t_tex			textures;
	int				map_heigth;
	int				map_width;
	char			**map;
	int				screen_heigth;
	int				screen_width;
	int				f_color;
	int				c_color;
	t_keys			keys;
	t_vec2d			pos;
	t_vec2d			dir;
	t_vec2d			plane;
	int				save;
	int				spr_count;
	t_sprites		*sprites;
	double			*ray_dist;
	int				timer;
	int				hp;
}				t_settings;

typedef struct s_og
{
	t_input			*input;
	t_settings		*settings;
	t_mlx			*mlx;
}				t_og;

typedef struct s_dda
{
	t_vec2d			camera;
	t_vec2d			ray_dir;
	t_vec2d			delta;
	t_vec2d			side;
	t_vec2i			box;
	t_vec2i			step;
	t_vec2d			tex;
	double			dist;
	int				hit;
	int				type;
	int				line_len;
	double			xtex;
}				t_dda;

void			init_map_vars(t_input *input);
void			import_map(t_input *input, char *file);

int				parse_r(char *line, t_input *input);
int				parse_no(char *line, t_input *input);
int				parse_so(char *line, t_input *input);
int				parse_we(char *line, t_input *input);
int				parse_ea(char *line, t_input *input);
int				parse_s(char *line, t_input *input);
int				parse_f(char *line, t_input *input);
int				parse_c(char *line, t_input *input);
int				parse_rgb(char *line, int *red, int *green, int *blue);

char			**make_map(char const *s, int heigth, int width);
void			set_map(t_input input, t_settings *settings);
int				validate_map(t_settings *settings, char **map);

int				create_rgb(int r, int g, int b);
int				get_r(int rgb);
int				get_g(int rgb);
int				get_b(int rgb);
int				add_shade(int rgb, double shading);

void			calc_distance_1(t_dda *dda, t_settings *settings);
void			calc_distance_2(t_dda *dda, t_settings *settings);

void			draw_rectangle(t_img *img, t_vec2i pos, t_vec2i dim,
					unsigned int color);
void			draw_horizontal(t_img *img, t_vec2i pos, int len,
					unsigned int color);
void			draw_vertical(t_img *img, t_vec2i pos, int len,
					unsigned int color);

void			screen_resize(void *mlx, int *width, int *heigth);
void			draw_frame(t_img *img, t_settings *settings);
void			draw_ceiling(t_img *img, int width, int heigth, int color);
void			draw_floor(t_img *img, int width, int heigth, int color);
void			draw_walls(t_img *img, t_settings *settings);
void			draw_healthbar(t_img *img, int heigth, int hp);
void			get_textures(t_og *og, t_tex *tx);
void			draw_tex_vertical(t_img *img, t_vec2i pos, t_dda *dda,
					t_img *tex);

void			draw_sprites(t_img *img, t_settings *settings);
void			sort_sprites(t_sprites *sprites, int count, t_vec2d pos);
void			draw_sprite(t_sprite_calc spr, t_settings *settings,
					t_img *img);
void			draw_spr_vertical(t_img *img, t_vec2i pos, t_img *tex,
					t_sprite_calc spr);
int				pain(t_settings *settings);

int				frame(t_og *og);

void			update_position(t_settings *settings);
void			move_forward(t_settings *settings);
void			move_back(t_settings *settings);
void			move_left(t_settings *settings);
void			move_right(t_settings *settings);
void			rotate(t_settings *settings);

int				key_exit(t_og *og);
int				key_press(int key, t_og *og);
int				key_release(int key, t_og *og);

void			screenshot(t_img *img, t_settings *settings);
char			*header_string(t_settings *settings, unsigned int bytes);
char			*bitmap_string(t_img *img, t_settings *settings,
					int padding, unsigned int bytes);
void			hex_to_24bit(char *str, unsigned int hex);
void			hex_to_32bit(char *str, unsigned int hex);

void			run_game(t_og *og);
void			error(char *message);

#endif
