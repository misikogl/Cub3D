/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_xpm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <misikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:21:45 by misikogl          #+#    #+#             */
/*   Updated: 2023/09/06 04:59:19 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

static char	*pass_empty(char *line)
{
	while (*line == ' ')
		line++;
	return (line);
}

static int	load(int i, t_cub3d *game, char *line)
{
	int			size;
	char		*sprite;
	t_data		*tmp;

	size = 64;
	game->texture.xpm[i] = malloc(sizeof(t_data));
	tmp = game->texture.xpm[i];
	line++;
	line++;
	line = pass_empty(line);
	sprite = ft_strndup (&line[0], ft_strlen(&line[0]) - 1);
	if (open(sprite, O_RDONLY) < 0)
		return (0);
	tmp->img = mlx_xpm_file_to_image(game->mlx, sprite, &size, &size);
	tmp->addr = mlx_get_data_addr(tmp->img,
			&(tmp->bits_per_pixel), &(tmp->line_length), &(tmp->endian));
	if (!(tmp->img) || !(tmp->addr))
		return (0);
	if (sprite)
		free(sprite);
	return (1);
}

//0xRRGGBB
static int	getcolor(t_cub3d *game, char *line)
{
	char	**rgb;
	int		color;

	rgb = 0;
	rgb = ft_split(line, ',');
	if (!rgb || !rgb[0] || !rgb[1] || !rgb[2] || ft_atoi(rgb[0]) > 255 \
		|| ft_atoi(rgb[1]) > 255 || ft_atoi(rgb[2]) > 255 \
		|| ft_atoi(rgb[0]) < 0 || ft_atoi(rgb[1]) < 0 || ft_atoi(rgb[2]) < 0)
		return (printf("Wrong color format\n"));
	if (ft_atoi(rgb[0]) == 0 && ft_atoi(rgb[2]) == 0 && ft_atoi(rgb[1]) == 0)
		color = 1;
	else
		color = (ft_atoi(&rgb[0][2]) << 16 | ft_atoi(rgb[1]) << 8 | \
			ft_atoi(rgb[2]));
	if (!ft_strncmp(line, "F ", 2))
		game->texture.bot = color;
	else
		game->texture.top = color;
	color = 0;
	while (rgb[color])
		free(rgb[color++]);
	free(rgb);
	return (0);
}

static int	import_xpm2(t_cub3d *game, char *line)
{
	if (!ft_strncmp (line, "NO ", 3))
	{
		if (!load(0, game, line))
			return (printf("File Not Found :%s\n", &line[3]), 1);
	}
	else if (!ft_strncmp (line, "SO ", 3))
	{
		if (!load(1, game, line))
			return (printf("File Not Found :%s\n", &line[3]), 1);
	}
	else if (!ft_strncmp (line, "WE ", 3))
	{
		if (!load(2, game, line))
			return (printf("File Not Found :%s\n", &line[3]), 1);
	}
	else if (!ft_strncmp(line, "EA ", 3))
	{
		if (!load(3, game, line))
			return (printf("File Not Found :%s\n", &line[3]), 1);
	}
	else if (!ft_strncmp (line, "F ", 2) || !ft_strncmp (line, "C ", 2))
		return (getcolor(game, line));
	else
		return (1);
	return (0);
}

int	import_xpm(t_cub3d *game, char *line)
{
	line = pass_empty(line);
	if (!ft_strncmp (line, "\n", 1))
		return (0);
	if (import_xpm2(game, line) == 1)
		return (1);
	return (0);
}
