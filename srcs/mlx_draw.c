/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <gmattei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:57:23 by gmattei           #+#    #+#             */
/*   Updated: 2023/11/07 16:32:36 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	my_mlx_pixel_put(t_mlx *data, int x, int y, int color)
{
	char	*pixel;

	pixel = data->img.addr + (y * data->img.line_len + x * (data->img.bpp / 8));
	*(int *)pixel = color;
}

void	window_labels(t_mlx *data)
{
	(void)data;
}

/* void	draw_floor_ceiling(t_mlx *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(data, x, y, data->ceiling_color);
			x++;
		}
		x = 0;
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		while (x < WIN_WIDTH)
		{
			my_mlx_pixel_put(data, x, y, data->floor_color);
			x++;
		}
		x = 0;
		y++;
	}
} */

void	draw(t_mlx *data)
{
	ft_raycasting(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	window_labels(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, \
	data->img.mlx_img, 0, 0);
}
