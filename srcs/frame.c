/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   frame.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 10:56:30 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 09:27:57 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	update_position(t_settings *settings)
{
	if (settings->keys.w && !settings->keys.s)
		move_forward(settings);
	if (settings->keys.a && !settings->keys.d)
		move_left(settings);
	if (settings->keys.s && !settings->keys.w)
		move_back(settings);
	if (settings->keys.d && !settings->keys.a)
		move_right(settings);
	if (settings->keys.l_arr || settings->keys.r_arr)
		rotate(settings);
}

#ifndef BONUS

void	draw_frame(t_img *img, t_settings *settings)
{
	draw_ceiling(img, settings->screen_width,
		settings->screen_heigth, settings->c_color);
	draw_floor(img, settings->screen_width,
		settings->screen_heigth, settings->f_color);
	update_position(settings);
	draw_walls(img, settings);
	if (settings->spr_count)
		draw_sprites(img, settings);
	if (settings->save)
		screenshot(img, settings);
}

#endif

int	frame(t_og *og)
{
	if (!(og->settings->keys.w || og->settings->keys.a || og->settings->keys.s
			|| og->settings->keys.d || og->settings->keys.l_arr
			|| og->settings->keys.r_arr || !og->mlx->new.img))
		return (0);
	if (og->mlx->new.img)
	{
		og->mlx->old = og->mlx->new;
		mlx_put_image_to_window(og->mlx->ptr, og->mlx->wdw, og->mlx->old.img,
		0, 0);
	}
	og->mlx->new.img = mlx_new_image(og->mlx->ptr, og->settings->screen_width,
			og->settings->screen_heigth);
	if (!og->mlx->new.img)
		error("Failed to load mlx image.\n");
	og->mlx->new.addr = mlx_get_data_addr(og->mlx->new.img, &og->mlx->new.bpp,
			&og->mlx->new.ll, &og->mlx->new.ed);
	if (!og->mlx->new.addr)
		error("MLX memory allocation failed.\n");
	og->mlx->new.dim.x = og->settings->screen_width;
	og->mlx->new.dim.y = og->settings->screen_heigth;
	draw_frame(&og->mlx->new, og->settings);
	mlx_put_image_to_window(og->mlx->ptr, og->mlx->wdw, og->mlx->new.img, 0, 0);
	if (og->mlx->old.img)
		mlx_destroy_image(og->mlx->ptr, og->mlx->old.img);
	return (1);
}
