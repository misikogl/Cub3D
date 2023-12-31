/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hsenses <hsenses@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:02:47 by misikogl          #+#    #+#             */
/*   Updated: 2023/09/05 22:59:51 by hsenses          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (y < 0 || y > SCREEN_HEIGHT)
		return ;
	if (x < 0 || x > SCREEN_WIDTH)
		return ;
	if (!data->addr)
		return ;
	dst = \
	data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

size_t	get_texture_color(t_data *texture, int pixel_x, int pixel_y)
{
	return (*(size_t *)((texture->addr + (pixel_y * texture->line_length) \
		+ (pixel_x * texture->bits_per_pixel / 8))));
}
