/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 16:05:19 by jfinet            #+#    #+#             */
/*   Updated: 2018/06/17 20:14:35 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = ft_strlen(needle);
	if (i == 0)
		return ((char*)haystack);
	while (*haystack != '\0' && len-- >= i)
	{
		if (ft_memcmp(haystack++, needle, i) == 0)
			return ((char*)haystack - 1);
	}
	return (NULL);
}
