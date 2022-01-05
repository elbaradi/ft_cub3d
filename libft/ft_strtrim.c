/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 19:15:58 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/26 01:09:14 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isinset(char const c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1)
		return (0);
	i = 0;
	while (ft_isinset(s1[i], set))
		i++;
	start = i;
	i = ft_strlen(s1);
	while (i > start && ft_isinset(s1[i - 1], set))
		i--;
	end = i;
	trimmed = ft_substr(s1, start, end - start);
	return (trimmed);
}
