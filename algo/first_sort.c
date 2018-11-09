/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:08:35 by jfinet            #+#    #+#             */
/*   Updated: 2018/10/04 23:23:47 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	first_sort2(t_struct *node, int data2sort, int pivot)
{
	int data;

	while (data2sort > 0)
	{
		data = node->pile_a[node->size_a - 1];
		if (data > pivot)
		{
			if (data2sort > 1)
				rotate_a(node);
			node->rotated++;
		}
		if (data <= pivot && data2sort != 0)
		{
			push_on_b(node);
			node->pushed++;
		}
		data2sort--;
	}
}

void		first_sort(t_struct *node, int data2sort)
{
	int pivot;
	int pushed;
	int max;

	max = get_max(node->pile_a, data2sort);
	set_nul(node);
	pivot = pivot_selector(node->pile_a, data2sort, node->size_a - 1);
	if (data2sort <= 6)
	{
		algo5data(node, max, data2sort);
		data2sort = 0;
	}
	first_sort2(node, data2sort, pivot);
	pushed = node->pushed;
	if (node->pushed == 0)
		return ;
	if (node->pushed >= 2)
		first_sort(node, node->rotated);
	sort_on_b(node, pushed);
}
