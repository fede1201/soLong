/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapCheckChar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:18:37 by fluzi             #+#    #+#             */
/*   Updated: 2024/05/20 14:32:39 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	char_check(t_start *mappa)
{
	char	a;
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (mappa->matrix[y])
	{
		while (mappa->matrix[y][x])
		{
			a = mappa->matrix[y][x];
			if (a == '0' || a == '1' || a == 'C' || a == 'E' || a == 'P'
				|| a == 'A')
				x++;
			else
				return (error(7));
		}
		y++;
		x = 0;
	}
	return (1);
}
