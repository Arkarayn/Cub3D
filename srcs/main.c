/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <gmattei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:41:40 by gmattei           #+#    #+#             */
/*   Updated: 2023/10/05 12:45:14 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc != 2)
		return (err("Wrong number of arguments", "Try ./cub3d map.cub"));
	if (open(argv[1], O_RDONLY) <= 0)
		return (err("Map file not found", \
		"Try ./cub3d map.cub or check the path"));
}
