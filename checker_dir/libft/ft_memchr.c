/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:48:36 by jfinet            #+#    #+#             */
/*   Updated: 2018/06/17 22:18:55 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*csrc;

	csrc = (unsigned char*)s;
	while (n--)
	{
		if ((*csrc) != (unsigned char)c)
			csrc++;
		else
			return (csrc);
	}
	return (NULL);
}
