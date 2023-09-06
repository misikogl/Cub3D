/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenses <hsenses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:07:21 by misikogl          #+#    #+#             */
/*   Updated: 2023/09/05 23:00:22 by hsenses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_raycast	setwall(t_cub3d *game, t_raycast *ray)
{
	if (ray->side == 0)
	{
		ray->draw.wallx = \
			game->player->pos.y + ray->draw.perpwalldist * ray->raydir.y;
		if (ray->map.x < game->player->pos.x)
			ray->draw.wall = 3;
		else
			ray->draw.wall = 2;
	}
	else
	{
		ray->draw.wallx = \
			game->player->pos.x + ray->draw.perpwalldist * ray->raydir.x;
		if (ray->map.y < game->player->pos.y)
			ray->draw.wall = 1;
		else
			ray->draw.wall = 0;
	}
	return (*ray);
}

double	getperpwalldist(t_raycast *ray)
{
	if (ray->side == 0)
		return (ray->sidedist.x - ray->deltadist.x);
	else
		return (ray->sidedist.y - ray->deltadist.y);
}

t_raycast	getwalllength(t_cub3d *game, t_raycast *ray)
{
	ray->draw.perpwalldist = getperpwalldist(ray);
	ray->draw.lineheight = (int)(SCREEN_HEIGHT / ray->draw.perpwalldist);
	ray->draw.drawwall.x = -ray->draw.lineheight / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw.drawwall.x < 0)
		ray->draw.drawwall.x = 0;
	ray->draw.drawwall.y = ray->draw.lineheight / 2 + SCREEN_HEIGHT / 2;
	if (ray->draw.drawwall.y > SCREEN_HEIGHT)
		ray->draw.drawwall.y = SCREEN_HEIGHT;
	*ray = setwall(game, ray);
	return (*ray);
}
