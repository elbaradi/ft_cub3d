/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parse_settings_wefc.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/06 17:26:52 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 09:27:21 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_we(char *line, t_input *input)
{
	int	i;

	i = 2;
	if (input->init.west_id)
		return (-1);
	input->init.west_id = 1;
	while (*(line + i) == ' ')
		i++;
	if (*(line + i) && *(line + i - 1) == ' ')
	{
		input->w_texture = ft_strdup(line + i);
		if (!input->w_texture)
			error("Failed to allocate memory for west texture string.\n");
		return (1);
	}
	return (-1);
}

int	parse_ea(char *line, t_input *input)
{
	int	i;

	i = 2;
	if (input->init.east_id)
		return (-1);
	input->init.east_id = 1;
	while (*(line + i) == ' ')
		i++;
	if (*(line + i) && *(line + i - 1) == ' ')
	{
		input->e_texture = ft_strdup(line + i);
		if (!input->e_texture)
			error("Failed to allocate memory for east texture string.\n");
		return (1);
	}
	return (-1);
}

int	parse_rgb(char *line, int *red, int *green, int *blue)
{
	if (ft_isdigit(*line) && *(line - 1) == ' ')
	{
		*red = ft_atoi(line);
		line += ft_numlen(*red) + 1;
	}
	else
		return (-1);
	if (ft_isdigit(*line) && *(line - 1) == ',')
	{
		*green = ft_atoi(line);
		line += ft_numlen(*green) + 1;
	}
	else
		return (-1);
	if (ft_isdigit(*line) && *(line - 1) == ',')
	{
		*blue = ft_atoi(line);
		line += ft_numlen(*blue);
	}
	else
		return (-1);
	return (!(*line) && *red <= 255 && *green <= 255 && *blue <= 255
		&& *red >= 0 && *green >= 0 && *blue >= 0);
}

int	parse_f(char *line, t_input *input)
{
	int	i;
	int	rtn;

	i = 1;
	if (input->init.floor_id)
		return (-1);
	input->init.floor_id = 1;
	while (*(line + i) == ' ')
		i++;
	rtn = parse_rgb((line + i), &input->floor_r, &input->floor_g,
			&input->floor_b);
	if (rtn)
		input->f_color = create_rgb(input->floor_r, input->floor_g,
				input->floor_b);
	return (rtn);
}

int	parse_c(char *line, t_input *input)
{
	int	i;
	int	rtn;

	i = 1;
	if (input->init.ceiling_id)
		return (-1);
	input->init.ceiling_id = 1;
	while (*(line + i) == ' ')
		i++;
	rtn = parse_rgb((line + i), &input->ceiling_r, &input->ceiling_g,
			&input->ceiling_b);
	if (rtn)
		input->c_color = create_rgb(input->ceiling_r, input->ceiling_g,
				input->ceiling_b);
	return (rtn);
}
