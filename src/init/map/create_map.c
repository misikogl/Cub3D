/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <misikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:03:47 by misikogl          #+#    #+#             */
/*   Updated: 2023/09/06 04:58:54 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	fill_mapspaces(char **map, int xlen, int i)
{
	int		j;
	char	*tmp;
	char	*temp;

	while (map[++i])
	{
		tmp = ft_calloc(xlen + 1, 1);
		j = -1;
		while (map[i][++j])
		{
			if (!ft_strchr("10NSEW ", map[i][j]))
				return (0);
			tmp[j] = map[i][j];
		}
		while (++j < xlen)
		{
			temp = tmp;
			tmp = ft_strjoin (tmp, " ");
			free(temp);
		}
		free (map[i]);
		map[i] = tmp;
	}
	return (1);
}

char	*get_map_text(int fd)
{
	char	*str;
	char	*check;
	char	*temp;

	check = 0;
	while (1)
	{
		if (check)
			free(check);
		check = get_next_line(fd);
		if (ft_strncmp(check, "\n", 1))
			break ;
	}
	str = 0;
	while (1)
	{
		temp = str;
		str = ft_strjoin(str, check);
		free(temp);
		free(check);
		check = get_next_line(fd);
		if (!check)
			break ;
	}
	return (str);
}

char	**get_map(t_cub3d *game, int fd)
{
	size_t		tmp;
	char		**map;
	char		*text;
	char		*check;

	text = get_map_text(fd);
	check = ft_strnstr(text, "\n\n", ft_strlen(text));
	if (check)
		return (0);
	map = ft_split(text, '\n');
	free(text);
	game->map->y = 0;
	game->map->x = 0;
	while (map[game->map->y])
	{
		tmp = ft_strlen(map[game->map->y]);
		if (game->map->x < tmp)
			game->map->x = tmp + 1;
		game->map->y++;
	}
	return (map);
}

int	loadsprites(int fd, t_cub3d *game)
{
	char	*line;
	int		ret;

	ret = 0;
	line = 0;
	while (1)
	{
		line = get_next_line(fd);
		ret++;
		if (import_xpm(game, line))
			return (0);
		free(line);
		if (game->texture.bot && game->texture.top && game->texture.xpm[1] && \
			game->texture.xpm[0] && game->texture.xpm[2] && \
			game->texture.xpm[3])
			break ;
	}
	return (ret);
}

int	create_map(t_cub3d *game, char *file)
{
	int	fd;

	game->map = malloc(sizeof(t_map));
	if (ft_strlen (file) < 5 || ft_strrcmp (file, ".cub") != 0)
		return (!printf("Wrong file format: correct file format is file.cub\n"));
	fd = open (file, O_RDONLY);
	if (fd < 0)
		return (!printf ("File Not Found :%s\n", file));
	if (!loadsprites (fd, game))
		return (!printf ("Wrong XPM format!\n"));
	game->map->map = get_map (game, fd);
	if (!game->map->map)
		return (!printf ("Wrong Map format!\n"));
	if (!fill_mapspaces(game->map->map, game->map->x, -1))
		return (!printf ("Unsupported character detected.\n"));
	if (!player_check (game->map->map))
		return (!printf ("Player not found or more than one player found.\n"));
	if (!map_check (game->map->map))
		return (!printf ("Map & Player must be covered by wall(s)\n"));
	close(fd);
	return (1);
}
