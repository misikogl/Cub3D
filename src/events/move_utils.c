/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <misikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:14:31 by misikogl          #+#    #+#             */
/*   Updated: 2023/09/05 23:49:34 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static double	get_distance(double newpos)
{
	return (newpos * WALKING_SPEED);
}

void	setpos(t_cub3d *game, double newposx, double newposy, char mod)
{
	double	*posx;
	double	*posy;

	posx = &(game->player->pos.x);
	posy = &(game->player->pos.y);
	if (mod == '-')
	{
		if (!(game->map->map[(int)(*posy - get_distance(newposy))]))
			return ;
		if (!(ft_strchr("1", game->map->map[(int)(*posy \
			- get_distance(newposy))][(int)(*posx)])))
			game->player->pos.y -= newposy * (WALKING_SPEED);
		if (!(ft_strchr("1", game->map->map[(int)(*posy)]
				[(int)(*posx - get_distance(newposx))])))
			game->player->pos.x -= newposx * (WALKING_SPEED);
		return ;
	}
	if (!(game->map->map[(int)(*posy + get_distance(newposy))]))
		return ;
	if (!(ft_strchr("1", game->map->map[(int)(*posy \
		+ get_distance(newposy))][(int)(*posx)])))
		game->player->pos.y += newposy * (WALKING_SPEED);
	if (!(ft_strchr("1", game->map->map[(int)(*posy)]
			[(int)(*posx + get_distance(newposx))])))
		game->player->pos.x += newposx * (WALKING_SPEED);
}

void	turn(t_cub3d *game)
{
	double	olddirx;
	double	oldplanex;

	olddirx = game->player->dir.x;
	oldplanex = game->player->plane.x;
	if (game->key.keyleft)
	{
		game->player->dir.x = game->player->dir.x * cos(-TURNSPEED)
			- game->player->dir.y * sin(-TURNSPEED);
		game->player->dir.y = olddirx * sin(-TURNSPEED)
			+ game->player->dir.y * cos(-TURNSPEED);
		game->player->plane.x = game->player->plane.x * cos(-TURNSPEED)
			- game->player->plane.y * sin(-TURNSPEED);
		game->player->plane.y = oldplanex * sin(-TURNSPEED)
			+ game->player->plane.y * cos(-TURNSPEED);
		return ;
	}
	game->player->dir.x = game->player->dir.x * cos(TURNSPEED)
		- game->player->dir.y * sin(TURNSPEED);
	game->player->dir.y = olddirx * sin(TURNSPEED)
		+ game->player->dir.y * cos(TURNSPEED);
	game->player->plane.x = game->player->plane.x * cos(TURNSPEED)
		- game->player->plane.y * sin(TURNSPEED);
	game->player->plane.y = oldplanex * sin(TURNSPEED)
		+ game->player->plane.y * cos(TURNSPEED);
}

int	retmove(t_cub3d *game)
{
	if (game->key.w || game->key.s || game->key.a || game->key.d || 
		game->key.keyleft || game->key.keyright)
		return (1);
	else
		return (0);
}
