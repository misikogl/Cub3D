/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <misikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 07:52:16 by misikogl          #+#    #+#             */
/*   Updated: 2023/09/06 02:43:08 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	move(t_cub3d *game)
{
	if (game->key.w)
		setpos(game, game->player->dir.x, game->player->dir.y, '+');
	if (game->key.s)
		setpos(game, game->player->dir.x, game->player->dir.y, '-');
	if (game->key.d)
		setpos(game, game->player->plane.x, game->player->plane.y, '+');
	if (game->key.a)
		setpos(game, game->player->plane.x, game->player->plane.y, '-');
	if (game->key.keyleft || game->key.keyright)
		turn(game);
	return (retmove(game));
}

int	move_loop(t_cub3d *game)
{
	if (move (game))
		getscreen(game);
	return (0);
}

void	getscreen(t_cub3d *game)
{
	raycast (game);
	mlx_put_image_to_window (game->mlx, game->win, game->img->img, 0, 0);
}
