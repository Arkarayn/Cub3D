/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <gmattei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:37:01 by  gcavanna         #+#    #+#             */
/*   Updated: 2023/11/07 15:55:59 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_ray	ft_init_ray(float camera_x, t_player *player)
{
	t_ray	ray;

	ray.dir_x = player->dir_x + player->plane_x * camera_x;
	ray.dir_y = player->dir_y + player->plane_y * camera_x;
	ray.map_x = (int)player->pos_x;
	ray.map_y = (int)player->pos_y;
	ray.delta_dist_x = fabsf(1 / ray.dir_x);
	ray.delta_dist_y = fabsf(1 / ray.dir_y);
	ray.hit = 0;
	return (ray);
}

t_ray	ft_init_side_distance(t_ray ray, t_player *player)
{
	t_ray	side_dist;

	if (ray.dir_x < 0)
	{
		side_dist.step_x = -1;
		side_dist.dist_x = (player->pos_x - ray.map_x) * ray.delta_dist_x;
	}
	else
	{
		side_dist.step_x = 1;
		side_dist.dist_x = (ray.map_x + 1.0 - player->pos_x) * ray.delta_dist_x;
	}
	if (ray.dir_y < 0)
	{
		side_dist.step_y = -1;
		side_dist.dist_y = (player->pos_y - ray.map_y) * ray.delta_dist_y;
	}
	else
	{
		side_dist.step_y = 1;
		side_dist.dist_y = (ray.map_y + 1.0 - player->pos_y) * ray.delta_dist_y;
	}
	return (side_dist);
}

int	ft_wall_collision_detection(t_mappo *map, t_ray ray)
{
	while (ray.hit == 0)
	{
		if (ray.dist_x < ray.dist_y)
		{
			ray.dist_x += ray.delta_dist_x;
			ray.map_x += ray.step_x;
			ray.side = 0;
		}
		else
		{
			ray.dist_y += ray.delta_dist_y;
			ray.map_y += ray.step_y;
			ray.side = 1;
		}
		if (map->matrix[ray.map_x][ray.map_y] == '1')
			ray.hit = 1;
	}
	return (ray.side);
}

void	ft_raycasting(t_game *game)
{
	int		x;
	float	camera_x;
	t_ray	ray;
	t_ray	side_dist;

	x = 0;
	while (x < game->win_width)
	{
		camera_x = 2 * x / (float)game->win_width - 1;
		ray = ft_init_ray(camera_x, &game->player);
		side_dist = ft_init_side_distance(ray, &game->player);
		ray.side = ft_wall_collision_detection(&game->map, ray);
		if (ray.side == 0)
			ray.perp_wall_dist = (ray.map_x - game->player.pos_x + \
			(1 - ray.step_x) / 2) / ray.dir_x;
		else
			ray.perp_wall_dist = (ray.map_y - game->player.pos_y + \
			(1 - ray.step_y) / 2) / ray.dir_y;
		game->z_buffer[x] = ray.perp_wall_dist;
		ft_draw_wall(&ray, game);
		x++;
	}
}
