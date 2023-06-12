/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:20:08 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/06/12 15:20:09 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	new_img(t_vars *vars, int w, int h)
{
	t_img	img;

	img.img_ptr = mlx_new_image(vars->mlx_ptr, w, h);
	img.addr = mlx_get_data_addr(img.img_ptr,
			&(img.bpp), &(img.size_line),
			&(img.endian));
	img.w = w;
	img.h = h;
	return (img);
}

void	del_all_img(t_vars *vars)
{
	if (vars->img.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->img.img_ptr);
	if (vars->spts.floor.img.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->spts.floor.img.img_ptr);
	if (vars->spts.wall.img.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->spts.wall.img.img_ptr);
	if (vars->spts.player.img.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->spts.player.img.img_ptr);
	if (vars->spts.colectibles.img.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->spts.colectibles.img.img_ptr);
	if (vars->spts.exit.img.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->spts.exit.img.img_ptr);
	if (vars->spts.ladder.img.img_ptr)
		mlx_destroy_image(vars->mlx_ptr, vars->spts.ladder.img.img_ptr);
}

void	put_pixel_img(t_img img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && y >= 0 && x < img.w && y < img.h)
	{
		dst = img.addr + (y * img.size_line + x * (img.bpp / 8));
		*(unsigned int *) dst = color;
	}
}

unsigned int	get_pixel_img(t_img img, int x, int y)
{
	return (*(unsigned int *)(img.addr + (y * img.size_line + \
		x * (img.bpp / 8))));
}
