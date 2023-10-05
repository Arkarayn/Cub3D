/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:57:38 by gmattei           #+#    #+#             */
/*   Updated: 2023/09/29 17:57:39 by gmattei          ###   ########.fr       */
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
