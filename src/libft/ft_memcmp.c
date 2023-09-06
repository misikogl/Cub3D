/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 17:36:06 by misikogl          #+#    #+#             */
/*   Updated: 2022/03/31 23:47:13 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s11;
	unsigned char	*s22;
	size_t			i;

	i = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	if (!s1 && !s2)
		return (0);
	while (i < n)
	{
		if (s11[i] != s22[i])
		{
			return (s11[i] - s22[i]);
		}
		i++;
	}
	return (0);
}
/*
int main()
{
	char a[] = "muhammed";
	char b[] = "muhamr";
	printf("%d\n", ft_memcmp(a, b, 4));
}
*/
