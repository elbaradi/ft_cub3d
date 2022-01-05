/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:10:37 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/26 01:11:54 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**free_array(char **array, unsigned int index)
{
	while (index > 0)
	{
		index--;
		free(array[index]);
	}
	free(array);
	return (0);
}

static char	**create_array(char const *s, char c)
{
	size_t	i;
	size_t	subcount;
	char	**array;

	i = 0;
	subcount = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			subcount++;
		i++;
	}
	array = ft_calloc(subcount + 1, sizeof(char *));
	if (!array)
		return (0);
	return (array);
}

static char	**fill_array(char const *s, char c, char **array)
{
	size_t			i;
	size_t			j;
	unsigned int	sub_index;

	i = 0;
	sub_index = 0;
	while (s[i])
	{
		if (((!i && s[0] != c)) || (s[i] != c && s[i - 1] == c))
		{
			j = 0;
			while (s[i + j] != c && s[i + j])
				j++;
			array[sub_index] = ft_substr(s, i, j);
			if (!array[sub_index])
				return (free_array(array, sub_index));
			sub_index++;
		}
		i++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (0);
	array = create_array(s, c);
	if (!array)
		return (0);
	array = fill_array(s, c, array);
	if (!array)
		return (0);
	return (array);
}
