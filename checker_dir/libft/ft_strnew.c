/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 00:45:56 by jfinet            #+#    #+#             */
/*   Updated: 2018/06/18 12:57:02 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*tab;

	tab = (char*)malloc(sizeof(char) * size + 1);
	if (tab == NULL)
		return (NULL);
	ft_bzero(tab, size + 1);
	return (tab);
}
