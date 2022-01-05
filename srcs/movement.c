/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   movement.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 14:38:18 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 09:27:30 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_settings *settings)
{
	if (settings->keys.s)
		return ;
	if (settings->keys.a + settings->keys.d == 1)
	{
		if (settings->map[(int)settings->pos.y]
			[(int)(settings->pos.x + (0.1 * settings->dir.x))] == '0')
			settings->pos.x += 0.07 * settings->dir.x;
		if (settings->map[(int)(settings->pos.y + (0.1 * settings->dir.y))]
			[(int)settings->pos.x] == '0')
			settings->pos.y += 0.07 * settings->dir.y;
	}
	else
	{
		if (settings->map[(int)settings->pos.y]
			[(int)(settings->pos.x + (0.15 * settings->dir.x))] == '0')
			settings->pos.x += 0.1 * settings->dir.x;
		if (settings->map[(int)(settings->pos.y + (0.15 * settings->dir.y))]
			[(int)settings->pos.x] == '0')
			settings->pos.y += 0.1 * settings->dir.y;
	}
}

void	move_back(t_settings *settings)
{
	if (settings->keys.w)
		return ;
	if (settings->keys.a + settings->keys.d == 1)
	{
		if (settings->map[(int)settings->pos.y]
			[(int)(settings->pos.x - (0.1 * settings->dir.x))] == '0')
			settings->pos.x -= 0.07 * settings->dir.x;
		if (settings->map[(int)(settings->pos.y - (0.1 * settings->dir.y))]
			[(int)settings->pos.x] == '0')
			settings->pos.y -= 0.07 * settings->dir.y;
	}
	else
	{
		if (settings->map[(int)settings->pos.y]
			[(int)(settings->pos.x - (0.15 * settings->dir.x))] == '0')
			settings->pos.x -= 0.1 * settings->dir.x;
		if (settings->map[(int)(settings->pos.y - (0.15 * settings->dir.y))]
			[(int)settings->pos.x] == '0')
			settings->pos.y -= 0.1 * settings->dir.y;
	}
}

void	move_left(t_settings *settings)
{
	if (settings->keys.d)
		return ;
	if (settings->keys.w + settings->keys.s == 1)
	{
		if (settings->map[(int)settings->pos.y]
			[(int)(settings->pos.x - (0.07 * settings->plane.x))] == '0')
			settings->pos.x -= 0.05 * settings->plane.x;
		if (settings->map[(int)(settings->pos.y - (0.07 * settings->plane.y))]
			[(int)settings->pos.x] == '0')
			settings->pos.y -= 0.05 * settings->plane.y;
	}
	else
	{
		if (settings->map[(int)settings->pos.y]
			[(int)(settings->pos.x - (0.15 * settings->plane.x))] == '0')
			settings->pos.x -= 0.1 * settings->plane.x;
		if (settings->map[(int)(settings->pos.y - (0.15 * settings->plane.y))]
			[(int)settings->pos.x] == '0')
			settings->pos.y -= 0.1 * settings->plane.y;
	}
}

void	move_right(t_settings *settings)
{
	if (settings->keys.a)
		return ;
	if (settings->keys.w + settings->keys.s == 1)
	{
		if (settings->map[(int)settings->pos.y]
			[(int)(settings->pos.x + (0.07 * settings->plane.x))] == '0')
			settings->pos.x += 0.05 * settings->plane.x;
		if (settings->map[(int)(settings->pos.y + (0.07 * settings->plane.y))]
			[(int)settings->pos.x] == '0')
			settings->pos.y += 0.05 * settings->plane.y;
	}
	else
	{
		if (settings->map[(int)settings->pos.y]
			[(int)(settings->pos.x + (0.15 * settings->plane.x))] == '0')
			settings->pos.x += 0.1 * settings->plane.x;
		if (settings->map[(int)(settings->pos.y + (0.15 * settings->plane.y))]
			[(int)settings->pos.x] == '0')
			settings->pos.y += 0.1 * settings->plane.y;
	}
}

void	rotate(t_settings *settings)
{
	double	tmp_dir;
	double	tmp_plane;

	tmp_dir = settings->dir.x;
	tmp_plane = settings->plane.x;
	if (settings->keys.l_arr && !settings->keys.r_arr)
	{
		settings->dir.x = settings->dir.x * cos(-0.08)
			- settings->dir.y * sin(-0.08);
		settings->plane.x = settings->plane.x * cos(-0.08)
			- settings->plane.y * sin(-0.08);
		settings->dir.y = settings->dir.y * cos(-0.08) + tmp_dir * sin(-0.08);
		settings->plane.y = settings->plane.y * cos(-0.08)
			+ tmp_plane * sin(-0.08);
	}
	else if (!settings->keys.l_arr && settings->keys.r_arr)
	{
		settings->dir.x = settings->dir.x * cos(0.08)
			- settings->dir.y * sin(0.08);
		settings->plane.x = settings->plane.x * cos(0.08)
			- settings->plane.y * sin(0.08);
		settings->dir.y = settings->dir.y * cos(0.08) + tmp_dir * sin(0.08);
		settings->plane.y = settings->plane.y * cos(0.08)
			+ tmp_plane * sin(0.08);
	}
}
