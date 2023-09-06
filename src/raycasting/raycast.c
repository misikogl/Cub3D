/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenses <hsenses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 15:06:36 by misikogl          #+#    #+#             */
/*   Updated: 2023/09/05 23:00:24 by hsenses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_raycast	init_raycast(t_cub3d *game)
{
	t_raycast	ray;

	ray.pos.x = game->player->pos.x;
	ray.pos.y = game->player->pos.y;
	ray.plane.x = game->player->plane.x;
	ray.plane.y = game->player->plane.y;
	ray.dir.x = game->player->dir.x;
	ray.dir.y = game->player->dir.y;
	return (ray);
}

t_raycast	summonray(t_cub3d *game, t_raycast *ray)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist.x < ray->sidedist.y)
		{
			ray->sidedist.x += ray->deltadist.x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist.y += ray->deltadist.y;
			ray->map.y += ray->step.y;
			ray->side = 1;
		}
		if (!game->map->map[ray->map.y])
			break ;
		else if (game->map->map[ray->map.y][ray->map.x] == '1')
			ray->hit = 1;
	}
	return (*ray);
}

void	raycast(t_cub3d *game)
{
	int				x;
	t_raycast		ray;

	x = -1;
	ray = init_raycast(game);
	while (++x < SCREEN_WIDTH)
	{
		ray = raycastloopstart(&ray, x);
		ray = summonray(game, &ray);
		ray = getwalllength(game, &ray);
		drawvertical(x, game, &ray);
	}
}
