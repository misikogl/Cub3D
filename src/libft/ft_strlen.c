/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:21:30 by misikogl          #+#    #+#             */
/*   Updated: 2023/08/16 20:06:13 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	l;

	l = 0;
	while (s [l] != '\0')
	{
		l++;
	}
	return (l);
}
/*
int main()
{
	char s1[] = "ada";
	printf("%d\n",ft_strlen(s1));
}
*/
