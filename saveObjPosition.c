/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveObjPosition.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:44:13 by fluzi             #+#    #+#             */
/*   Updated: 2024/05/17 13:35:56 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

//
// Registra le posizione e degli oggetti nello spazio 
// Prima funzione scorre tutto lo spazio, quanto trova un target invia 
// informazioni a funzione save che si occupa di registrare i dati nella struct
//

static void	save_position_struct(t_start *mappa, int y, int x, char type)
{
	if (type == 'P')
	{
		mappa->map.entry.tile_type = 'P';
		mappa->map.entry.x_axis = x;
		mappa->map.entry.y_axis = y;
	}
	else if (type == 'E')
	{
		mappa->map.exit.tile_type = 'E';
		mappa->map.exit.x_axis = x;
		mappa->map.exit.y_axis = y;
	}
	else if (type == 'A')
	{
		mappa->map.nemico.tile_type = 'A';
		mappa->map.nemico.x_axis = x;
		mappa->map.nemico.y_axis = y;
	}
}

void	save_position(t_start *mappa)
{
	int	y;
	int	x;

	y = 0;
	while (y < mappa->max_y)
	{
		x = 0;
		while (x < mappa->max_x)
		{
			if (mappa->matrix[y][x] == 'P')
				save_position_struct(mappa, y, x, 'P');
			if (mappa->matrix[y][x] == 'A')
				save_position_struct(mappa, y, x, 'A');
			if (mappa->matrix[y][x] == 'E')
				save_position_struct(mappa, y, x, 'E');
			x++;
		}
		y++;
	}
}
