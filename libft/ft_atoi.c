/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 20:08:43 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/27 21:04:33 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	return ((c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r' || c == ' '));
}

int	ft_atoi(const char *str)
{
	size_t				i;
	size_t				start_num;
	int					sign;
	unsigned long int	result;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	sign = ft_trni((str[i] == '-'), -1, 1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	result = 0;
	start_num = i;
	while (ft_isdigit(str[i]))
	{
		result = str[i] - '0' + result * 10;
		i++;
	}
	if ((result > 9223372036854775807 || (i - start_num) > 19) && sign == 1)
		return (-1);
	if ((result > 9223372036854775807 || (i - start_num) > 19) && sign == -1)
		return (0);
	return (sign * result);
}
