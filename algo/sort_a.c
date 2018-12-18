/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:02:35 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/18 17:13:41 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	sort_on_a3(t_struct *node, int data2sort, int pivot, int data)
{
	if (data > pivot)
	{
		if (data2sort > 2)
		{
			rotate_a(node);
			node->rotated++;
		}
		if (data2sort == 2)
			swap_a(node);
		node->rest2sort++;
	}
	if (data <= pivot && data2sort != 0)
	{
		push_on_b(node);
		if (data != pivot)
			node->pushed++;
		if (data == pivot)
		{
			rotate_b(node);
			node->pivot_rotated = 1;
		}
	}
}

static void	sort_on_a2(t_struct *node, int data2sort, int pivot)
{
	int data;

	while (data2sort > 0)
	{
		data = node->pile_a[node->size_a - 1];
		if (check_rest2sort_a(node, data2sort, pivot) == 0)
		{
			if (node->pivot_rotated == 1)
				rev_rotate_b(node);
			node->rest2sort += data2sort;
			while (node->rotated--)
				rev_rotate_a(node);
			return ;
		}
		sort_on_a3(node, data2sort, pivot, data);
		data2sort--;
	}
	if (node->pivot_rotated == 1)
		rev_rotate_b(node);
	while (node->rotated--)
		rev_rotate_a(node);
}

void		sort_on_a(t_struct *node, int data2sort)
{
	int pivot;
	int pushed;

	set_nul(node);
	pivot = get_median(node->pile_a, data2sort, node->size_a - 1);
	data2sort = sort_smallparts_a(node, data2sort);
	sort_on_a2(node, data2sort, pivot);
	pushed = node->pushed;
	if (node->pushed == 0)
		return ;
	if (node->rest2sort > 1)
		sort_on_a(node, node->rest2sort);
	sort_on_b(node, pushed, 1);
}
