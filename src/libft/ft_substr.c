/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhammed <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:57:17 by misikogl          #+#    #+#             */
/*   Updated: 2022/03/31 23:19:20 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned int	i;
	size_t			j;

	j = 0;
	i = start;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return ((char *)ft_calloc (1, 1));
	if (s == NULL)
		return (NULL);
	if (len + start > ft_strlen(s))
		len = ft_strlen(s) - start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	while (s[i] != 0 && j < len)
	{
		ptr[j] = s[i];
		i++;
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}
/*
int main()
{
	char	*a = "alicim";
	printf("%s",ft_substr(a,3,5));
}
*/
