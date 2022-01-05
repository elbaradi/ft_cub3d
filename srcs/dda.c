/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dda.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/20 12:41:27 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 09:28:15 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calc_distance_1(t_dda *dda, t_settings *settings)
{
	dda->ray_dir.x = settings->dir.x + (settings->plane.x * dda->camera.x);
	dda->ray_dir.y = settings->dir.y + (settings->plane.y * dda->camera.x);
	dda->box = (t_vec2i){(int)settings->pos.x, (int)settings->pos.y};
	dda->delta = (t_vec2d){fabs(1 / dda->ray_dir.x), fabs(1 / dda->ray_dir.y)};
	dda->step.x = ft_trni((dda->ray_dir.x > 0), 1, -1);
	dda->step.y = ft_trni((dda->ray_dir.y > 0), 1, -1);
	dda->side.x = ft_trnf((dda->ray_dir.x < 0), (settings->pos.x - dda->box.x)
			* dda->delta.x, (dda->box.x + 1 - settings->pos.x) * dda->delta.x);
	dda->side.y = ft_trnf((dda->ray_dir.y < 0), (settings->pos.y - dda->box.y)
			* dda->delta.y, (dda->box.y + 1 - settings->pos.y) * dda->delta.y);
}

void	finishing_touch(t_dda *dda, t_settings *settings)
{
	if (dda->type == 0 || dda->type == 2)
	{
		dda->dist = (dda->box.y - settings->pos.y + (1 - dda->step.y) / 2)
			/ dda->ray_dir.y;
		dda->tex = (t_vec2d){settings->pos.x + dda->dist * dda->ray_dir.x, 0};
	}
	else
	{
		dda->dist = (dda->box.x - settings->pos.x + (1 - dda->step.x) / 2)
			/ dda->ray_dir.x;
		dda->tex = (t_vec2d){settings->pos.y + dda->dist * dda->ray_dir.y, 0};
	}
}

void	calc_distance_2(t_dda *dda, t_settings *settings)
{
	dda->hit = 0;
	while (!dda->hit)
	{
		if (dda->side.x < dda->side.y)
		{
			dda->side.x += dda->delta.x;
			dda->box.x += dda->step.x;
			dda->type = 2 + dda->step.x;
		}
		else
		{
			dda->side.y += dda->delta.y;
			dda->box.y += dda->step.y;
			dda->type = 1 + dda->step.y;
		}
		if (settings->map[dda->box.y][dda->box.x] == '1')
			dda->hit = 1;
	}
	finishing_touch(dda, settings);
}
