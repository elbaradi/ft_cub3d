/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlunbr_base_fd.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 17:34:02 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/26 01:12:09 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlunbr_base_fd(unsigned long long nbr, char *basestr, int fd)
{
	int			base;
	long long	exp;
	int			len;

	base = ft_strlen(basestr);
	if (base < 2)
		return (-1);
	exp = 1;
	len = 1;
	while (nbr / base / exp)
	{
		exp *= base;
		len++;
	}
	while (exp)
	{
		ft_putchar_fd(basestr[nbr / exp % base], fd);
		exp /= base;
	}
	return (len);
}
