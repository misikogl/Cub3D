/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_loopstart.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenses <hsenses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:10:08 by misikogl          #+#    #+#             */
/*   Updated: 2023/09/05 23:00:18 by hsenses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	dabs(double n)
{
	if (n < 0)
		return (n *= -1);
	else
		return (n);
}

static t_raycast	*setsidedist(t_raycast *ray)
{
	if (ray->raydir.x < 0)
	{
		ray->step.x = -1;
		ray->sidedist.x = (ray->pos.x - ray->map.x) * ray->deltadist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->sidedist.x = (ray->map.x + 1.0 - ray->pos.x) * ray->deltadist.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->step.y = -1;
		ray->sidedist.y = (ray->pos.y - ray->map.y) * ray->deltadist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->sidedist.y = (ray->map.y + 1.0 - ray->pos.y) * ray->deltadist.y;
	}
	return (ray);
}

t_raycast	raycastloopstart(t_raycast *ray, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)SCREEN_WIDTH - 1;
	ray->raydir.x = ray->dir.x + ray->plane.x * camera_x;
	ray->raydir.y = ray->dir.y + ray->plane.y * camera_x;
	ray->map.x = (int)ray->pos.x;
	ray->map.y = (int)ray->pos.y;
	ray->deltadist.x = dabs(1 / ray->raydir.x);
	ray->deltadist.y = dabs(1 / ray->raydir.y);
	ray = setsidedist(ray);
	ray->hit = 0;
	return (*ray);
}
