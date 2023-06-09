/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:25:48 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/06/09 18:19:18 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_init(t_vars *vars)
{
	char	*s;

	s = ft_strjoin("maps/", vars->map_path);
	vars->map_path = ft_strjoin(s, ".ber");
	free(s);
	if (ft_strncmp(vars->map_path + (ft_strlen(vars->map_path) - 4),
			".ber", 4))
		error_exit(vars, "It's not a '.ber' file.\n\nChoose one of the following (as a param):\
		\n- map1\n- map42\n");
	get_map(vars, 0, 0);
	if (vars->map.mtx == NULL)
		error_exit(vars, "Failed to read the map.\n");
	flood_fill(vars);
	vars->mlx_ptr = mlx_init();
	new_win(vars, "zuKEY");
	if (vars->mlx_ptr == NULL || vars->win.win_ptr == NULL)
		error_exit(vars, "Window creation failed.\n");
	vars->img = new_img(vars, vars->win.w, vars->win.h);
	if (vars->img.img_ptr == NULL)
		error_exit(vars, "Image creation failed.");
	def_paths(vars);
}

int	main(int ac, char **av)
{
	static t_vars	vars;

	vars.map_path = av[1];
	if (ac != 2)
		ft_putstr_fd("Choose one of the following (as a param):\
		\n- map1\n- map42\n", 1);
	else
	{
		game_init(&vars);
		mlx_hook(vars.win.win_ptr, 2, 1L << 0, read_pkeys, &vars);
		mlx_hook(vars.win.win_ptr, 3, 1L << 1, read_rkeys, &vars);
		mlx_hook(vars.win.win_ptr, 17, 1L << 0, exit_win, &vars);
		mlx_loop_hook(vars.mlx_ptr, render, &vars);
		mlx_loop(vars.mlx_ptr);
	}
	return (0);
}
