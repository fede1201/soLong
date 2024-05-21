/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anemyMove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:00:33 by fluzi             #+#    #+#             */
/*   Updated: 2024/05/14 16:10:25 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	a_move_right(t_start *map)
{
	int	player_x;
	int	player_y;

	player_x = map->map.nemico.x_axis;
	player_y = map->map.nemico.y_axis;
	if (map->matrix[player_y][player_x + 1] != '1')
	{
		map->matrix[player_y][player_x] = '0';
		map->matrix[player_y][player_x + 1] = 'A';
		map->map.nemico.x_axis = player_x + 1;
		map->map.nemico.y_axis = player_y;
		build_map(map);
	}
}

void	a_move_left(t_start *map)
{
	int	player_x;
	int	player_y;

	player_x = map->map.nemico.x_axis;
	player_y = map->map.nemico.y_axis;
	if (map->matrix[player_y][player_x - 1] != '1')
	{
		map->matrix[player_y][player_x] = '0';
		map->matrix[player_y][player_x - 1] = 'A';
		map->map.nemico.x_axis = player_x - 1;
		map->map.nemico.y_axis = player_y;
		build_map(map);
	}
}

void	a_move_up(t_start *map)
{
	int	player_x;
	int	player_y;

	player_x = map->map.nemico.x_axis;
	player_y = map->map.nemico.y_axis;
	if (map->matrix[player_y - 1][player_x] != '1')
	{
		map->matrix[player_y][player_x] = '0';
		map->matrix[player_y - 1][player_x] = 'A';
		map->map.nemico.x_axis = player_x;
		map->map.nemico.y_axis = player_y - 1;
		build_map(map);
	}
}

void	a_move_down(t_start *map)
{
	int	player_x;
	int	player_y;

	player_x = map->map.nemico.x_axis;
	player_y = map->map.nemico.y_axis;
	if (map->matrix[player_y + 1][player_x] != '1')
	{
		map->matrix[player_y][player_x] = '0';
		map->matrix[player_y + 1][player_x] = 'A';
		map->map.nemico.x_axis = player_x;
		map->map.nemico.y_axis = player_y + 1;
		build_map(map);
	}
}

int	game_over(t_start *map)
{
	int	anemy_x;
	int	anemy_y;
	int	player_x;
	int	player_y;

	anemy_x = map->map.nemico.x_axis;
	anemy_y = map->map.nemico.y_axis;
	player_x = map->map.entry.x_axis;
	player_y = map->map.entry.y_axis;
	if (anemy_x == player_x && anemy_y == player_y)
	{
		mlx_destroy_window(map->mlx.mlx, map->mlx.win);
		ft_putstr_fd("GAME OVER", 1);
		exit(1);
		return (0);
	}
	return (1);
}
