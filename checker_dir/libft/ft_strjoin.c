/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:34:47 by jfinet            #+#    #+#             */
/*   Updated: 2018/06/19 17:46:52 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *tab;

	if (!s1 || !s2)
		return (0);
	tab = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (tab == NULL)
		return (NULL);
	tab = ft_strcat(tab, s1);
	tab = ft_strcat(tab, s2);
	return (tab);
}
