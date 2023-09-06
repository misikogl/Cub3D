/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <misikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 19:15:04 by misikogl          #+#    #+#             */
/*   Updated: 2023/09/06 04:59:31 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	player_check(char **map)
{
	int	i;
	int	j;
	int	player;

	i = -1;
	player = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NSEW", map[i][j]))
				player++;
		}
	}
	if (player != 1)
		return (0);
	return (1);
}

static int	horizontalcheck(char **map, int i, int j, int flag)
{
	while (map[++i])
	{
		flag = 0;
		j = -1;
		while (map[i][++j])
		{
			if (flag == 0 && map[i][j] == '1')
				flag ^= 1;
			if (flag == 0 && ft_strchr("NSEW0", map[i][j]))
				return (0);
			if (flag == 1 && map[i][j] == ' ')
			{
				if (map[i][j - 1] && ft_strchr("0NSEW", map[i][j - 1]))
					return (0);
				flag ^= 1;
			}
		}
	}
	return (1);
}

static int	verticalcheck(char **map, int i, int j, int flag)
{
	while (map[0][++j])
	{
		flag = 0;
		i = 0;
		while (map[i] && map[i][j])
		{
			if (flag == 0 && map[i][j] == '1')
				flag ^= 1;
			if (flag == 0 && ft_strchr ("NSEW0", map[i][j]))
				return (0);
			if (flag == 1 && map[i][j] == ' ')
			{
				if (map[i - 1] && map[i - 1][j]
						&& ft_strchr ("0NSEW", map[i - 1][j]))
					return (0);
				flag ^= 1;
			}
			if (!map[i + 1] && ft_strchr ("NSEW0", map[i][j]))
				return (0);
			i++;
		}
	}
	return (1);
}

int	map_check(char **map)
{
	if (!horizontalcheck (map, -1, -1, 0))
		return (0);
	if (!verticalcheck (map, -1, -1, 0))
		return (0);
	return (1);
}
