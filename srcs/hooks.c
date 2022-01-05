/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/25 10:45:44 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 09:27:49 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef BONUS

int	key_exit(t_og *og)
{
	mlx_destroy_window(og->mlx->ptr, og->mlx->wdw);
	ft_putstr("Successfully exited Tijmen's cub3D. Thanks for playing!\n");
	exit(EXIT_SUCCESS);
}

#endif

int	key_press(int key, t_og *og)
{
	if (key == W)
		og->settings->keys.w = 1;
	else if (key == A)
		og->settings->keys.a = 1;
	else if (key == S)
		og->settings->keys.s = 1;
	else if (key == D)
		og->settings->keys.d = 1;
	else if (key == L_ARR)
		og->settings->keys.l_arr = 1;
	else if (key == R_ARR)
		og->settings->keys.r_arr = 1;
	else if (key == ESC)
		key_exit(og);
	return (1);
}

int	key_release(int key, t_og *og)
{
	if (key == W)
		og->settings->keys.w = 0;
	else if (key == A)
		og->settings->keys.a = 0;
	else if (key == S)
		og->settings->keys.s = 0;
	else if (key == D)
		og->settings->keys.d = 0;
	else if (key == L_ARR)
		og->settings->keys.l_arr = 0;
	else if (key == R_ARR)
		og->settings->keys.r_arr = 0;
	return (1);
}
