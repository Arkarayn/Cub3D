/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <gmattei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 17:57:21 by gmattei           #+#    #+#             */
/*   Updated: 2023/11/07 16:41:05 by gmattei          ###   ########.fr       */
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
# include <stdbool.h>

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

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		floor_color;
	int		ceiling_color;
	char	**map;
	t_img	img;
}	t_mlx;

typedef struct s_map
{
	int		cardinal[4];
	char	*tex_path[4];
	int		colors[2][3];

	int		posx;
	int		posy;
	int		x;
	int		y;
	int		**maprix;
	bool	oriented;
	bool	n;
	bool	s;
	bool	e;
	bool	w;
}	t_map;

typedef struct s_cube
{
	t_map	*map;
	char	*mapath;

	t_mlx	*mlx;
	int		fd;

}	t_cube;

typedef struct s_texture
{
	int		*data;
	int		width;
	int		height;
}				t_texture;

typedef struct s_ray
{
	float		dir_x;
	float		dir_y;
	int			map_x;
	int			map_y;
	float		delta_dist_x;
	float		delta_dist_y;
	float		dist_x;
	float		dist_y;
	float		perp_wall_dist;
	float		wall_x;
	int			x;
	int			color;
	float		step;
	float		tex_pos;
	int			draw_end;
	int			draw_start;
	t_texture	texture;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
}				t_ray;

typedef struct s_player
{
	float		pos_x;
	float		pos_y;
	float		dir_x;
	float		dir_y;
	float		plane_x;
	float		plane_y;
	float		move_speed;
	float		rot_speed;
	float		ray_dir_x;
	float		ray_dir_y;
}				t_player;

typedef struct s_mappo
{
	char		**matrix;
	int			rows;
	int			cols;
}				t_mappo;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_mappo		map;
	t_player	player;
	int			win_width;
	int			win_height;
	int			*z_buffer;
	t_texture	texture;
}				t_game;

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

int		ft_wall_height(t_ray *ray, int win_height);
void	ft_texture_coord(t_ray *ray, t_game *game);
void	ft_render(t_ray *ray, t_game *game, int y);
void	ft_draw_wall(t_ray *ray, t_game *game);
void	ft_raycasting(t_game *game);
int		ft_wall_collision_detection(t_mappo *map, t_ray ray);
t_ray	ft_init_side_distance(t_ray ray, t_player *player);
void	ft_get_player_pos(t_game *game);
void	ft_get_player_pov(t_player *player, double camera_x);
void	set_plr_pov(t_player *player, char dir);

int		check(int ac);
int		innit(char **av, t_map *map, t_cube *cube);
void	map_innit(t_cube *cube, t_map *map);
void	destroy_cube(t_cube *cube);
void	add_element(char **tok, int *id, int type, t_cube *cube);
void	add_path(char **tok, int i, int type, t_cube *cube);
int		open_path(t_cube *cube);

//	Tools
int		open_path(t_cube *cube);
int		puterr(int n);
void	get_next_close(char *line, t_cube *cube);

//	Parsing
void	parser(t_cube *cube);
int		check_next_line(char *line, int *id, t_cube *cube);
int		check_next_map(int start, char *line, t_cube *cube);
int		mapalloc(char *line, t_cube *cube);
int		map_sizecheck(char *line, int *x, int *y, t_cube *cube);
int		line_walls(int i, char *line, t_cube *cube);
int		add_orient(char c, t_cube *cube);
int		linecmp(int i, char *prev_line, char *line);
void	add_map(int start, t_cube *cube);
void	add_element(char **tok, int *id, int type, t_cube *cube);
void	add_path(char **tok, int i, int type, t_cube *cube);
void	add_color(int type, char **tok, t_cube *cube);
void	add_rgb(int type, char **rgb, t_cube *cube);
int		is_map(char *prev_line, char *line, t_cube *cube);
int		is_valid(char c);
int		is_orient(char **tok);
int		is_mapstart(char *line, char **tok, t_cube *cube);
void	free_next_line(char **tok);

void	gotomap(char **line, int start, t_cube *cube);
void	fill_map(char *line, t_cube *cube);
int		coordinate(int i, char *line);

#endif