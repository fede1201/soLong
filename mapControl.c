/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapControl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:45:49 by fluzi             #+#    #+#             */
/*   Updated: 2024/05/21 14:58:54 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

// Verifica che la lunghezza sull'asse X sia sempre la stessa
// Salva dimensioni massime per assi X e Y nella struct

static int	is_rectangle(char **map, t_start *mappa)
{
	int	y;

	y = 0;
	mappa->max_x = ft_strlen(map[y]);
	while (map[y])
	{
		if (ft_strlen(map[y]) != (size_t) mappa->max_x)
			return (error(1));
		y++;
	}
	mappa->max_y = y;
	mappa->matrix = map;
	mappa->map.move = 0;
	return (1);
}

// Controlla che la mappa sia circondata da mura
// Non salva niente nella struct
static int	check_perimeter_wall(t_start *mappa, int y, int x)
{
	while (mappa->matrix[y])
	{
		while (mappa->matrix[y][x])
		{
			if (y == 0 || y == mappa->max_y - 1)
			{
				if (mappa->matrix[y][x] == '1')
					x++;
				else
					return (error(2));
			}
			else if (mappa->matrix[y][0] == '1'
			&& mappa->matrix[y][mappa->max_x - 1] == '1')
				x++;
			else
				return (error(3));
		}
		y++;
		x = 0;
	}
	return (1);
}

// Controlla che siano presenti tutte le caratteristiche necessarie 
// come collezionabili, entrata e uscita.

static int	check_items(t_start *mappa, int y)
{
	int	x;

	while (mappa->matrix[y])
	{
		x = 0;
		while (mappa->matrix[y][x])
		{
			if (mappa->matrix[y][x] == 'C')
				mappa->map.n_coin += 1;
			else if (mappa->matrix[y][x] == 'P')
				mappa->map.n_port += 1;
			else if (mappa->matrix[y][x] == 'E')
				mappa->map.n_exit += 1;
			else if (mappa->matrix[y][x] == 'A')
				mappa->map.n_enemy += 1;
			x++;
		}
		y++;
	}
	if (mappa->map.n_port != 1 || mappa->map.n_coin == 0
		|| mappa->map.n_coin > 5 || mappa->map.n_exit != 1
		|| mappa->map.n_enemy > 1)
		return (error(4));
	return (1);
}
// Verifica che il file sia di tipo ber.

static int	check_extension_ber(char *path)
{
	size_t	len;

	len = ft_strlen(path);
	if ((path[len - 4] == '.') && (path[len - 3] == 'b')
		&& (path[len - 2] == 'e') && (path[len - 1] == 'r'))
		return (1);
	else
		return (error(5));
}
// Funzione inziale cattura errori, verifica che tutte le specifiche 
// siano rispettate lanciando progressivamente i controlli.

int	control(char **map, t_start *mappa, char *path)
{
	mappa->map.n_coin = 0;
	mappa->map.n_port = 0;
	mappa->map.n_exit = 0;
	mappa->map.n_enemy = 0;
	if (is_rectangle(map, mappa) && check_perimeter_wall(mappa, 0, 0)
		&& check_items(mappa, 0) && check_extension_ber(path)
		&& check_path(mappa) && char_check(mappa))
		return (1);
	else
		return (0);
}
