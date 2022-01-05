/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/05 09:05:16 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/27 23:13:11 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_gnl_thanks_norminette_v3(char **dst, size_t *dstsize)
{
	if (!(*dst))
		*dstsize = 0;
	else
		*dstsize = ft_strlen(*dst);
}

char	*ft_gnl_strcat(char **dst, char *src)
{
	size_t	i;
	size_t	size;
	size_t	dstsize;
	char	*tmp;

	ft_gnl_thanks_norminette_v3(dst, &dstsize);
	size = dstsize + ft_strlen(src);
	tmp = malloc(size + 1);
	if (!tmp)
		return (0);
	i = 0;
	while (i < dstsize)
	{
		*(tmp + i) = *((*dst) + i);
		i++;
	}
	while (i < size)
	{
		*(tmp + i) = *(src + i - dstsize);
		i++;
	}
	*(tmp + i) = 0;
	if (*dst)
		free(*dst);
	return (tmp);
}
