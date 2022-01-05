/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/20 10:42:20 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 09:28:01 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#ifndef BONUS

void	error(char *message)
{
	ft_putstr("Error\n");
	ft_putstr(message);
	exit(EXIT_FAILURE);
}

#endif

#ifdef BONUS

void	error(char *message)
{
	ft_putstr("Error\n");
	ft_putstr(message);
	system("pkill afplay");
	exit(EXIT_FAILURE);
}

#endif
