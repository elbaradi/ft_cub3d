/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   load_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/20 14:19:47 by tel-bara      #+#    #+#                 */
/*   Updated: 2022/01/05 09:27:41 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*load_texture(void *ptr, char *tex, t_vec2i *dim)
{
	void	*img_ptr;

	ft_putstr("Parsing '");
	ft_putstr(tex);
	ft_putstr("'...\n");
	if (tex[ft_strlen(tex) - 1] == 'g')
		img_ptr = mlx_png_file_to_image(ptr, tex, &dim->x, &dim->y);
	else
		img_ptr = mlx_xpm_file_to_image(ptr, tex, &dim->x, &dim->y);
	return (img_ptr);
}

void	get_tex_info(t_tex *tx, double heigth, int sprite)
{
	tx->n.addr = mlx_get_data_addr(tx->n.img, &tx->n.bpp, &tx->n.ll, &tx->n.ed);
	tx->n.ratio = (double)tx->n.dim.y / heigth;
	tx->s.addr = mlx_get_data_addr(tx->s.img, &tx->s.bpp, &tx->s.ll, &tx->s.ed);
	tx->s.ratio = (double)tx->s.dim.y / heigth;
	tx->w.addr = mlx_get_data_addr(tx->w.img, &tx->w.bpp, &tx->w.ll, &tx->w.ed);
	tx->w.ratio = (double)tx->w.dim.y / heigth;
	tx->e.addr = mlx_get_data_addr(tx->e.img, &tx->e.bpp, &tx->e.ll, &tx->e.ed);
	tx->e.ratio = (double)tx->e.dim.y / heigth;
	if (sprite)
	{
		tx->spr.addr = mlx_get_data_addr(tx->spr.img, &tx->spr.bpp,
				&tx->spr.ll, &tx->spr.ed);
		tx->spr.ratio = (double)tx->spr.dim.y / heigth;
	}
	if (!tx->n.addr || !tx->s.addr || !tx->w.addr || !tx->e.addr
		|| (!tx->spr.addr && sprite))
		error("Failed to retrieve texture addresses with MLX.\n");
}

void	get_textures(t_og *og, t_tex *tx)
{
	tx->n.img = load_texture(og->mlx->ptr, og->input->n_texture, &tx->n.dim);
	free(og->input->n_texture);
	tx->s.img = load_texture(og->mlx->ptr, og->input->s_texture, &tx->s.dim);
	free(og->input->s_texture);
	tx->w.img = load_texture(og->mlx->ptr, og->input->w_texture, &tx->w.dim);
	free(og->input->w_texture);
	tx->e.img = load_texture(og->mlx->ptr, og->input->e_texture, &tx->e.dim);
	free(og->input->e_texture);
	if (og->settings->spr_count)
	{
		tx->spr.img = load_texture(og->mlx->ptr, og->input->spr_texture,
				&tx->spr.dim);
		free(og->input->spr_texture);
	}
	if (!tx->n.img || !tx->s.img || !tx->w.img || !tx->e.img
		|| (!tx->spr.img && og->settings->spr_count))
		error("Failed to load textures.\n");
	get_tex_info(tx, og->settings->screen_heigth, og->settings->spr_count);
}
