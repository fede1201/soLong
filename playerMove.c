/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerMove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:44:28 by fluzi             #+#    #+#             */
/*   Updated: 2024/05/15 16:00:16 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	move_right(t_start *map)
{
	int	x;
	int	y;

	x = map->map.entry.x_axis;
	y = map->map.entry.y_axis;
	if ((map->matrix[y][x + 1] != '1' && map->matrix[y][x + 1] != 'E')
		|| (map->matrix[y][x + 1] == 'E'
		&& map->map.n_coin == map->map.n_coin_take))
	{
		coin_count(map, y, x + 1);
		map->matrix[y][x] = '0';
		map->matrix[y][x + 1] = 'P';
		map->map.entry.x_axis = x + 1;
		map->map.entry.y_axis = y;
		map->map.move += 1;
		map->map.entry.stat = 1;
		win_function(map);
		build_map(map);
	}
}

void	move_left(t_start *map)
{
	int	x;
	int	y;

	x = map->map.entry.x_axis;
	y = map->map.entry.y_axis;
	if ((map->matrix[y][x - 1] != '1' && map->matrix[y][x - 1] != 'E')
		|| (map->matrix[y][x - 1] == 'E'
		&& map->map.n_coin == map->map.n_coin_take))
	{
		coin_count(map, y, x - 1);
		map->matrix[y][x] = '0';
		map->matrix[y][x - 1] = 'P';
		map->map.entry.x_axis = x - 1;
		map->map.entry.y_axis = y;
		map->map.move += 1;
		map->map.entry.stat = 3;
		win_function(map);
		build_map(map);
	}
}

void	move_up(t_start *map)
{
	int	x;
	int	y;

	x = map->map.entry.x_axis;
	y = map->map.entry.y_axis;
	if ((map->matrix[y - 1][x] != '1' && map->matrix[y - 1][x] != 'E')
		|| (map->matrix[y - 1][x] == 'E'
		&& map->map.n_coin == map->map.n_coin_take))
	{
		coin_count(map, y - 1, x);
		map->matrix[y][x] = '0';
		map->matrix[y - 1][x] = 'P';
		map->map.entry.x_axis = x;
		map->map.entry.y_axis = y - 1;
		map->map.move += 1;
		map->map.entry.stat = 4;
		win_function(map);
		build_map(map);
	}
}

void	move_down(t_start *map)
{
	int	x;
	int	y;

	x = map->map.entry.x_axis;
	y = map->map.entry.y_axis;
	if ((map->matrix[y + 1][x] != '1' && map->matrix[y + 1][x] != 'E')
		|| (map->matrix[y + 1][x] == 'E'
		&& map->map.n_coin == map->map.n_coin_take))
	{
		coin_count(map, y + 1, x);
		map->matrix[y][x] = '0';
		map->matrix[y + 1][x] = 'P';
		map->map.entry.x_axis = x;
		map->map.entry.y_axis = y + 1;
		map->map.move += 1;
		map->map.entry.stat = 2;
		win_function(map);
		build_map(map);
	}
}

int	window_escape(t_start *map)
{
	mlx_destroy_window(map->mlx.mlx, map->mlx.win);
	exit(1);
	return (1);
}
