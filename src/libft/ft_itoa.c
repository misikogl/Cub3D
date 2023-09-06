/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <42istanbul.com.tr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 22:07:32 by misikogl          #+#    #+#             */
/*   Updated: 2022/03/31 23:49:48 by misikogl         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		b;
	long	number;

	b = n;
	number = n;
	len = count(b) + (n < 0) + (n == 0);
	s = malloc(len + 1);
	if (!s)
		return (0);
	s[len] = '\0';
	if (number < 0)
		number *= -1;
	if (number == 0)
		s[0] = '0';
	while (number)
	{
		len--;
		s[len] = number % 10 + 48;
		number /= 10;
	}
	if (b < 0)
		s[0] = '-';
	return (s);
}
/*
int main()
{
	printf ("%s\n", ft_itoa(91));
	printf ("%s\n", ft_itoa(-32));
	printf ("%s\n", ft_itoa(0));
}
*/
