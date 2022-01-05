/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:05:14 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/27 21:00:31 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	size;
	char	*sub;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ft_trnsize_t(ft_strlen(s + start) < len, ft_strlen(s + start), len);
	sub = ft_calloc(size + 1, sizeof(char));
	if (!sub)
		return (0);
	ft_memcpy(sub, s + start, size);
	return (sub);
}
