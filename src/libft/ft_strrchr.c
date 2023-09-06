/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhammed <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:46:29 by misikogl          #+#    #+#             */
/*   Updated: 2022/03/31 23:24:29 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*rtv;
	int		i;

	rtv = (char *)s;
	i = ft_strlen(rtv);
	while (i >= 0)
	{
		if (rtv[i] == (char)c)
			return (&rtv[i]);
		i--;
	}
	return (NULL);
}
/*
int main(void)
{
	char a[] = "ahmetmet";
	char c = 'm';
	char *rtv;

	rtv = ft_strrchr(a, c);
	
	printf("%s\n", rtv);
}
*/
