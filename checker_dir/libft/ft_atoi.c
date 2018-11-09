/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 18:23:37 by jfinet            #+#    #+#             */
/*   Updated: 2018/10/04 19:37:42 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				neg;
	unsigned long	nb;

	nb = 0;
	neg = 1;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
		if (nb > 2147483647 && neg == 1)
			return (-1);
		else if (nb > 2147483648 && neg == -1)
			return (0);
	}
	if (*str != ' ' && *str != '\0')
		return (-1);
	return ((int)(nb * neg));
}
