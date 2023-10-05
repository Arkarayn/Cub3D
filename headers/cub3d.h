/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <gmattei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:57:21 by gmattei           #+#    #+#             */
/*   Updated: 2023/10/05 15:33:42 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
	------------LIBRARIES------------
*/

# include "../ctm/ctm_libs/ctm_libs.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

/*
	------------COLORS & STYLES------------
*/

// COLORS

# define BLACK "\033[0;30m"
# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define WHITE "\033[0;37m"

// STYLES

# define BOLD "\033[1m"
# define GREY "\033[2m"
# define ITALIC "\033[3m"
# define UNDERLINE "\033[4m"
# define BLINK "\033[5m"
# define REVERSE "\033[7m"
# define STRIKETHROUGH "\033[9m"

// RESET

# define RESET "\033[0m"

// CUSTOM

// Bold & Italic & Red
# define ERROR_DETECTED "\033[1;3;31m"
// Italic & Red
# define ERROR "\033[3;31m"
// Bold & Yellow
# define SOLUTION "\033[1;33m"

/*
	------------STRUCTURES------------
*/

/*
	--|res_x|--:		Resolution X
	--|res_y|--:		Resolution Y
	--|no|--:			North texture path
	--|so|--:			South texture path
	--|we|--:			West texture path
	--|ea|--:			East texture path
	--|s|--:			Sprite texture path
	--|f|--:			Floor color
	--|c|--:			Ceiling color
	--|map|--:			Map

	Map structure
*/
typedef struct s_map
{
	int		res_x;
	int		res_y;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*s;
	int		f;
	int		c;
	char	**map;
}	t_map;

/*
	--|map|--:			Map

	General structure
*/
typedef struct s_cube
{
	t_map	map;
}	t_cube;

/*
	------------FUNCTIONS------------
*/

/*
	---Error Handler----

	Prints error and optional solution (0 for no solution)
	Returns -1

	int err(char *error, char *solution);
*/
int		err(char *error, char *solution);

/*
	---Error Default Checker----

	Various starting checks
	Returns -1 if invalid

	int error_init_check(int fd, int argc, char **argv);
*/
int	error_init_check(int fd, int argc, char **argv);

/*
	---Map Validator----

	Checks if the map is valid
	Returns -1 if invalid

	int map_check(char *line);
*/
int		map_check(char *line);

/*
	---Get Line----

	Reads a line from a file descriptor
	Returns the line, NULL for error

	char *get_line(int fd);
*/
char	*get_line(int fd);

#endif