/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 13:29:09 by fluzi             #+#    #+#             */
/*   Updated: 2024/05/21 14:51:13 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

// 
//
// Error handling(Definizione errori su: libraries/error_handling.h)
// Cod: 0 "Invalide map file"
// Cod: 1 "Invalid map, the map provided is not a square."
// Cod: 2 "Invalid map, above or below it is not surrounded by walls."
// Cod: 3 "Invalid map, on the right or left it is not surrounded by walls."
// Cod: 4 "Invalid map, there are not all required items on this map.
//			Check and try again."
// Cod: 5 "Invalid map, you provided a file with an invalid extension, 
//			(.ber) is the only one allowed."
//
//

int	error(int error)
{
	ft_putstr_fd("Error\n", 1);
	if (error == 1)
		ft_putstr_fd(ERROR_1, 1);
	else if (error == 2)
		ft_putstr_fd(ERROR_2, 1);
	else if (error == 3)
		ft_putstr_fd(ERROR_3, 1);
	else if (error == 4)
		ft_putstr_fd(ERROR_4, 1);
	else if (error == 5)
		ft_putstr_fd(ERROR_5, 1);
	else if (error == 6)
		ft_putstr_fd(ERROR_6, 1);
	else if (error == 7)
		ft_putstr_fd(ERROR_7, 1);
	return (0);
}

int	close_matrix(char **matrix)
{
	int	y;

	y = 0;
	while (matrix[y] != NULL)
	{
		free(matrix[y]);
		y++;
	}
	free(matrix);
	return (1);
}
