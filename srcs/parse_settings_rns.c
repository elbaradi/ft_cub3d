/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_settings_rns.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 15:54:20 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 09:27:25 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_r(char *line, t_input *input)
{
	int	i;

	i = 1;
	if (input->init.res_id)
		return (-1);
	input->init.res_id = 1;
	while (*(line + i) == ' ')
		i++;
	if (ft_isdigit(*(line + i)) && *(line + i - 1) == ' ')
	{
		input->x_render_size = ft_atoi(line + i);
		i += ft_numlen(input->x_render_size);
	}
	while (*(line + i) == ' ')
		i++;
	if (ft_isdigit(*(line + i)) && *(line + i - 1) == ' ')
	{
		input->y_render_size = ft_atoi(line + i);
		i += ft_numlen(input->y_render_size);
	}
	if (*(line + i) || input->x_render_size < 1 || input->y_render_size < 1)
		return (-1);
	return (1);
}

int	parse_no(char *line, t_input *input)
{
	int	i;

	i = 2;
	if (input->init.north_id)
		return (-1);
	input->init.north_id = 1;
	while (*(line + i) == ' ')
		i++;
	if (*(line + i) && *(line + i - 1) == ' ')
	{
		input->n_texture = ft_strdup(line + i);
		if (!input->n_texture)
			error("Failed to allocate memory for north texture string.\n");
		return (1);
	}
	return (-1);
}

int	parse_so(char *line, t_input *input)
{
	int	i;

	i = 2;
	if (input->init.south_id)
		return (-1);
	input->init.south_id = 1;
	while (*(line + i) == ' ')
		i++;
	if (*(line + i) && *(line + i - 1) == ' ')
	{
		input->s_texture = ft_strdup(line + i);
		if (!input->s_texture)
			error("Failed to allocate memory for south texture string.\n");
		return (1);
	}
	return (-1);
}

int	parse_s(char *line, t_input *input)
{
	int	i;

	i = 1;
	if (input->init.sprite_id)
		return (-1);
	input->init.sprite_id = 1;
	while (*(line + i) == ' ')
		i++;
	if (*(line + i) && *(line + i - 1) == ' ')
	{
		input->spr_texture = ft_strdup(line + i);
		if (!input->spr_texture)
			error("Failed to allocate memory for sprite texture string.\n");
		return (1);
	}
	return (-1);
}
