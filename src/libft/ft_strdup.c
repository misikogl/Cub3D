/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhammed <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:26:57 by misikogl          #+#    #+#             */
/*   Updated: 2022/03/31 23:31:52 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*p;
	char	*p2;
	int		i;
	int		len;

	len = ft_strlen(s) + 1;
	p = (char *)malloc(len);
	if (!p)
		return (NULL);
	p2 = p;
	i = 0;
	while (s[i])
	{
		p2[i] = s[i];
		i++;
	}
	p2[i] = '\0';
	return (p2);
}
/*
int main()
{
	char	s1[] = {"enes"};
	printf("%s\n", ft_strdup(s1));
}
 */
