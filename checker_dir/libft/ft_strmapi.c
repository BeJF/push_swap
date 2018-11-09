/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 13:10:12 by jfinet            #+#    #+#             */
/*   Updated: 2018/06/20 13:13:30 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tab;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	tab = ft_strnew(ft_strlen(s));
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		tab[i] = (*f)(i, s[i]);
		i++;
	}
	return (tab);
}
