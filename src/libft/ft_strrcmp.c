/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <misikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 20:04:11 by misikogl          #+#    #+#             */
/*   Updated: 2023/09/05 18:56:47 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strrcmp(char *src, char *dest)
{
	int	srci;
	int	desti;

	srci = ft_strlen(src) - ft_strlen(dest);
	desti = 0;
	if (srci <= 0)
		return (0);
	while (src[srci] && dest[desti])
	{
		if (src[srci] != dest[desti])
			break ;
		srci++;
		desti++;
	}
	return (((unsigned char *)src)[srci] - ((unsigned char *)dest)[desti]);
}
