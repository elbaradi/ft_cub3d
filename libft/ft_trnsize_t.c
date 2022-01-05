/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_trnsize_t.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/27 20:35:56 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/27 22:58:52 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_trnsize_t(int condition, size_t a, size_t b)
{
	if (condition)
		return (a);
	else
		return (b);
}
