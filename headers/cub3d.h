/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <gmattei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:57:21 by gmattei           #+#    #+#             */
/*   Updated: 2023/10/11 16:56:13 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

/*
	------------LIBRARIES------------
*/

# include "../ctm/ctm_libs/ctm_libs.h"
# include "../minilibx-linux/mlx.h"
# include <math.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <fcntl.h>

/*
	------------DEFINES------------
*/

# define WIN_WIDTH 1600 
# define WIN_HEIGHT 900

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
	---Image---
	void *mlx_img ----> mlx image
	char *addr ----> image address
	int bpp ----> bits per pixel
	int endian ----> endian
	int line_len ----> line length
*/
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		endian;
	int		line_len;
}	t_img;

/*
	---Mlx---
	void *mlx ----> mlx pointer
	void *win ----> mlx window
	t_img *img ----> mlx image
*/
typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		floor_color;
	int		ceiling_color;
	char	**map;
	t_img	img;
}	t_mlx;

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
	Returns -1 if invalid, 0 otherwise

	int error_init_check(int fd, int argc, char **argv);
*/
int		error_init_check(int fd, int argc, char **argv);

/*
	---Display Destroyer---

	Free mlx pointers and exit
	Returns -1

	int destroy_mlx(t_mlx *data);
*/
int		destroy_mlx(t_mlx *data);

/*
	---Mouse Handler---

	Handles mouse events
	Returns 0

	int mouse_handler(int keycode, t_mlx *data);
*/
int		mouse_handler(int keycode, t_mlx *data);

/*
	---Key Handler---

	Handles keyboard events
	Returns 0

	int key_handler(int keycode, t_mlx *data);
*/
int		key_handler(int keycode, t_mlx *data);

/*
	---Hooks Initialization---

	Initializes hooks

	void hooks_init(t_mlx *data);
*/
void	hooks_init(t_mlx *data);

/*
	---Mlx Initialization---

	Initializes mlx
	Returns -1 if error, 0 otherwise

	int ft_init(t_mlx *data);
*/
int		init(t_mlx *data);

/*
	---Pixel Drawer---

	Puts a pixel on the screen

	void my_mlx_pixel_put(t_mlx *data, int x, int y, int color);
*/
void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color);

/*
	---Window Labels---

	Displays window labels

	void ft_draw(t_mlx *data);
*/
void	window_labels(t_mlx *data);

/*
	---Floor & Ceiling Drawer---

	Draws floor and ceiling

	void draw_floor_ceiling(t_mlx *data);
*/
void	draw_floor_ceiling(t_mlx *data);

/*
	---Draw---

	Draws everything

	void draw(t_mlx *data);
*/
void	draw(t_mlx *data);

#endif