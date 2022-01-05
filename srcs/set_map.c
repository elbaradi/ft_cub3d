/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_map.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/14 16:06:32 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 09:27:09 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	initialize_player(t_input input, t_settings *settings)
{
	settings->pos = (t_vec2d){input.spawn.x + 0.5, input.spawn.y - 0.5};
	if (input.spawn_dir == 'N')
	{
		settings->dir = (t_vec2d){0, -1};
		settings->plane = (t_vec2d){0.66, 0};
	}
	if (input.spawn_dir == 'S')
	{
		settings->dir = (t_vec2d){0, 1};
		settings->plane = (t_vec2d){-0.66, 0};
	}
	if (input.spawn_dir == 'W')
	{
		settings->dir = (t_vec2d){-1, 0};
		settings->plane = (t_vec2d){0, -0.66};
	}
	if (input.spawn_dir == 'E')
	{
		settings->dir = (t_vec2d){1, 0};
		settings->plane = (t_vec2d){0, 0.66};
	}
}

int	check_bounds(int x, int y, char **map)
{
	if (map[y][x] == ' ')
		map[y][x] = '0';
	if ((map[y][x] == '0' || map[y][x] == '2') && map[y - 1][x] != '.'
		&& map[y][x + 1] != '.' && map[y + 1][x] != '.' && map[y][x - 1] != '.')
	{
		if (map[y][x] == '0')
			map[y][x] = 'X';
		if (map[y][x] == '2')
			map[y][x] = 'Z';
		return (check_bounds(x, y - 1, map) && check_bounds(x + 1, y, map)
			&& check_bounds(x, y + 1, map) && check_bounds(x - 1, y, map));
	}
	else if (map[y][x] == '1' || map[y][x] == 'X' || map[y][x] == 'Z')
		return (1);
	else
		return (0);
}

int	validate_map(t_settings *settings, char **map)
{
	int	i;
	int	j;
	int	count;

	if (!(check_bounds((int)settings->pos.x, (int)settings->pos.y, map)))
		return (0);
	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'X')
				map[i][j] = '0';
			if (map[i][j] == '2' || map[i][j] == 'Z')
			{
				settings->sprites[count].pos = (t_vec2d){j + 0.5, i + 0.5};
				count++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	set_map(t_input input, t_settings *settings)
{
	settings->map = make_map(input.map, input.map_heigth, input.map_width);
	if (!settings->map)
		error("Failed to create 2D char array for map.\n");
	settings->map_width = input.map_width;
	settings->map_heigth = input.map_heigth;
	settings->screen_width = input.x_render_size;
	settings->screen_heigth = input.y_render_size;
	settings->f_color = input.f_color;
	settings->c_color = input.c_color;
	initialize_player(input, settings);
	settings->timer = 0;
	settings->hp = 100;
	settings->spr_count = input.sprite_count;
	if (input.sprite_count)
	{
		settings->sprites = malloc(input.sprite_count * sizeof(t_sprites));
		if (!settings->sprites)
			error("Failed to allocate memory for sprite location.\n");
	}
	settings->ray_dist = malloc(settings->screen_width * sizeof(double));
	if (!settings->ray_dist)
		error("Failed to allocate memory for ray distance buffer.\n");
	if (!(validate_map(settings, settings->map)))
		error("Invalid map: Player can get out of bounds.\n");
}
