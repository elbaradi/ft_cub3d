/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   draw_lines.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/18 18:17:55 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 09:28:05 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_horizontal(t_img *img, t_vec2i pos, int len, unsigned int color)
{
	char	*dst;
	int		offset;
	int		i;

	offset = pos.y * img->ll + pos.x * (img->bpp / 8);
	dst = img->addr + offset;
	i = 0;
	while (i < len)
	{
		*(unsigned int *)(dst + (i * (img->bpp / 8))) = color;
		i++;
	}
}

void	draw_vertical(t_img *img, t_vec2i pos, int len, unsigned int color)
{
	char	*dst;
	int		offset;
	int		i;

	offset = pos.y * img->ll + pos.x * (img->bpp / 8);
	dst = img->addr + offset;
	i = 0;
	while (i < len)
	{
		*(unsigned int *)(dst + (i * img->ll)) = color;
		i++;
	}
}

void	draw_rectangle(t_img *img, t_vec2i pos, t_vec2i dim, unsigned int color)
{
	int		i;

	i = 0;
	while (i < dim.y)
	{
		draw_horizontal(img, (t_vec2i){pos.x, pos.y + i}, dim.x, color);
		i++;
	}
}

void	draw_tex_vertical(t_img *img, t_vec2i pos, t_dda *dda, t_img *tex)
{
	char	*dst;
	int		i;
	int		tex_x;
	int		color;

	tex->ratio = (double)tex->dim.y / dda->line_len;
	if (pos.y < 0)
	{
		dda->tex.y = -pos.y;
		pos.y = 0;
	}
	if (dda->line_len > img->dim.y)
		dda->line_len = img->dim.y;
	dst = img->addr + pos.y * img->ll + pos.x * (img->bpp / 8);
	tex_x = (int)(dda->tex.x * tex->dim.x) % tex->dim.x * (tex->bpp / 8);
	i = 0;
	while (i < dda->line_len)
	{
		color = *(unsigned int *)(tex->addr
				+ (tex->ll * (int)((i + dda->tex.y) * tex->ratio)) + tex_x);
		*(unsigned int *)(dst + (i * img->ll)) = add_shade(color, tex->shading);
		i++;
	}
}
