/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 14:33:35 by jfinet            #+#    #+#             */
/*   Updated: 2018/11/19 15:08:55 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*int		check_rest2sort_a(t_struct *node, int size, int pivot)
{
	int size_a;

	size_a = node->size_a;
	while (size--)
	{
		if (node->pile[size_a - 1] <= pivot)
			return (1);
		size_a--;
	}
	return (0);
}*/

int		pivot_selector(int *tab, int size, int top)
{
	int i;
	int total;
	int pivot;

	i = size - 1;
	total = 0;
	while (i >= 0)
	{
		total += tab[top];
		i--;
		top--;
	}
	pivot = total / size;
	return (pivot);
}

int		checkif_b_sorted(t_struct *node, int data2sort)
{
	int *pile_b;
	int top;

	pile_b = node->pile_b;
	top = node->size_b - 1;
	while (data2sort > 1)
	{
		if (pile_b[top] < pile_b[top - 1])
			return (0);
		top--;
		data2sort--;
	}
	return (1);
}

int		checkif_a_sorted(t_struct *node, int data2sort)
{
	int *pile_a;
	int top;

	pile_a = node->pile_a - 1;
	top = node->size_a;
	while (data2sort > 1)
	{
		if (pile_a[top] > pile_a[top - 1])
			return (0);
		top--;
		data2sort--;
	}
	return (1);
}

void	set_nul(t_struct *node)
{
	node->pushed = 0;
	node->rotated = 0;
	node->rest2sort = 0;
	node->call = 1;
	node->pivot_rotated = 0;
}
