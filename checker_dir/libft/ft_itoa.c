/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 20:34:23 by jfinet            #+#    #+#             */
/*   Updated: 2018/06/19 17:43:51 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_get_len(int n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char				*ft_itoa(int n)
{
	size_t			c;
	char			*tab;
	unsigned int	temp;

	c = ft_get_len(n);
	temp = n;
	if (n < 0)
	{
		c++;
		temp = -n;
	}
	if (!(tab = ft_strnew(c)))
		return (NULL);
	tab[--c] = temp % 10 + '0';
	while (temp /= 10)
		tab[--c] = temp % 10 + '0';
	if (n < 0)
		tab[0] = '-';
	return (tab);
}
