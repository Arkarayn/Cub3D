/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <gmattei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:57:38 by gmattei           #+#    #+#             */
/*   Updated: 2023/10/09 11:11:16 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	err(char *error, char *solution)
{
	printf(ERROR_DETECTED"\n**Error Detected** \n"RESET""MAGENTA"%s"RESET, error);
	if (solution[0] != '0')
		printf(SOLUTION" \n\n\t\t%s\n\n", solution);
	else
		printf("\n\n");
	return (-1);
}

int	error_init_check(int fd, int argc, char **argv)
{
	if (argc != 2)
		return (err("Wrong number of arguments", "Try ./cub3d maps/map.cub"));
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".cub", 4) != 0)
		return (err("Wrong file extension", "Try ./cub3d maps/map.cub"));
	if (fd <= 0)
		return (err("Map file not found", \
		"Try ./cub3d maps/map.cub or check the path"));
	return (0);
}
