/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 22:20:00 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/06/08 18:02:28 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	def_paths(t_vars *vars)
{
	vars->spts.floor.spt_path = ft_strdup("assets/floor.xpm");
	vars->spts.wall.spt_path = ft_strdup("assets/wall.xpm");
	vars->spts.player.spt_path = ft_strdup("assets/player.xpm");
	vars->spts.colectibles.spt_path = ft_strdup("assets/key.xpm");
	vars->spts.exit.spt_path = ft_strdup("assets/exit.xpm");
	vars->spts.ladder.spt_path = ft_strdup("assets/ladder.xpm");
}

void	draw_sprite(t_vars *vars, t_sprite *sprite, int j, int i)
{
	int				k;
	int				l;
	unsigned int	color;

	k = 0;
	while (k < SCALE)
	{
		l = 0;
		while (l < SCALE)
		{
			color = get_pixel_img(sprite->img, l, k);
			if (color && color != 4278190080)
				put_pixel_img(vars->img, (j * SCALE) + l, (i * SCALE) + \
				k, color);
			l++;
		}
		k++;
	}
}

void	get_sprite(t_vars *vars, t_sprite *sprite, int j, int i)
{
	if (sprite->img.img_ptr == NULL)
	{
		sprite->img.w = SCALE;
		sprite->img.h = SCALE;
		sprite->img.img_ptr = mlx_xpm_file_to_image(vars->mlx_ptr,
				sprite->spt_path, &sprite->img.w, &sprite->img.h);
		sprite->img.addr = mlx_get_data_addr(sprite->img.img_ptr, &(sprite->\
				img.bpp), &(sprite->img.size_line), &(sprite->img.endian));
	}
	draw_sprite(vars, sprite, j, i);
}
