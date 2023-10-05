/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <gmattei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:49:08 by gmattei           #+#    #+#             */
/*   Updated: 2023/10/05 15:27:12 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

char	*get_line(int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = malloc(sizeof(char) * 500);
	while (read(fd, &line[i], 1) > 0)
	{
		if (line[i] == '\n')
			break ;
		i++;
		if (i > 99)
		{
			err("Line too long", "Check the map");
			free(line);
			return (NULL);
		}
	}
	line[i] = '\0';
	return (line);
}
