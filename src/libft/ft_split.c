/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misikogl <misikogl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 23:40:45 by misikogl          #+#    #+#             */
/*   Updated: 2023/09/06 03:51:12 by misikogl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_next_charset(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	ft_count_words(const char *s, char c)
{
	char	pre_c;
	size_t	i;

	i = 0;
	pre_c = c;
	while (*s)
	{
		if (pre_c == c && *s != c)
			i++;
		pre_c = *s;
		s++;
	}
	return (i);
}

char	**ft_split(const char *s, char c)
{
	char	**s_tab;
	size_t	next_charset;
	size_t	i;

	if (s == NULL)
		return (NULL);
	s_tab = malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (s_tab == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
		next_charset = ft_next_charset(s, c);
		if (next_charset)
		{
			s_tab[i] = ft_substr(s, 0, next_charset);
			s += next_charset;
			i++;
		}
		else
			s++;
	}
	s_tab[i] = NULL;
	return (s_tab);
}
/*
#include <stdio.h>
int        main(void)
{
    int i = 0;
    char **tab;
        
    tab = ft_split(",,,,,,,dasd,,,,,,ad,,,,,,,,ds,,,,,da,,,asd,,,,", ',');
    while (i < 4)
    {
        printf("string %d : %s\n", i, tab[i]);
        i++;
    }
    return (0);
} 
*/
