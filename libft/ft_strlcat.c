/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 19:31:55 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/26 01:09:38 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstsize;

	i = 0;
	dstsize = ft_strlen(dst);
	if (size > dstsize)
	{
		while (i < size - dstsize - 1 && src[i])
		{
			dst[i + dstsize] = src[i];
			i++;
		}
		dst[i + dstsize] = 0;
		return (ft_strlen(src) + dstsize);
	}
	return (ft_strlen(src) + size);
}
