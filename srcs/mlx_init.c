/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <gmattei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:49:08 by gmattei           #+#    #+#             */
/*   Updated: 2023/10/11 17:00:56 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	destroy_mlx(t_mlx *data)
{
	mlx_loop_end(data->mlx_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data);
	exit(0);
	return (-1);
}

int	mouse_handler(int keycode, t_mlx *data)
{
	(void)keycode;
	(void)data;
	return (0);
}

int	key_handler(int keycode, t_mlx *data)
{
	if (keycode == XK_Escape || keycode == XK_q)
		return (destroy_mlx(data));
	else
		printf("keycode: %d\n", keycode);
	return (0);
}

void	hooks_init(t_mlx *data)
{
	mlx_do_key_autorepeaton(data->mlx_ptr);
	mlx_hook(data->win_ptr, 2, 1l << 0, &key_handler, data);
	mlx_mouse_hook(data->win_ptr, &mouse_handler, data);
	mlx_hook(data->win_ptr, 17, 1L << 17, &destroy_mlx, data);
	mlx_loop(data->mlx_ptr);
}

void	map_creation(t_mlx *data)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = open("maps/map.cub", O_RDONLY);
	data->map = (char **)malloc(sizeof(char *) * 100);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		data->map[i] = ft_strdup(line);
		free(line);
		i++;
	}
	data->map[i] = NULL;
	close(fd);
}

int	init(t_mlx *data)
{
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "Cub3D");
	data->img.mlx_img = mlx_new_image(data->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.mlx_img, &data->img.bpp,
			&data->img.line_len, &data->img.endian);
	if (!data->mlx_ptr || !data->win_ptr || !data->img.mlx_img)
		return (err("An error has occured", "Please try again"));
	data->floor_color = 0x0f0ff0;
	data->ceiling_color = 0xf0ff0f;
	map_creation(data);
	for(int i = 0; data->map[i]; i++)
		printf("%s", data->map[i]);
	draw(data);
	hooks_init(data);
	return (0);
}
