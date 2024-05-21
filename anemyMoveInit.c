/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anemyMoveInit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 16:17:01 by fluzi             #+#    #+#             */
/*   Updated: 2024/05/20 14:38:11 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	randome_move_init(t_start *map)
{
	int	numero;
	int	anemy_x;
	int	anemy_y;

	usleep(99000);
	if (map->map.n_enemy > 0)
	{
		game_over(map);
		srand(time(NULL));
		numero = rand() % 4;
		anemy_x = map->map.nemico.x_axis;
		anemy_y = map->map.nemico.y_axis;
		move_random(map, numero, anemy_x, anemy_y);
	}
	game_over(map);
	if (map->map.coin_stat >= 3)
		map->map.coin_stat = 1;
	else
		map->map.coin_stat++;
	build_map(map);
	return (1);
}

void	help_move0(t_start *map, int x, int y)
{
	if (map->matrix[y - 1][x] != '1' && map->matrix[y - 1][x] != 'C'
	&& map->matrix[y - 1][x] != 'E')
		a_move_up(map);
	else
		random1(map);
}

void	help_move1(t_start *map, int x, int y)
{
	if (map->matrix[y][x + 1] != '1' && map->matrix[y][x + 1] != 'C'
	&& map->matrix[y][x + 1] != 'E')
		a_move_right(map);
	else
		random2(map);
}

void	help_move2(t_start *map, int x, int y)
{
	if (map->matrix[y + 1][x] != '1' && map->matrix[y + 1][x] != 'C'
	&& map->matrix[y + 1][x] != 'E')
		a_move_down(map);
	else
		random3(map);
}

void	help_move3(t_start *map, int x, int y)
{
	if (map->matrix[y][x - 1] != '1' && map->matrix[y][x - 1] != 'C'
	&& map->matrix[y][x - 1] != 'E')
		a_move_left(map);
	else
		random4(map);
}
