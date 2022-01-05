/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_frame.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/20 11:01:49 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 09:28:09 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_ceiling(t_img *img, int width, int heigth, int color)
{
	int	i;
	int	horizon;
	int	r;
	int	g;
	int	b;

	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	horizon = heigth / 2;
	i = horizon;
	while (i > 0)
	{
		draw_horizontal(img, (t_vec2i){0, horizon - i}, width,
			create_rgb(r * i / horizon, g * i / horizon, b * i / horizon));
		i--;
	}
}

void	draw_floor(t_img *img, int width, int heigth, int color)
{
	int	i;
	int	horizon;
	int	r;
	int	g;
	int	b;

	r = get_r(color);
	g = get_g(color);
	b = get_b(color);
	i = 1;
	horizon = heigth / 2;
	draw_horizontal(img, (t_vec2i){0, horizon}, width, 0);
	while (horizon + i < heigth)
	{
		draw_horizontal(img, (t_vec2i){0, horizon + i}, width,
			create_rgb(r * i / horizon, g * i / horizon, b * i / horizon));
		i++;
	}
}

void	texture_walls(t_img *img, t_vec2i start, t_dda *dda, t_tex *textures)
{
	if (dda->type == 0)
	{
		textures->n.shading = textures->shading;
		draw_tex_vertical(img, start, dda, &textures->n);
	}
	else if (dda->type == 1)
	{
		textures->w.shading = textures->shading;
		draw_tex_vertical(img, start, dda, &textures->w);
	}
	else if (dda->type == 2)
	{
		textures->s.shading = textures->shading;
		draw_tex_vertical(img, start, dda, &textures->s);
	}
	else if (dda->type == 3)
	{
		textures->e.shading = textures->shading;
		draw_tex_vertical(img, start, dda, &textures->e);
	}
}

void	draw_walls(t_img *img, t_settings *settings)
{
	int		i;
	t_dda	dda;

	i = 0;
	while (i < settings->screen_width)
	{
		dda.camera.x = 2 * i / (double)settings->screen_width - 1;
		calc_distance_1(&dda, settings);
		calc_distance_2(&dda, settings);
		settings->ray_dist[i] = dda.dist;
		dda.line_len = (1.2 * (double)settings->screen_heigth / dda.dist);
		settings->textures.shading = ft_trnf(\
			(dda.line_len > (double)settings->screen_heigth), 1,
				1 - ((double)settings->screen_heigth - dda.line_len)
				/ (double)settings->screen_heigth);
		texture_walls(img,
			(t_vec2i){i, (settings->screen_heigth - dda.line_len) / 2},
			&dda, &settings->textures);
		i++;
	}
}

void	draw_healthbar(t_img *img, int heigth, int hp)
{
	int	i;

	i = 46;
	while (i > 43)
	{
		draw_horizontal(img, (t_vec2i){23, heigth - i}, 100, 0x696969);
		draw_horizontal(img, (t_vec2i){23, heigth + 23 - i}, 100, 0x696969);
		i--;
	}
	while (i > 23)
	{
		draw_horizontal(img, (t_vec2i){23, heigth - i}, hp, 0x9ffd32);
		if (hp != 100)
			draw_horizontal(img, (t_vec2i){23 + hp, heigth - i},
				(100 - hp), 0xe2ffdc);
		i--;
	}
	i = 0;
	while (i < 3)
	{
		draw_vertical(img, (t_vec2i){20 + i, heigth - 46}, 26, 0x696969);
		draw_vertical(img, (t_vec2i){123 + i, heigth - 46}, 26, 0x696969);
		i++;
	}
}
