/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprites.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/15 23:04:14 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 09:27:01 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sort_sprites(t_sprites *sprites, int count, t_vec2d pos)
{
	t_sprites	swap;
	int			i;
	int			j;

	i = 0;
	while (i < count)
	{
		sprites[i].dist
			= pow(pos.x - sprites[i].pos.x, 2)
			+ pow(pos.y - sprites[i].pos.y, 2);
		i++;
	}
	i = 1;
	while (i < count)
	{
		swap = sprites[i];
		j = i - 1;
		while (j >= 0 && sprites[j].dist < swap.dist)
		{
			sprites[j + 1] = sprites[j];
			j = j - 1;
		}
		sprites[j + 1] = swap;
		i++;
	}
}

void	draw_spr_vertical(t_img *img, t_vec2i pos, t_img *tex,
		t_sprite_calc spr)
{
	char			*dst;
	int				i;
	unsigned int	color;
	int				len;
	int				adj;

	tex->ratio = (double)tex->dim.y / spr.dim.y;
	adj = 0;
	if (pos.y < 0)
	{
		adj = -pos.y;
		pos.y = 0;
	}
	len = ft_trni((spr.dim.y > img->dim.y), img->dim.y, spr.dim.y);
	dst = img->addr + pos.y * img->ll + pos.x * (img->bpp / 8);
	i = 0;
	while (i < len)
	{
		color = *(unsigned int *)(tex->addr
				+ (tex->ll * (int)((i + adj) * tex->ratio)) + spr.tex_x);
		if (color != 0xFF000000)
			*(unsigned int *)(dst + (i * img->ll)) = color;
		i++;
	}
}

void	draw_sprite(t_sprite_calc spr, t_settings *settings, t_img *img)
{
	t_vec2i	stripe;
	int		end;
	double	ratio;

	spr.dim.y = abs((int)(settings->screen_heigth / (spr.transform.y)));
	spr.dim.x = abs((int)(settings->screen_heigth / (spr.transform.y)));
	stripe.x = spr.screen_x - (spr.dim.x / 2);
	if (stripe.x < 0)
		stripe.x = 0;
	stripe.y = (settings->screen_heigth / 2) - (spr.dim.y / 2);
	end = spr.screen_x + (spr.dim.x / 2);
	if (end >= settings->screen_width)
		end = settings->screen_width - 1;
	ratio = (double)settings->textures.spr.dim.x / spr.dim.x;
	while (stripe.x < end)
	{
		spr.tex_x = (settings->textures.spr.bpp / 8)
			* (int)((stripe.x - (spr.screen_x - (spr.dim.x / 2))) * ratio);
		if (spr.transform.y > 0 && stripe.x > 0
			&& stripe.x < settings->screen_width
			&& spr.transform.y < settings->ray_dist[stripe.x])
			draw_spr_vertical(img, stripe, &settings->textures.spr, spr);
		stripe.x++;
	}
}

#ifndef BONUS

int	pain(t_settings *settings)
{
	if (settings->timer < 90)
		settings->timer++;
	if (sqrt(settings->sprites[settings->spr_count - 1].dist) < 0.6
		&& settings->timer == 90)
	{
		settings->timer = 0;
		ft_putstr("Ouch!\n");
		return (1);
	}
	return (0);
}

#endif

void	draw_sprites(t_img *img, t_settings *settings)
{
	int				i;
	t_sprite_calc	spr;

	i = 0;
	sort_sprites(settings->sprites, settings->spr_count, settings->pos);
	while (i < settings->spr_count)
	{
		spr.sprite.x = settings->sprites[i].pos.x - settings->pos.x;
		spr.sprite.y = settings->sprites[i].pos.y - settings->pos.y;
		spr.inv = 1 / (settings->plane.x * settings->dir.y
				- settings->plane.y * settings->dir.x);
		spr.transform.x = spr.inv * (settings->dir.y * spr.sprite.x
				- settings->dir.x * spr.sprite.y);
		spr.transform.y = spr.inv * (settings->plane.x * spr.sprite.y
				- settings->plane.y * spr.sprite.x);
		spr.screen_x = (int)((settings->screen_width / 2)
				* (1 + spr.transform.x / spr.transform.y));
		draw_sprite(spr, settings, img);
		i++;
	}
	if (pain(settings))
		draw_rectangle(img, (t_vec2i){0, 0}, (t_vec2i)
			{settings->screen_width, settings->screen_heigth}, 0x808B0000);
}
