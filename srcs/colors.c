/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/01/16 18:15:40 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/25 23:20:57 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	create_rgb(int r, int g, int b)
{
	return (0xFFFFFF & (r << 16 | g << 8 | b));
}

int	get_r(int rgb)
{
	return ((rgb & (0xFF << 16)) >> 16);
}

int	get_g(int rgb)
{
	return ((rgb & (0xFF << 8)) >> 8);
}

int	get_b(int rgb)
{
	return (rgb & 0xFF);
}

int	add_shade(int rgb, double shading)
{
	int		r;
	int		g;
	int		b;

	r = get_r(rgb) * shading;
	g = get_g(rgb) * shading;
	b = get_b(rgb) * shading;
	return (create_rgb(r, g, b));
}
