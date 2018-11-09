/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 15:22:28 by jfinet            #+#    #+#             */
/*   Updated: 2018/06/17 20:15:34 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;

	i = ft_strlen(needle);
	if (i == 0)
		return ((char*)haystack);
	while (*haystack)
	{
		if (ft_memcmp(haystack++, needle, i) == 0)
			return ((char*)haystack - 1);
	}
	return (0);
}
