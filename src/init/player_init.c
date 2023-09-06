/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <misikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:35:29 by misikogl          #+#    #+#             */
/*   Updated: 2023/09/05 23:35:21 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	player_plane(t_cub3d *game, char c)
{
	if (c == 'N')
	{
		game->player->plane.x = FOV;
		game->player->plane.y = 0;
	}
	else if (c == 'S')
	{
		game->player->plane.x = -FOV;
		game->player->plane.y = 0;
	}
	else if (c == 'W')
	{
		game->player->plane.x = 0;
		game->player->plane.y = -FOV;
	}
	else if (c == 'E')
	{
		game->player->plane.x = 0;
		game->player->plane.y = FOV;
	}
}

void	player_dir(t_cub3d *game, char c)
{
	if (c == 'N')
	{
		game->player->dir.x = 0;
		game->player->dir.y = -1;
	}
	else if (c == 'S')
	{
		game->player->dir.x = 0;
		game->player->dir.y = 1;
	}
	else if (c == 'W')
	{
		game->player->dir.x = -1;
		game->player->dir.y = 0;
	}
	else if (c == 'E')
	{
		game->player->dir.x = 1;
		game->player->dir.y = 0;
	}
	player_plane(game, c);
}

int	initialize_player(t_cub3d *game)
{
	int	i;
	int	j;

	i = -1;
	game->player = malloc(sizeof(t_character));
	while (game->map->map[++i])
	{
		j = -1;
		while (game->map->map[i][++j])
		{
			if (ft_strchr ("NSEW", game->map->map[i][j]))
			{
				game->player->pos.x = (double)j + 0.5;
				game->player->pos.y = (double)i + 0.5;
				player_dir(game, game->map->map[i][j]);
				return (1);
			}
		}
	}
	return (0);
}
