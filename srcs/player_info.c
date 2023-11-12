/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcavanna <gcavanna@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 08:44:09 by gcavanna          #+#    #+#             */
/*   Updated: 2023/11/12 15:29:07 by gcavanna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "cub3d.h"

// void	set_plr_pov(t_player *player, char dir)
// {
// 	player->dir_x = 0;
// 	player->dir_y = 0;
// 	player->plane_x = 0;
// 	player->plane_y = 0;
// 	if (dir == 'N')
// 	{
// 		player->dir_y = -1;
// 		player->plane_x = 0.66;
// 	}
// 	else if (dir == 'S')
// 	{
// 		player->dir_y = 1;
// 		player->plane_x = -0.66;
// 	}
// 	else if (dir == 'E')
// 	{
// 		player->dir_x = 1;
// 		player->plane_y = 0.66;
// 	}
// 	else if (dir == 'W')
// 	{
// 		player->dir_x = -1;
// 		player->plane_y = -0.66;
// 	}
// }

// void	ft_get_player_pov(t_player *player, double camera_x)
// {
// 	player->ray_dir_x = player->dir_x + player->plane_x * camera_x;
// 	player->ray_dir_y = player->dir_y + player->plane_y * camera_x;
// }

// void	ft_get_player_pos(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < game->map.rows)
// 	{
// 		j = 0;
// 		while (j < game->map.cols)
// 		{
// 			if (ft_strchr("NEWS", game->map.matrix[i][j]))
// 			{
// 				game->player.pos_x = i + 0.5;
// 				game->player.pos_y = j + 0.5;
// 				set_plr_pov(&game->player, game->map.matrix[i][j]);
// 				game->map.matrix[i][j] = '0';
// 				return ;
// 			}
// 			j++;
// 		}
// 		i++;
// 	}
// }

/**
 * Sets the player's point of view based on the given direction.
 * @param map - The map struct containing the player's position.
 * @param dir - The direction the player is facing (N, S, E, W).
 */
void set_plr_pov(t_map *map, char dir)
{
	map->posx = 0;
	map->posy = 0;
	if (dir == 'N')
	{
		map->posy = -1;
		map->posx = 0.66;
	}
	else if (dir == 'S')
	{
		map->posy = 1;
		map->posx = -0.66;
	}
	else if (dir == 'E')
	{
		map->posx = 1;
		map->posy = 0.66;
	}
	else if (dir == 'W')
	{
		map->posx = -1;
		map->posy = -0.66;
	}
}

/**
 * Gets the player's position from the map and sets the player's point of view.
 * @param cube - The cube struct containing the map and player information.
 */
void ft_get_player_pos(t_cube *cube)
{
	int i;
	int j;

	i = 0;
	while (i < cube->map->y)
	{
		j = 0;
		while (j < cube->map->x)
		{
			if (strchr("NEWS", cube->map->maprix[i][j]))
			{
				cube->map->posx = i + 0.5;
				cube->map->posy = j + 0.5;
				set_plr_pov(cube->map, cube->map->maprix[i][j]);
				cube->map->maprix[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}