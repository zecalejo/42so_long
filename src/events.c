/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:17:01 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/06/08 18:15:59 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_moves(t_vars *vars, t_point temp)
{
	if (vars->map.mtx[temp.y][temp.x] == 'E'
		&& vars->map.colectibles > 0)
		return ;
	else if (vars->map.mtx[temp.y][temp.x] == 'C')
		vars->map.colectibles--;
	else if (vars->map.mtx[temp.y][temp.x] == 'E')
		vars->map.exit = 0;
	vars->map.mtx[vars->begin.y][vars->begin.x] = '0';
	vars->map.mtx[temp.y][temp.x] = 'P';
	vars->begin = temp;
	vars->keys.moves++;
}

void	moves(t_vars *vars)
{
	t_point	temp;
	int		prev_mov;

	prev_mov = vars->keys.moves;
	temp = vars->begin;
	if (vars->begin.x < 0 || vars->begin.y < 0 || vars->begin.x >= vars->map.w
		|| vars->begin.y >= vars->map.h)
		return ;
	else
	{
		if (vars->keys.up == 1)
			temp.y--;
		else if (vars->keys.down == 1)
			temp.y++;
		else if (vars->keys.left == 1)
			temp.x--;
		else if (vars->keys.right == 1)
			temp.x++;
		if (vars->map.mtx[temp.y][temp.x] != '1')
			check_moves(vars, temp);
	}
	if (prev_mov != vars->keys.moves)
		printf("MOVES = %d\n", vars->keys.moves);
}

int	read_pkeys(int key_pressed, void *param)
{	
	t_vars	*vars;

	vars = (t_vars *)param;
	if (key_pressed == ESC || !vars)
		exit_win(vars);
	else if (key_pressed == UP || key_pressed == W)
		vars->keys.up = 1;
	else if (key_pressed == DOWN || key_pressed == S)
		vars->keys.down = 1;
	else if (key_pressed == LEFT || key_pressed == A)
		vars->keys.left = 1;
	else if (key_pressed == RIGHT || key_pressed == D)
		vars->keys.right = 1;
	else
		return (-1);
	moves(vars);
	if (vars->map.exit == 0)
		exit_win(vars);
	return (0);
}

int	read_rkeys(int key_released, void *param)
{	
	t_vars	*vars;

	vars = (t_vars *)param;
	if (key_released == UP || key_released == W)
		vars->keys.up = 0;
	else if (key_released == DOWN || key_released == S)
		vars->keys.down = 0;
	else if (key_released == LEFT || key_released == A)
		vars->keys.left = 0;
	else if (key_released == RIGHT || key_released == D)
		vars->keys.right = 0;
	else
		return (-1);
	return (0);
}
