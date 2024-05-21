/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anemyRandomMove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:19:50 by fluzi             #+#    #+#             */
/*   Updated: 2024/05/17 17:40:21 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	random1(t_start *map)
{
	int	x;
	int	y;

	x = map->map.nemico.x_axis;
	y = map->map.nemico.y_axis;
	if (map->matrix[y - 1][x] != '1' && map->matrix[y - 1][x] != 'C'
	&& map->matrix[y - 1][x] != 'E')
		a_move_up(map);
	else if (map->matrix[y][x + 1] != '1' && map->matrix[y][x + 1] != 'C'
	&& map->matrix[y][x + 1] != 'E')
		a_move_right(map);
	else if (map->matrix[y + 1][x] != '1' && map->matrix[y + 1][x] != 'C'
	&& map->matrix[y + 1][x] != 'E')
		a_move_down(map);
	else if (map->matrix[y][x - 1] != '1' && map->matrix[y][x - 1] != 'C'
	&& map->matrix[y][x - 1] != 'E')
		a_move_left(map);
}

void	random2(t_start *map)
{
	int	x;
	int	y;

	x = map->map.nemico.x_axis;
	y = map->map.nemico.y_axis;
	if (map->matrix[y][x + 1] != '1' && map->matrix[y][x + 1] != 'C'
		&& map->matrix[y][x + 1] != 'E')
		a_move_right(map);
	else if (map->matrix[y + 1][x] != '1' && map->matrix[y + 1][x] != 'C'
		&& map->matrix[y + 1][x] != 'E')
		a_move_down(map);
	else if (map->matrix[y][x - 1] != '1' && map->matrix[y][x - 1] != 'C'
		&& map->matrix[y][x - 1] != 'E')
		a_move_left(map);
	else if (map->matrix[y - 1][x] != '1' && map->matrix[y - 1][x] != 'C'
		&& map->matrix[y - 1][x] != 'E')
		a_move_up(map);
}

void	random3(t_start *map)
{
	int	x;
	int	y;

	x = map->map.nemico.x_axis;
	y = map->map.nemico.y_axis;
	if (map->matrix[y + 1][x] != '1' && map->matrix[y + 1][x] != 'C'
	&& map->matrix[y + 1][x] != 'E')
		a_move_down(map);
	else if (map->matrix[y][x - 1] != '1' && map->matrix[y][x - 1] != 'C'
		&& map->matrix[y][x - 1] != 'E')
		a_move_left(map);
	else if (map->matrix[y - 1][x] != '1' && map->matrix[y - 1][x] != 'C'
		&& map->matrix[y - 1][x] != 'E')
		a_move_up(map);
	else if (map->matrix[y][x + 1] != '1' && map->matrix[y][x + 1] != 'C'
		&& map->matrix[y][x + 1] != 'E')
		a_move_right(map);
}

void	random4(t_start *map)
{
	int	x;
	int	y;

	x = map->map.nemico.x_axis;
	y = map->map.nemico.y_axis;
	if (map->matrix[y][x - 1] != '1' && map->matrix[y][x - 1] != 'C'
		&& map->matrix[y][x - 1] != 'E')
		a_move_left(map);
	else if (map->matrix[y - 1][x] != '1' && map->matrix[y - 1][x] != 'C'
		&& map->matrix[y - 1][x] != 'E')
		a_move_up(map);
	else if (map->matrix[y][x + 1] != '1' && map->matrix[y][x + 1] != 'C'
		&& map->matrix[y][x + 1] != 'E')
		a_move_right(map);
	if (map->matrix[y + 1][x] != '1' && map->matrix[y + 1][x] != 'C'
		&& map->matrix[y + 1][x] != 'E')
		a_move_down(map);
}

int	move_random(t_start *map, int numero, int x, int y)
{
	if (numero == 0)
		help_move0(map, x, y);
	else if (numero == 1)
		help_move1(map, x, y);
	else if (numero == 2)
		help_move2(map, x, y);
	else if (numero == 3)
		help_move3(map, x, y);
	return (1);
}
