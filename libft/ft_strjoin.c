/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 16:49:19 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/26 01:09:41 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len_s1;
	size_t		len_joined;
	char		*joined;

	if (!s1 || !s2)
		return (0);
	len_s1 = ft_strlen(s1);
	len_joined = len_s1 + ft_strlen(s2) + 1;
	joined = ft_calloc(len_joined, sizeof(char));
	if (!joined)
		return (0);
	ft_strlcpy(joined, s1, len_s1 + 1);
	ft_strlcat(joined, s2, len_joined);
	return (joined);
}
