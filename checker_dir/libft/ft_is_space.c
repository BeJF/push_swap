/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 11:15:04 by jfinet            #+#    #+#             */
/*   Updated: 2018/06/22 11:22:17 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_space(const char *str)
{
	if (*str == '\t' || *str == '\v' || *str == '\n' ||
		*str == '\r' || *str == '\f' || *str == ' ')
		return (1);
	else
		return (0);
}
