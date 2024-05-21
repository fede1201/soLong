/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:10:09 by fluzi             #+#    #+#             */
/*   Updated: 2024/05/21 15:25:58 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	coin_count(t_start *map, int y, int x)
{
	if (map->matrix[y][x] == 'C')
	{
		map->map.n_coin_take += 1;
		if (map->map.n_coin == map->map.n_coin_take)
			map->map.exit.stat = 1;
	}
}

int	win_function(t_start *map)
{
	int	exit_x;
	int	exit_y;
	int	player_x;
	int	player_y;

	exit_x = map->map.exit.x_axis;
	exit_y = map->map.exit.y_axis;
	player_x = map->map.entry.x_axis;
	player_y = map->map.entry.y_axis;
	if (exit_x == player_x && exit_y == player_y)
	{
		mlx_destroy_window(map->mlx.mlx, map->mlx.win);
		ft_putstr_fd("HAI VINTO", 1);
		exit(1);
		return (0);
	}
	return (1);
}

void	stamp_img_p(t_start *map, int y, int x)
{
	if (map->map.entry.stat == 1)
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
			map->img.player_r, x * 100, y * 100);
	else if (map->map.entry.stat == 2)
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
			map->img.player_d, x * 100, y * 100);
	else if (map->map.entry.stat == 3)
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
			map->img.player_l, x * 100, y * 100);
	else if (map->map.entry.stat == 4)
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
			map->img.player_u, x * 100, y * 100);
}

void	stamp_coin(t_start *map, int y, int x)
{
	int	state;

	state = map->map.coin_stat;
	if (state == 1)
	{
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
			map->img.coin_1, x * 100, y * 100);
	}
	if (state == 2)
	{
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
			map->img.coin_2, x * 100, y * 100);
	}
	if (state == 3)
	{
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
			map->img.coin_3, x * 100, y * 100);
	}
}

void	free_now(t_start *map)
{
	close_matrix(map->matrix);
	free(map->img.wall);
	free(map->img.wall_l);
	free(map->img.flor);
	free(map->img.coin_1);
	free(map->img.coin_2);
	free(map->img.coin_3);
	free(map->img.coin_4);
	free(map->img.exit_o);
	free(map->img.nemico);
	free(map->img.player_r);
	free(map->img.player_l);
	free(map->img.player_u);
	free(map->img.player_u);
	free(map->mlx.mlx);
	free(map->mlx.win);
}
