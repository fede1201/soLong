/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdToStr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fluzi <fluzi@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 14:44:59 by fluzi             #+#    #+#             */
/*   Updated: 2024/05/17 17:30:56 by fluzi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	*get_str_from_file(int fd)
{
	char	buffer[10];
	char	*ret;
	char	*tofree;
	ssize_t	bereed;

	bereed = 1;
	ret = ft_strdup("");
	while (bereed > 0)
	{
		bereed = read(fd, buffer, 9);
		if (bereed > 0)
		{
			buffer[bereed] = 0;
			tofree = ret;
			ret = ft_strjoin(tofree, buffer);
			free(tofree);
		}
	}
	if (ft_strlen(ret) == 0 || fd < 0)
	{
		free(ret);
		ft_putstr_fd("File not found", 1);
		return (NULL);
	}
	return (ret);
}
