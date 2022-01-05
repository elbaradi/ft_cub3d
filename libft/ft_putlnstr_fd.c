/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlnstr_fd.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 19:48:40 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/27 20:56:33 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlnstr_fd(char *s, int fd, int len)
{
	if (s && len)
	{
		len = ft_trni((len > (int)ft_strlen(s)), (int)ft_strlen(s), len);
		return (write(fd, s, len));
	}
	return (0);
}
