/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 19:38:11 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/06/08 18:50:23 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_paths(t_vars *vars)
{
	if (vars->map_path != NULL)
		free(vars->map_path);
	if (vars->spts.floor.spt_path != NULL)
		free(vars->spts.floor.spt_path);
	if (vars->spts.wall.spt_path != NULL)
		free(vars->spts.wall.spt_path);
	if (vars->spts.player.spt_path != NULL)
		free(vars->spts.player.spt_path);
	if (vars->spts.colectibles.spt_path != NULL)
		free(vars->spts.colectibles.spt_path);
	if (vars->spts.exit.spt_path != NULL)
		free(vars->spts.exit.spt_path);
	if (vars->spts.ladder.spt_path != NULL)
		free(vars->spts.ladder.spt_path);
}

void	free_all(t_vars *vars)
{
	int	i;

	i = 0;
	if (vars->map.mtx != NULL)
	{
		while (i < vars->map.h)
		{
			free(vars->map.mtx[i]);
			if (vars->map_cpy.mtx != NULL)
				free(vars->map_cpy.mtx[i]);
			i++;
		}
		free(vars->map.mtx);
		if (vars->map_cpy.mtx != NULL)
			free (vars->map_cpy.mtx);
	}
	free_paths(vars);
	free(vars->mlx_ptr);
}

void	error_exit(t_vars *vars, char *error_str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(error_str, 2);
	del_all_img(vars);
	if (vars->mlx_ptr != NULL && vars->win.win_ptr != NULL)
		mlx_destroy_window(vars->mlx_ptr, vars->win.win_ptr);
	if (vars->mlx_ptr != NULL)
		mlx_destroy_display(vars->mlx_ptr);
	free_all(vars);
	exit(1);
}

int	render(t_vars *vars)
{
	char	*temp;
	char	*mvs;

	temp = ft_itoa(vars->keys.moves);
	mvs = ft_strjoin("MOVES : ", temp);
	free(temp);
	draw_map(vars);
	mlx_put_image_to_window(vars->mlx_ptr, vars->win.win_ptr,
		vars->img.img_ptr, 0, 0);
	mlx_string_put(vars->mlx_ptr, vars->win.win_ptr, (vars->win.w / 2) - \
		(SCALE / 2), vars->win.h - (SCALE * 0.45), 0xFFFFFF, mvs);
	free(mvs);
	return (0);
}
