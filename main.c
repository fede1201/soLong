/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 15:51:18 by fluzi             #+#    #+#             */
/*   Updated: 2024/05/17 17:29:37 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

// static void    stampmat(char **mtr);

int	main(int argc, char **argv)
{
	int		fd;
	char	*str;
	char	**map;
	t_start	file;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	str = get_str_from_file(fd);
	if (str == NULL)
		return (0);
	map = ft_split(str, '\n');
	free(str);
	close(fd);
	if (control(map, &file, argv[1]) == 0)
	{
		close_matrix(map);
		return (0);
	}
	else
	{
		open_window(&file);
		return (1);
	}
}
