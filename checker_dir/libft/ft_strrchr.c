/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 14:59:23 by jfinet            #+#    #+#             */
/*   Updated: 2018/06/17 16:06:52 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	int			i;
	const char	*t;

	t = NULL;
	i = 1 + ft_strlen(s);
	if (ft_strlen(s) == 0)
		return (0);
	while (i != 0)
	{
		if (*s == (char)c)
			t = s;
		i--;
		s++;
	}
	if (t == 0)
		return (0);
	else
		return ((char*)t);
}
