/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putlnbr_base_fd.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/24 17:34:02 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/27 22:41:20 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlnbr_base_fd(long long nbr, char *basestr, int fd)
{
	int			base;
	long long	exp;
	int			len;
	int			minus;

	base = ft_strlen(basestr);
	if (base < 2)
		return (-1);
	exp = 1;
	len = 1;
	minus = ft_trni((nbr < 0), 1, 0);
	while (nbr / base / exp)
	{
		exp *= base;
		len++;
	}
	if (minus)
		ft_putchar_fd('-', fd);
	while (exp)
	{
		ft_putchar_fd(basestr[ft_trni(minus, -1, 1) * (nbr / exp % base)], fd);
		exp /= base;
	}
	return (minus + len);
}
