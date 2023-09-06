/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 14:24:48 by misikogl          #+#    #+#             */
/*   Updated: 2022/03/31 23:46:06 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*j;
	unsigned char	*k;

	if (dst == src)
	{
		return (0);
	}
	i = 0;
	j = (unsigned char *)dst;
	k = (unsigned char *)src;
	while (i < n)
	{
		j[i] = k[i];
		i++;
	}
	return (j);
}
/*
int main()
{
	char s1[] = "ahmet";
	char s2[] = "isau";
	printf("%s",ft_memcpy(s1,s2,3));
}
*/
