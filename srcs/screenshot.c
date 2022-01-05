/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screenshot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/19 19:17:17 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 09:27:16 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hex_to_24bit(char *str, unsigned int hex)
{
	str[0] = (unsigned char)(hex & 0xFF);
	str[1] = (unsigned char)((hex & 0xFF00) >> 8);
	str[2] = (unsigned char)((hex & 0xFF0000) >> 16);
}

void	hex_to_32bit(char *str, unsigned int hex)
{
	str[0] = (unsigned char)(hex & 0xFF);
	str[1] = (unsigned char)((hex & 0xFF00) >> 8);
	str[2] = (unsigned char)((hex & 0xFF0000) >> 16);
	str[3] = (unsigned char)((hex & 0xFF000000) >> 24);
}

char	*header_string(t_settings *settings, unsigned int bytes)
{
	char	*header;

	header = ft_calloc(54, sizeof(char));
	if (!header)
		error("Memory allocation for .bmp header failed.\n");
	hex_to_24bit(header, 19778);
	hex_to_32bit(header + 2, 54 + bytes);
	hex_to_32bit(header + 10, 54);
	hex_to_24bit(header + 14, 40);
	hex_to_32bit(header + 18, settings->screen_width);
	hex_to_32bit(header + 22, settings->screen_heigth);
	hex_to_24bit(header + 26, 1);
	hex_to_24bit(header + 28, 24);
	hex_to_32bit(header + 34, bytes);
	return (header);
}

char	*bitmap_string(t_img *img, t_settings *settings,
		int padding, unsigned int bytes)
{
	char	*bmp;
	int		i;
	t_vec2i	pos;

	bmp = ft_calloc(bytes, sizeof(char));
	if (!bmp)
		error("Memory allocation for .bmp data failed.\n");
	i = 0;
	pos.y = settings->screen_heigth - 1;
	while (pos.y >= 0)
	{
		pos.x = 0;
		while (pos.x < settings->screen_width)
		{
			hex_to_24bit(bmp + i, *(unsigned int *)(img->addr
				+ (pos.y * img->ll) + (pos.x * (img->bpp / 8))));
			i += 3;
			pos.x++;
		}
		i += padding;
		pos.y--;
	}
	return (bmp);
}

#ifndef BONUS

void	screenshot(t_img *img, t_settings *settings)
{
	int				fd;
	int				padding;
	unsigned int	bytes;
	char			*header;
	char			*bmp;

	fd = open("./screenshot/screenshot.bmp", (O_WRONLY | O_CREAT | O_TRUNC
				| O_APPEND), 0666);
	if (fd == -1)
		error("Failed to create screenshot.bmp using open().\n");
	padding = (4 - ((settings->screen_width * 3) % 4)) % 4;
	bytes = settings->screen_heigth * ((settings->screen_width * 3) + padding);
	header = header_string(settings, bytes);
	bmp = bitmap_string(img, settings, padding, bytes);
	if (write(fd, header, 54) == -1)
		error("Failed to write header data into screenshot.bmp.\n");
	free(header);
	if (write(fd, bmp, bytes) == -1)
		error("Failed to write bitmap data into screenshot.bmp.\n");
	free(bmp);
	ft_putstr("Saved as screenshot.bmp in ./screenshot/\n");
	exit(EXIT_SUCCESS);
}

#endif
