/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/29 14:10:37 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 09:27:33 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static char	**fill_array(char const *s, char **array, int width)
{
	size_t			i;
	size_t			j;
	unsigned int	sub_index;

	i = 0;
	sub_index = 1;
	while (s[i])
	{
		if (((!i && s[0] != '\n')) || (s[i] != '\n' && s[i - 1] == '\n'))
		{
			j = 0;
			while (s[i + j] != '\n' && s[i + j])
				j++;
			array[sub_index] = malloc((width + 1) * sizeof(char));
			if (!array[sub_index])
				return (free_array(array, sub_index));
			array[sub_index][0] = '.';
			ft_memcpy((*(array + sub_index) + 1), s + i, j);
			ft_memset((*(array + sub_index) + (j + 1)), '.', width - (j + 1));
			array[sub_index][width] = 0;
			sub_index++;
		}
		i++;
	}
	return (array);
}

char	**make_map(char const *s, int heigth, int width)
{
	char	**array;

	if (!s)
		return (0);
	array = ft_calloc(heigth + 1, sizeof(char *));
	if (!array)
		return (0);
	array[0] = malloc((width + 1) * sizeof(char));
	if (!array[0])
		return (0);
	ft_memset(array[0], '.', width);
	array[0][width] = 0;
	array = fill_array(s, array, width);
	if (!array)
		return (0);
	array[heigth - 1] = malloc((width + 1) * sizeof(char));
	if (!array[heigth - 1])
		return (free_array(array, heigth - 1));
	ft_memset(array[heigth - 1], '.', width);
	array[heigth - 1][width] = 0;
	return (array);
}
