/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bonus_bonus.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/20 16:12:31 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 09:28:22 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifdef BONUS

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
	system("afplay audio/tracks/Love.mp3 -r 0.85&");
	mlx_loop(og->mlx->ptr);
}

int	pain(t_settings *settings)
{
	char	*sound;

	if (settings->timer < 90)
		settings->timer++;
	if (sqrt(settings->sprites[settings->spr_count - 1].dist) < 0.6
		&& settings->timer == 90)
	{
		settings->timer = 0;
		settings->hp += -9;
		sound = ft_strdup("afplay audio/sounds/Ouchx.m4a&");
		*(sound + 24) = '0' + rand() % 10;
		system(sound);
		free(sound);
		if (settings->hp <= 0)
		{
			ft_putstr("You died. LOL. Thanks for playing!\n");
			system("pkill afplay");
			system("afplay audio/sounds/GameOver.m4a&");
			exit(EXIT_SUCCESS);
		}
		return (1);
	}
	return (0);
}

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
	if (settings->screen_heigth > 400 && settings->screen_width > 400)
		draw_healthbar(img, settings->screen_heigth, settings->hp);
	if (settings->save)
		screenshot(img, settings);
}

int	key_exit(t_og *og)
{
	mlx_destroy_window(og->mlx->ptr, og->mlx->wdw);
	system("pkill afplay");
	ft_putstr("Successfully exited Tijmen's cub3D. Thanks for playing!\n");
	exit(EXIT_SUCCESS);
}

void	screenshot(t_img *img, t_settings *settings)
{
	int				fd;
	int				padding;
	unsigned int	bytes;
	char			*header;
	char			*bmp;

	fd = open("./screenshot/screenshot.bmp", (O_WRONLY | O_CREAT | O_TRUNC
				| O_APPEND), 0666);
	if (fd == -1)
		error("Failed to create screenshot.bmp using open().\n");
	padding = (4 - ((settings->screen_width * 3) % 4)) % 4;
	bytes = settings->screen_heigth * ((settings->screen_width * 3) + padding);
	header = header_string(settings, bytes);
	bmp = bitmap_string(img, settings, padding, bytes);
	if (write(fd, header, 54) == -1)
		error("Failed to write header data into screenshot.bmp.\n");
	free(header);
	if (write(fd, bmp, bytes) == -1)
		error("Failed to write bitmap data into screenshot.bmp.\n");
	free(bmp);
	ft_putstr("Saved as screenshot.bmp in ./screenshot/\n");
	system("pkill afplay");
	exit(EXIT_SUCCESS);
}

#endif
