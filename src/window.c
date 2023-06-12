/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:20:27 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/06/12 15:20:29 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	new_win(t_vars *vars, char *str)
{
	vars->win.w = vars->map.w * SCALE;
	vars->win.h = (vars->map.h + 1) * SCALE;
	vars->win.win_ptr = mlx_new_window(vars->mlx_ptr, vars->win.w,
			vars->win.h, str);
}

int	exit_win(t_vars *vars)
{
	del_all_img(vars);
	if (vars->mlx_ptr != NULL && vars->win.win_ptr != NULL)
		mlx_destroy_window(vars->mlx_ptr, vars->win.win_ptr);
	if (vars->mlx_ptr != NULL)
		mlx_destroy_display(vars->mlx_ptr);
	free_all(vars);
	exit(EXIT_SUCCESS);
}
