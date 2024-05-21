/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:04:53 by fluzi             #+#    #+#             */
/*   Updated: 2024/05/20 14:25:50 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "libraries/solong_struct.h"
# include "libraries/error_handling.h"
# include "mlx/mlx.h"
# include <time.h>   

# define KEY_ARROW_RIGHT 65363 
# define KEY_ARROW_LEFT 65361
# define KEY_ARROW_UP 65362 
# define KEY_ARROW_DOWN 65364

# define KEY_D 100 
# define KEY_A 97
# define KEY_W 119 
# define KEY_S 115

# define KEY_ESC 65307

char	*get_str_from_file(int fd);
int		control(char **map, t_start *mappa, char *path);
int		error(int error);
int		check_path(t_start *mappa);
void	save_position(t_start *mappa);
void	stampmat(char **mtr);
int		close_matrix(char **matrix);
void	open_window(t_start *file);
void	move_right(t_start *map);
void	move_left(t_start *map);
void	move_up(t_start *map);
void	move_down(t_start *map);
void	build_map(t_start *map);
int		window_escape(t_start *map);
int		randome_move_init(t_start *map);
int		move_random(t_start *map, int numero, int anemyX, int anemyY);
void	a_move_right(t_start *map);
void	a_move_left(t_start *map);
void	a_move_up(t_start *map);
void	a_move_down(t_start *map);
void	stamp_img(t_start *map, int y, int x);
int		game_over(t_start *map);
int		win_function(t_start *map);
void	coin_count(t_start *map, int y, int x);
void	random1(t_start *map);
void	random2(t_start *map);
void	random3(t_start *map);
void	random4(t_start *map);
void	help_move0(t_start *map, int x, int y);
void	help_move1(t_start *map, int x, int y);
void	help_move2(t_start *map, int x, int y);
void	help_move3(t_start *map, int x, int y);
void	stamp_img_p(t_start *map, int y, int x);
void	stamp_coin(t_start *map, int y, int x);
void	free_now(t_start *map);
int		char_check(t_start *mappa);

#endif 