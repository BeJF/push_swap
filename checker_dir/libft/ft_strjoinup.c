/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 20:21:18 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/19 15:43:19 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoinup(char *s1, char *s2, int ret)
{
	char *tab;

	if (!s1 || !s2)
		return (0);
	s2[ret] = '\0';
	tab = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (tab == NULL)
		return (NULL);
	tab = ft_strcat(tab, s1);
	tab = ft_strcat(tab, s2);
	return (tab);
}
