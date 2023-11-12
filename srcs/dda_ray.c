/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:37:01 by  gcavanna         #+#    #+#             */
/*   Updated: 2023/11/12 15:26:04 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
This file contains the implementation of the DDA (Digital Differential Analyzer)
algorithm used for raycasting in the game. The algorithm is used to detect collisions
between the player's view and the walls of the game map. The algorithm is divided into
several functions:

- ft_init_ray: initializes the ray with the player's position and direction, and calculates
the delta distance between the x and y directions of the ray.

- ft_init_side_distance: initializes the side distance of the ray, which is used to calculate
the distance between the player and the next wall in the x and y directions.

- ft_wall_collision_detection: detects if the ray has collided with a wall by checking the
game map matrix at the current position of the ray.

- ft_raycasting: performs the raycasting for each column of the game window, calculating the
distance between the player and the wall in the direction of the ray, and drawing the wall
on the screen.

The functions use several structs to store the necessary information for the raycasting,
including the player's position and direction, the ray's direction and distance, and the
distance between the player and the next wall in the x and y directions.
*/
// #include "cub3d.h"

// t_ray ft_init_ray(float camera_x, t_player *player) {
// 	t_ray ray;
// 	ray.dir_x = player->dir_x + player->plane_x * camera_x;
// 	ray.dir_y = player->dir_y + player->plane_y * camera_x;
// 	ray.map_x = (int)player->pos_x;
// 	ray.map_y = (int)player->pos_y;
// 	ray.delta_dist_x = fabsf(1 / ray.dir_x);
// 	ray.delta_dist_y = fabsf(1 / ray.dir_y);
// 	ray.hit = 0;
// 	return (ray);
// }

// t_ray ft_init_side_distance(t_ray ray, t_player *player) {
// 	t_ray side_dist;
// 	if (ray.dir_x < 0) {
// 		side_dist.step_x = -1;
// 		side_dist.dist_x = (player->pos_x - ray.map_x) * ray.delta_dist_x;
// 	} else {
// 		side_dist.step_x = 1;
// 		side_dist.dist_x = (ray.map_x + 1.0 - player->pos_x) * ray.delta_dist_x;
// 	}
// 	if (ray.dir_y < 0) {
// 		side_dist.step_y = -1;
// 		side_dist.dist_y = (player->pos_y - ray.map_y) * ray.delta_dist_y;
// 	} else {
// 		side_dist.step_y = 1;
// 		side_dist.dist_y = (ray.map_y + 1.0 - player->pos_y) * ray.delta_dist_y;
// 	}
// 	return (side_dist);
// }

// int ft_wall_collision_detection(t_mappo *map, t_ray ray) {
// 	while (ray.hit == 0) {
// 		if (ray.dist_x < ray.dist_y) {
// 			ray.dist_x += ray.delta_dist_x;
// 			ray.map_x += ray.step_x;
// 			ray.side = 0;
// 		} else {
// 			ray.dist_y += ray.delta_dist_y;
// 			ray.map_y += ray.step_y;
// 			ray.side = 1;
// 		}
// 		if (map->matrix[ray.map_x][ray.map_y] == '1')
// 			ray.hit = 1;
// 	}
// 	return (ray.side);
// }

// void ft_raycasting(t_game *game) {
// 	int x;
// 	float camera_x;
// 	t_ray ray;
// 	t_ray side_dist;
// 	x = 0;
// 	while (x < game->win_width) {
// 		camera_x = 2 * x / (float)game->win_width - 1;
// 		ray = ft_init_ray(camera_x, &game->player);
// 		side_dist = ft_init_side_distance(ray, &game->player);
// 		ray.side = ft_wall_collision_detection(&game->map, ray);
// 		if (ray.side == 0)
// 			ray.perp_wall_dist = (ray.map_x - game->player.pos_x + (1 - ray.step_x) / 2) / ray.dir_x;
// 		else
// 			ray.perp_wall_dist = (ray.map_y - game->player.pos_y + (1 - ray.step_y) / 2) / ray.dir_y;
// 		game->z_buffer[x] = ray.perp_wall_dist;
// 		ft_draw_wall(&ray, game);
// 		x++;
// 	}
// }

#include "cub3d.h"

t_ray	ft_init_ray(float camera_x, t_cube *cube)
{
    t_ray	ray;

    ray.dir_x = cube->map->dir_x + cube->map->plane_x * camera_x;
    ray.dir_y = cube->map->dir_y + cube->map->plane_y * camera_x;
    ray.map_x = (int)cube->map->pos_x;
    ray.map_y = (int)cube->map->pos_y;
    ray.delta_dist_x = fabsf(1 / ray.dir_x);
    ray.delta_dist_y = fabsf(1 / ray.dir_y);
    ray.hit = 0;
    return (ray);
}

t_ray	ft_init_side_distance(t_ray ray, t_cube *cube)
{
    t_ray	side_dist;

    if (ray.dir_x < 0)
    {
        side_dist.step_x = -1;
        side_dist.dist_x = (cube->map->pos_x - ray.map_x) * ray.delta_dist_x;
    }
    else
    {
        side_dist.step_x = 1;
        side_dist.dist_x = (ray.map_x + 1.0 - cube->map->pos_x) * ray.delta_dist_x;
    }
    if (ray.dir_y < 0)
    {
        side_dist.step_y = -1;
        side_dist.dist_y = (cube->map->pos_y - ray.map_y) * ray.delta_dist_y;
    }
    else
    {
        side_dist.step_y = 1;
        side_dist.dist_y = (ray.map_y + 1.0 - cube->map->pos_y) * ray.delta_dist_y;
    }
    return (side_dist);
}

int	ft_wall_collision_detection(t_map *map, t_ray ray)
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
        if (map->maprix[ray.map_x][ray.map_y] == 1)
            ray.hit = 1;
    }
    return (ray.side);
}

void	ft_raycasting(t_cube *cube)
{
    int		x;
    float	camera_x;
    t_ray	ray;
    t_ray	side_dist;

    x = 0;
    while (x < cube->win_width)
    {
        camera_x = 2 * x / (float)cube->win_width - 1;
        ray = ft_init_ray(camera_x, cube);
        side_dist = ft_init_side_distance(ray, cube);
        ray.side = ft_wall_collision_detection(cube->map, ray);
        if (ray.side == 0)
            ray.perp_wall_dist = (ray.map_x - cube->map->pos_x + \
            (1 - ray.step_x) / 2) / ray.dir_x;
        else
            ray.perp_wall_dist = (ray.map_y - cube->map->pos_y + \
            (1 - ray.step_y) / 2) / ray.dir_y;
        cube->z_buffer[x] = ray.perp_wall_dist;
        ft_draw_wall(&ray, cube);
        x++;
    }
}