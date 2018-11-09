/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_minmax.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 17:28:35 by jfinet            #+#    #+#             */
/*   Updated: 2018/10/04 21:03:59 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		get_max(int *tab, int data2sort)
{
	int max;
	int i;
	int z;

	max = tab[0];
	i = data2sort;
	z = data2sort - 1;
	while (i > 0)
	{
		if (tab[z] > max)
			max = tab[z];
		i--;
		z--;
	}
	return (max);
}

int		get_min(int *tab, int data2sort)
{
	int min;
	int i;
	int z;

	min = tab[0];
	i = data2sort;
	z = data2sort - 1;
	while (i > 0)
	{
		if (tab[z] < min)
			min = tab[z];
		i--;
		z--;
	}
	return (min);
}

int		get_max2(int *tab, int data2sort, int max)
{
	int max2;
	int i;
	int z;

	z = data2sort - 1;
	max2 = get_min(tab, data2sort);
	i = data2sort;
	if (max2 == max)
		max2 = tab[1];
	while (i > 0)
	{
		if (tab[z] > max2 && tab[z] < max)
			max2 = tab[z];
		i--;
		z--;
	}
	return (max2);
}
