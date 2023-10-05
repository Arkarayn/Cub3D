/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <gmattei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:41:40 by gmattei           #+#    #+#             */
/*   Updated: 2023/10/05 15:37:12 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int argc, char **argv)
{
	t_cube	*cube;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (error_init_check(fd, argc, argv) < 0)
		return (-1);
	cube = malloc(sizeof(t_cube));
	if (cub_check(cube, fd) == -1)
		return (err("Map file is not valid", "Check the map"));
	close(fd);
	return (0);
}
