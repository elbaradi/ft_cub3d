/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   import_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/04 16:10:07 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 09:27:45 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	parse_settings(char *line, t_input *input)
{
	int	err;

	err = 0;
	if (!*line)
		return ;
	if (!input->init.res_id && ft_strnstr(line, "R ", 2))
		err = parse_r(line, input);
	else if (!input->init.north_id && ft_strnstr(line, "NO ", 3))
		err = parse_no(line, input);
	else if (!input->init.south_id && ft_strnstr(line, "SO ", 3))
		err = parse_so(line, input);
	else if (!input->init.west_id && ft_strnstr(line, "WE ", 3))
		err = parse_we(line, input);
	else if (!input->init.east_id && ft_strnstr(line, "EA ", 3))
		err = parse_ea(line, input);
	else if (!input->init.sprite_id && ft_strnstr(line, "S ", 2))
		err = parse_s(line, input);
	else if (!input->init.floor_id && ft_strnstr(line, "F ", 2))
		err = parse_f(line, input);
	else if (!input->init.ceiling_id && ft_strnstr(line, "C ", 2))
		err = parse_c(line, input);
	if (err < 1)
		error("Map settings appear to be invalid.\n");
}

static int	parse_map_2(char *line, t_input *input)
{
	int		i;

	i = 0;
	while (*(line + i))
	{
		if (!(line[i] == '1' || line[i] == '0' || line[i] == 'N'
				|| line[i] == 'S' || line[i] == 'W' || line[i] == 'E'
				|| line[i] == ' ' || (line[i] == '2' && input->init.sprite_id)))
			return (-1);
		if (*(line + i) == '2')
			input->sprite_count++;
		if (line[i] == 78 || line[i] == 83 || line[i] == 87 || line[i] == 69)
		{
			if (input->spawn_dir)
				return (-1);
			input->spawn_dir = *(line + i);
			*(line + i) = '0';
			input->spawn = (t_vec2i){i + 1, input->map_heigth};
		}
		i++;
	}
	input->map_heigth++;
	if (i + 2 > input->map_width)
		input->map_width = i + 2;
	return (1);
}

static int	parse_map(char *line, t_input *input)
{
	char	*tmp;

	if (input->init.map_start && !(*line))
		error("Encountered empty line while parsing map.\n");
	else
	{
		if (parse_map_2(line, input) == -1)
			error("Invalid character in map.\n");
		tmp = input->map;
		input->map = ft_strjoin(input->map, line);
		if (!input->map)
			error("Memory allocation failed.\n");
		free(tmp);
		tmp = input->map;
		input->map = ft_strjoin(input->map, "\n");
		if (!input->map)
			error("Memory allocation failed.\n");
		free(tmp);
	}
	return (1);
}

void	init_map_vars(t_input *input)
{
	ft_bzero(&(input->init), sizeof(input->init));
	input->x_render_size = -1;
	input->y_render_size = -1;
	input->n_texture = 0;
	input->s_texture = 0;
	input->w_texture = 0;
	input->e_texture = 0;
	input->spr_texture = 0;
	input->floor_r = -1;
	input->floor_g = -1;
	input->floor_b = -1;
	input->ceiling_r = -1;
	input->ceiling_g = -1;
	input->ceiling_b = -1;
	input->map = ft_strdup("");
	input->map_heigth = 2;
	input->map_width = 0;
	input->spawn = (t_vec2i){0, 0};
	input->spawn_dir = 0;
	input->sprite_count = 0;
}

void	import_map(t_input *input, char *file)
{
	char	*line;
	int		fd;
	int		read;

	line = 0;
	read = 1;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Failed to open .cub.\n");
	ft_putstr("Parsing .cub file...\n");
	while (read)
	{
		read = get_next_line(fd, &line);
		if (read == -1)
			error("Reading .cub failed.\n");
		if (*line == ' ' || *line == '1' || *line == '0' || *line == '2')
			input->init.map_start = 1;
		if (!input->init.map_start)
			parse_settings(line, input);
		if (input->init.map_start)
			parse_map(line, input);
		free(line);
	}
}
