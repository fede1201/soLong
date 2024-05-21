/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:59:53 by fluzi             #+#    #+#             */
/*   Updated: 2024/05/17 16:01:58 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_STRUCT_H
# define SOLONG_STRUCT_H

# define NUM_COLLECTABLE 30
# define MAX_XPM 5

typedef struct s_img
{
	void	*wall;
	void	*wall_l;
	void	*flor;
	void	*coin_1;
	void	*coin_2;
	void	*coin_3;
	void	*coin_4;
	void	*exit_o;
	void	*exit_c;
	void	*nemico;
	void	*player_r;
	void	*player_l;
	void	*player_u;
	void	*player_d;
	int		width;
	int		height;
}	t_img;

typedef struct s_obj
{
	char	tile_type;
	int		x_axis;
	int		y_axis;
	char	*img[MAX_XPM];
	int		stat;
}	t_obj;

typedef struct s_map
{
	int		move;
	char	*map_path;
	int		heigth;
	int		width;
	t_obj	entry;
	t_obj	nemico;
	t_obj	exit;
	t_obj	ground;
	t_obj	score;
	t_obj	collect[NUM_COLLECTABLE];
	int		n_coin_take;
	int		n_coin;
	int		n_port;
	int		n_exit;
	int		n_enemy;
	int		img_width;
	int		img_height;
	int		coin_stat;
}	t_map;

typedef struct s_window
{
	void	*win;
	void	*mlx;

}	t_window;

typedef struct s_start
{
	t_map		map;
	t_img		img;
	t_window	mlx;
	int			max_x;
	int			max_y;
	char		**matrix;
}	t_start;

#endif