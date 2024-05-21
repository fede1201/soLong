/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:11:51 by fluzi             #+#    #+#             */
/*   Updated: 2024/05/21 15:22:59 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	stamp_img(t_start *map, int y, int x)
{
	if (map->matrix[y][x] == '1')
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
			map->img.wall, x * 100, y * 100);
	else if (map->matrix[y][x] == 'C')
		stamp_coin(map, y, x);
	else if (map->matrix[y][x] == 'E')
	{
		if (map->map.exit.stat == 0)
			mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
				map->img.exit_c, x * 100, y * 100);
		else if (map->map.exit.stat == 1)
			mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
				map->img.exit_o, x * 100, y * 100);
	}
	else if (map->matrix[y][x] == 'P')
		stamp_img_p(map, y, x);
	else if (map->matrix[y][x] == 'A')
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
			map->img.nemico, x * 100, y * 100);
	else
		mlx_put_image_to_window(map->mlx.mlx, map->mlx.win,
			map->img.flor, x * 100, y * 100);
}

void	build_map(t_start *map)
{
	int		y;
	int		x;
	char	*move;

	y = 0;
	x = 0;
	while (y < map->max_y)
	{
		while (x < map->max_x)
		{
			stamp_img(map, y, x);
			x++;
		}
		y++;
		x = 0;
	}
	move = ft_itoa(map->map.move);
	mlx_string_put(map->mlx.mlx, map->mlx.win, 120, 120, 255255255, "Mosse:");
	mlx_string_put(map->mlx.mlx, map->mlx.win, 185, 120, 255255255, move);
	free(move);
}

void	set_image(t_start *map)
{
	map->img.wall = mlx_xpm_file_to_image(map->mlx.mlx, "img/new/wall.xpm",
			&(map->img.width), &(map->img.height));
	map->img.flor = mlx_xpm_file_to_image(map->mlx.mlx, "img/new/flor-_1_.xpm",
			&(map->img.width), &(map->img.height));
	map->img.coin_1 = mlx_xpm_file_to_image(map->mlx.mlx, "img/new/c1.xpm",
			&(map->img.width), &(map->img.height));
	map->img.coin_2 = mlx_xpm_file_to_image(map->mlx.mlx, "img/new/c2.xpm",
			&(map->img.width), &(map->img.height));
	map->img.coin_3 = mlx_xpm_file_to_image(map->mlx.mlx, "img/new/c3.xpm",
			&(map->img.width), &(map->img.height));
	map->img.exit_o = mlx_xpm_file_to_image(map->mlx.mlx,
			"img/new/exit_open.xpm", &(map->img.width), &(map->img.height));
	map->img.exit_c = mlx_xpm_file_to_image(map->mlx.mlx,
			"img/new/exit_close.xpm", &(map->img.width), &(map->img.height));
	map->img.player_l = mlx_xpm_file_to_image(map->mlx.mlx,
			"img/new/p_left.xpm", &(map->img.width), &(map->img.height));
	map->img.player_r = mlx_xpm_file_to_image(map->mlx.mlx,
			"img/new/_p_right.xpm", &(map->img.width), &(map->img.height));
	map->img.player_u = mlx_xpm_file_to_image(map->mlx.mlx,
			"img/new/_p_up_.xpm", &(map->img.width), &(map->img.height));
	map->img.player_d = mlx_xpm_file_to_image(map->mlx.mlx,
			"img/new/_p_down.xpm", &(map->img.width), &(map->img.height));
	map->img.nemico = mlx_xpm_file_to_image(map->mlx.mlx,
			"img/new/Untitled-_2_.xpm", &(map->img.width), &(map->img.height));
}

int	key_hook(int keycode, t_start *map)
{
	if (keycode == KEY_ARROW_RIGHT || keycode == KEY_D)
		move_right(map);
	else if (keycode == KEY_ARROW_LEFT || keycode == KEY_A)
		move_left(map);
	else if (keycode == KEY_ARROW_UP || keycode == KEY_W)
		move_up(map);
	else if (keycode == KEY_ARROW_DOWN || keycode == KEY_S)
		move_down(map);
	else if (keycode == KEY_ESC)
		window_escape(map);
	return (0);
}

void	open_window(t_start *file)
{
	file->mlx.mlx = NULL;
	file->mlx.win = NULL;
	file->mlx.mlx = mlx_init();
	file->mlx.win = mlx_new_window(file->mlx.mlx, file->max_x * 100,
			file->max_y * 100, "test");
	file->img.height = 100;
	file->img.width = 100;
	file->map.n_coin_take = 0;
	file->map.entry.stat = 1;
	file->map.exit.stat = 0;
	file->map.coin_stat = 0;
	set_image(file);
	build_map(file);
	mlx_key_hook(file->mlx.win, key_hook, file);
	mlx_hook(file->mlx.win, 17, 0, window_escape, file);
	mlx_loop_hook(file->mlx.mlx, randome_move_init, file);
	mlx_loop(file->mlx.mlx);
	free_now(file);
}
