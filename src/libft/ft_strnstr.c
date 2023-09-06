/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhammed <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:19:07 by misikogl          #+#    #+#             */
/*   Updated: 2022/03/31 23:25:00 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == 0)
	{
		return ((char *)big);
	}
	i = 0;
	while (big[i] != 0 && i < len)
	{
		j = 0;
		while (big[i + j] == little[j] && little[j] != 0 && j + i < len)
		{
			j++;
		}
		if (j == ft_strlen (little))
		{
			return ((char *)&big[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
/*
int main ()
{
	 char s1[] = "muhammedirem";
	 char s2[] = "irem";
	char *rtn;
	       rtn = ft_strnstr(s1, s2, 4);
	printf ("%s\n", rtn);
}
*/
