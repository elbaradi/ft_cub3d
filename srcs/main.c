/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/11 17:00:22 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 09:27:36 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	validate_settings(t_id_init init)
{
	if (!init.north_id || !init.south_id || !init.west_id
		|| !init.east_id || !init.ceiling_id || !init.floor_id)
		error("Element identifiers appear to be missing.\n");
}

void	screen_resize(void *mlx, int *width, int *heigth)
{
	t_vec2i		display;

	mlx_get_screen_size(mlx, &display.x, &display.y);
	if (display.x < *width)
	{
		*width = display.x;
		ft_putstr("X-Resolution is too large, resizing window to fit screen\n");
	}
	if (display.y < *heigth)
	{
		*heigth = display.y;
		ft_putstr("Y-Resolution is too large, resizing window to fit screen\n");
	}
}

#ifndef BONUS

void	run_game(t_og *og)
{
	og->mlx->ptr = mlx_init();
	if (!og->mlx->ptr)
		error("Failed to initialize mlx.\n");
	screen_resize(og->mlx->ptr, &og->settings->screen_width,
								&og->settings->screen_heigth);
	if (!(og->settings->save))
	{
		og->mlx->wdw = mlx_new_window(og->mlx->ptr, og->settings->screen_width,
				og->settings->screen_heigth, "Tijmen's CHAD cub3D");
		if (!og->mlx->wdw)
			error("Failed to create window.\n");
		mlx_hook(og->mlx->wdw, 17, 0, &key_exit, og);
		mlx_hook(og->mlx->wdw, 2, 0, &key_press, og);
		mlx_hook(og->mlx->wdw, 3, 0, &key_release, og);
	}
	og->mlx->new.img = 0;
	get_textures(og, &og->settings->textures);
	ft_bzero(&og->settings->keys, sizeof(t_keys));
	mlx_loop_hook(og->mlx->ptr, &frame, og);
	mlx_loop(og->mlx->ptr);
}

#endif

int	main(int argc, char **argv)
{
	t_og	og;

	og.input = ft_calloc(1, sizeof(t_input));
	og.settings = ft_calloc(1, sizeof(t_settings));
	og.mlx = ft_calloc(1, sizeof(t_mlx));
	if ((argc == 2 || (argc == 3 && !ft_strncmp(argv[2], "--save", 7)))
		&& ((ft_strlen(argv[1]) > 3)
				&& !ft_strncmp(argv[1] + (ft_strlen(argv[1]) - 4), ".cub", 4)))
	{
		og.settings->save = (argc == 3);
		init_map_vars(og.input);
		import_map(og.input, argv[1]);
		validate_settings(og.input->init);
		set_map(*og.input, og.settings);
		run_game(&og);
	}
	else
		ft_putstr("Error\nStart as follows: ./cub3D [test].cub [--save]\n");
	return (1);
}
