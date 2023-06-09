/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 18:09:00 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/06/09 18:11:37 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	open_maps(t_vars *vars, const char *pathname)
{
	int	fd;

	fd = open(pathname, 0, O_RDONLY);
	if (fd < 0)
		error_exit(vars, "Invalid map file.\n\nChoose one of the following (as a param):\
		\n- map1\n- map42\n");
	return (fd);
}

void	get_map(t_vars *vars, int fd, int count)
{
	char	*s;
	char	*temp;

	if (fd == 0)
		fd = open_maps(vars, vars->map_path);
	s = get_next_line(fd);
	if (s)
		get_map(vars, fd, count + 1);
	if (!vars->map.mtx)
	{
		vars->map.h = count;
		vars->map.mtx = malloc(sizeof(char *) * (count + 1));
	}
	temp = ft_strtrim(s, "\n");
	free(s);
	if (temp)
	{
		vars->map.mtx[count] = ft_strdup(temp);
		free(temp);
	}
	if (count == 0)
		vars->map.w = ft_strlen(vars->map.mtx[count]);
	close(fd);
}

void	parse_map(t_vars *vars, t_point p0)
{
	while (p0.y < vars->map.h)
	{
		p0.x = 0;
		while (p0.x < vars->map.w)
		{
			if (vars->map.mtx[p0.y][p0.x] == 'P')
			{
				vars->map.player++;
				vars->begin = p0;
			}
			else if (vars->map.mtx[p0.y][p0.x] == 'C')
				vars->map.colectibles++;
			else if (vars->map.mtx[p0.y][p0.x] == 'E')
				vars->map.exit++;
			else if (vars->map.mtx[p0.y][p0.x] != '0' &&
				vars->map.mtx[p0.y][p0.x] != '1')
				error_exit(vars, "It's not a valid map.\n\nChoose one of the following (as a param):\
		\n- map1\n- map42\n");
			p0.x++;
		}
		p0.y++;
	}
}

void	map_dup(t_vars *vars)
{
	int		i;

	vars->map_cpy.w = vars->map.w;
	vars->map_cpy.h = vars->map.h;
	vars->map_cpy.player = vars->map.player;
	vars->map_cpy.colectibles = vars->map.colectibles;
	vars->map_cpy.exit = vars->map.exit;
	vars->map_cpy.mtx = malloc(sizeof(char *) * (vars->map.h + 1));
	if (!vars->map_cpy.mtx)
		error_exit(vars, "Failed to allocate memmory.\n");
	i = 0;
	while (i < vars->map.h)
	{
		vars->map_cpy.mtx[i] = ft_strdup(vars->map.mtx[i]);
		i++;
	}
	vars->map_cpy.mtx[i] = NULL;
}
