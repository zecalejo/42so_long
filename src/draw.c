/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:31:37 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/06/08 18:02:41 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_rect(t_rect rect, t_img img)
{
	double	i;
	double	j;

	i = 0;
	while (i < rect.h && i + rect.y < img.h)
	{
		j = 0;
		while (j < rect.w && j + rect.x < img.w)
		{
			put_pixel_img(img, j + rect.x, i + rect.y, rect.color);
			j++;
		}
		i++;
	}
}

void	draw_circle(t_circle circle, t_img img)
{
	unsigned short int	i;
	unsigned short int	j;

	i = 0;
	while (i < circle.r * 2 && i + circle.y < img.h)
	{
		j = 0;
		while (j < circle.r * 2 && j + circle.x < img.w)
		{
			if (((j - circle.r) * (j - circle.r)) + ((i - circle.r) * \
				(i - circle.r)) < (circle.r * circle.r))
				put_pixel_img(img, j + circle.x, i + circle.y, circle.color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_vars *vars)
{
	unsigned short int	i;
	unsigned short int	j;

	i = 0;
	while (i < vars->map.h)
	{
		j = 0;
		while (j < vars->map.w)
		{
			get_sprite(vars, &vars->spts.floor, j, i);
			if (vars->map.mtx[i][j] == '1')
				get_sprite(vars, &vars->spts.wall, j, i);
			else if (vars->map.mtx[i][j] == 'P')
				get_sprite(vars, &vars->spts.player, j, i);
			else if (vars->map.mtx[i][j] == 'C')
				get_sprite(vars, &vars->spts.colectibles, j, i);
			else if (vars->map.mtx[i][j] == 'E' && vars->map.colectibles == 0)
				get_sprite(vars, &vars->spts.ladder, j, i);
			else if (vars->map.mtx[i][j] == 'E')
				get_sprite(vars, &vars->spts.exit, j, i);
			j++;
		}
		i++;
	}
}
