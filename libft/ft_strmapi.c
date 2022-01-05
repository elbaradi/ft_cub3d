/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 19:09:27 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/26 01:09:29 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dup;

	i = 0;
	if (!s)
		return (0);
	dup = ft_strdup(s);
	if (!dup)
		return (0);
	while (s[i])
	{
		dup[i] = (*f)(i, s[i]);
		i++;
	}
	return (dup);
}
