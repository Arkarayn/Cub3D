/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_ray_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmattei <gmattei@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:58:00 by  gcavanna         #+#    #+#             */
/*   Updated: 2023/11/07 16:39:10 by gmattei          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_wall_height(t_ray *ray, int win_height)
{
	int	wall_height;

	wall_height = (int)(win_height / ray->perp_wall_dist);
	return (wall_height);
}

void	ft_texture_coord(t_ray *ray, t_game *game)
{
	int	tex_x;
	int	tex_y;

	if (ray->side == 0)
		ray->wall_x = game->player.pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = game->player.pos_x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	tex_x = (int)(ray->wall_x * (double)(game->texture.width));
	if (ray->side == 0 && ray->dir_x > 0)
		tex_x = game->texture.width - tex_x - 1;
	if (ray->side == 1 && ray->dir_y < 0)
		tex_x = game->texture.width - tex_x - 1;
	ray->step = 1.0 * game->texture.height / \
	ft_wall_height(ray, game->win_height);
	ray->tex_pos = (ray->draw_start - game->win_height / 2 + \
	ft_wall_height(ray, game->win_height) / 2) * ray->step;
	tex_y = (int)ray->tex_pos & (game->texture.height - 1);
	while (ray->draw_start < ray->draw_end)
	{
		ray->color = game->texture.data[game->texture.width * tex_y + tex_x];
		ft_render(ray, game, ray->draw_start);
		ray->draw_start++;
		ray->tex_pos += ray->step;
		tex_y = (int)ray->tex_pos & (game->texture.height - 1);
	}
}

void	ft_render(t_ray *ray, t_game *game, int y)
{
	char	*dst;

	dst = game->img.addr + (y * game->img.line_len + ray->x * \
	(game->img.bpp / 8));
	*(unsigned int*)dst = ray->color;
}

void	ft_draw_wall(t_ray *ray, t_game *game)
{
	int	wall_height;

	wall_height = ft_wall_height(ray, game->win_height);
	ray->draw_start = -wall_height / 2 + game->win_height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = wall_height / 2 + game->win_height / 2;
	if (ray->draw_end >= game->win_height)
		ray->draw_end = game->win_height - 1;
	ft_texture_coord(ray, game);
}