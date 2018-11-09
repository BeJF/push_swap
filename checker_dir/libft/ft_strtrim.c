/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:16:11 by jfinet            #+#    #+#             */
/*   Updated: 2018/06/20 17:46:59 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	f;
	size_t	l;
	char	*tab;

	i = 0;
	f = 0;
	l = 0;
	if (!s)
		return (0);
	l = ft_strlen(s);
	while (s[l - 1] == ' ' || s[l - 1] == '\n' || s[l - 1] == '\t')
		l--;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == ft_strlen(s) || !s)
		return (ft_strdup(""));
	f = l - i;
	tab = ft_strnew(f);
	if (tab == NULL)
		return (NULL);
	tab = ft_strsub(s, i, f);
	tab[l] = '\0';
	return (tab);
}
