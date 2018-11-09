/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 02:01:48 by jfinet            #+#    #+#             */
/*   Updated: 2018/06/19 17:47:06 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
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
		tab[i] = (*f)(s[i]);
		i++;
	}
	return (tab);
}
