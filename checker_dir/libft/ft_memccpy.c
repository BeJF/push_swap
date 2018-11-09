/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 15:41:16 by jfinet            #+#    #+#             */
/*   Updated: 2018/06/19 17:41:53 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*cdst;
	const unsigned char		*csrc;
	unsigned char			x;

	cdst = (unsigned char*)dst;
	csrc = (const unsigned char*)src;
	x = c;
	while (n-- > 0)
		if ((*cdst++ = *csrc++) == x)
			return (cdst);
	return (NULL);
}
