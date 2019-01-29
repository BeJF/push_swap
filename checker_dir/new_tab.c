/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 20:13:10 by jfinet            #+#    #+#             */
/*   Updated: 2019/01/29 14:40:07 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	*new_tab(int size)
{
	int *tab;

	if (!(tab = (int*)malloc(sizeof(int) * (size + 1))))
		return (NULL);
	while (size >= 0)
	{
		tab[size] = '\0';
		size--;
	}
	return (tab);
}
