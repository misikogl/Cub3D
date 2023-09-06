/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <misikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 16:51:34 by misikogl          #+#    #+#             */
/*   Updated: 2023/09/06 04:10:18 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_keys(t_cub3d *game)
{
	game->key.a = 0;
	game->key.s = 0;
	game->key.d = 0;
	game->key.w = 0;
	game->key.keyleft = 0;
	game->key.keyright = 0;
	return (0);
}

int	initialize_image(t_cub3d *game)
{
	game->img = malloc(sizeof(t_data));
	game->img->img = mlx_new_image(game->mlx, 1920, 1080);
	game->img->addr = \
	mlx_get_data_addr(game->img->img, &game->img->bits_per_pixel,
			&game->img->line_length, &game->img->endian);
	if (!(game->img->img) || !(game->img->addr))
		return (0);
	else
		return (1);
}

int	initialize(t_cub3d *game_init, char **argv)
{
	(game_init)->mlx = mlx_init();
	if (!((game_init)->mlx))
		return (0);
	if (!create_map (game_init, argv[1]))
		return (0);
	game_init->win = mlx_new_window (game_init->mlx, SCREEN_WIDTH, \
		SCREEN_HEIGHT, "cub3d");
	if (!((game_init)->win))
		return (0);
	init_keys (game_init);
	if (!initialize_player (game_init))
		return (0);
	if (!initialize_image (game_init))
		return (0);
	mlx_hook (game_init->win, 3, 1L << 1, key_up, game_init);
	mlx_hook (game_init->win, 17, 1L << 0, finish, game_init);
	mlx_hook (game_init->win, 2, 1L << 0, key_down, game_init);
	mlx_loop_hook (game_init->mlx, move_loop, game_init);
	mlx_put_image_to_window (game_init->mlx, game_init->win, \
		game_init->img->img, 0, 0);
	getscreen (game_init);
	return (1);
}
