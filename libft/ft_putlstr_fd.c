/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlstr_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 19:48:40 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/26 01:12:14 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlstr_fd(char *s, int fd)
{
	if (s)
		return (write(fd, s, ft_strlen(s)));
	return (0);
}
