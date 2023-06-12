/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:19:49 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/06/12 15:19:53 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_check(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map.h)
	{
		if ((int)ft_strlen(vars->map.mtx[i]) != vars->map.w)
			return (1);
		else if (vars->map.mtx[i][0] != '1'
			|| vars->map.mtx[i][vars->map.w - 1] != '1')
			return (1);
		j = 0;
		while ((i == 0 || i == vars->map.h - 1) && vars->map.mtx[i][j])
		{
			if (vars->map.mtx[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	if (vars->map.player != 1 || vars->map.colectibles
		!= vars->map_cpy.colectibles || vars->map.exit != 1)
		return (1);
	return (0);
}

void	f_fill(t_vars *vars, int hrz, int vrt)
{
	if (hrz < 0 || vrt < 0 || hrz >= vars->map_cpy.w || vrt >= vars->map_cpy.h
		|| vars->map_cpy.mtx[vrt][hrz] == '1' ||
			vars->map_cpy.mtx[vrt][hrz] == 'F')
		return ;
	else if (vars->map_cpy.mtx[vrt][hrz] == 'C')
		vars->map_cpy.colectibles++;
	vars->map_cpy.mtx[vrt][hrz] = 'F';
	f_fill(vars, hrz + 1, vrt);
	f_fill(vars, hrz - 1, vrt);
	f_fill(vars, hrz, vrt + 1);
	f_fill(vars, hrz, vrt - 1);
}

void	flood_fill(t_vars *vars)
{
	parse_map(vars, (t_point){0, 0});
	map_dup(vars);
	vars->map_cpy.colectibles = 0;
	f_fill(vars, vars->begin.x, vars->begin.y);
	if (map_check(vars))
		error_exit(vars, "Map checker: KO!\n");
	else
		ft_putstr_fd("Map checker: OK!\n", 1);
}
