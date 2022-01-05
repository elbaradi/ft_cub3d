/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 23:59:48 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/26 01:09:49 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	count;
	char	*copy;

	count = ft_strlen(s1) + 1;
	copy = ft_calloc(count, sizeof(char));
	if (!copy)
		return (0);
	ft_memcpy(copy, s1, count);
	return (copy);
}
