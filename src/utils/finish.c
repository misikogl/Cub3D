/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <misikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 17:32:47 by misikogl          #+#    #+#             */
/*   Updated: 2023/09/06 03:33:17 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	finish(t_cub3d *game)
{
	exit (mlx_destroy_window(game->mlx, game->win));
	return (1);
}
