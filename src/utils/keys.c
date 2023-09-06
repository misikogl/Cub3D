/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <misikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:31:35 by misikogl          #+#    #+#             */
/*   Updated: 2023/09/06 03:34:57 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_down(int keycode, t_cub3d *game)
{
	if (keycode == 53)
		finish(game);
	else if (keycode == 13)
		game->key.w = 1;
	else if (keycode == 1)
		game->key.s = 1;
	else if (keycode == 0)
		game->key.a = 1;
	else if (keycode == 2)
		game->key.d = 1;
	else if (keycode == 123)
		game->key.keyleft = 1;
	else if (keycode == 124)
		game->key.keyright = 1;
	return (1);
}

int	key_up(int keycode, t_cub3d *game)
{
	if (keycode == 53)
		finish(game);
	else if (keycode == 13)
		game->key.w = 0;
	else if (keycode == 1)
		game->key.s = 0;
	else if (keycode == 0)
		game->key.a = 0;
	else if (keycode == 2)
		game->key.d = 0;
	else if (keycode == 123)
		game->key.keyleft = 0;
	else if (keycode == 124)
		game->key.keyright = 0;
	return (1);
}
