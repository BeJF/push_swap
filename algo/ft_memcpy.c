/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 20:37:29 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/17 14:08:38 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			*cdst;
	const int	*csrc;

	cdst = (int*)dst;
	csrc = (const int*)src;
	while (n--)
		*cdst++ = *csrc++;
		//*dst++ = *src;
	return (dst);
}
