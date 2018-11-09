/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 20:32:16 by jfinet            #+#    #+#             */
/*   Updated: 2018/06/15 00:04:22 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ucs1;
	unsigned char	*ucs2;

	ucs1 = (unsigned char*)s1;
	ucs2 = (unsigned char*)s2;
	while (n--)
	{
		if ((*ucs1) == (*ucs2))
		{
			ucs1++;
			ucs2++;
		}
		else
			return (*ucs1 - *ucs2);
	}
	return (0);
}
