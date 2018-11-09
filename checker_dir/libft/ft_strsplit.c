/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:24:47 by jfinet            #+#    #+#             */
/*   Updated: 2018/06/20 19:41:31 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *s, char c)
{
	int	i;
	int	m;

	i = 0;
	m = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			m++;
			while (s[i] != c && s[i])
				i++;
		}
		while (s[i] == c && s[i])
			i++;
	}
	return (m);
}

static int		ft_word_length(char const *s, char c)
{
	size_t i;

	i = 0;
	while (*s && *s != c)
	{
		i++;
		s++;
	}
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	m;
	char	**tab;

	i = 0;
	if (!s)
		return (NULL);
	m = ft_count_words(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * (m + 1))))
		return (NULL);
	while (m--)
	{
		while (*s == c && *s != '\0')
			s++;
		if (!(tab[i] = ft_strsub(s, 0, ft_word_length(s, c))))
			return (NULL);
		s += ft_word_length(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
