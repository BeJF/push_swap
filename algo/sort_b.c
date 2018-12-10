/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:59:46 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/07 09:43:41 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	sort_on_b3(t_struct *node, int data2sort, int pivot)
{
	if (data2sort > 2)
	{
		rotate_b(node);
		node->rotated++;
	}
	if (data2sort == 2)
		swap_b(node);
	node->rest2sort++;
}

static void	sort_on_b2(t_struct *node, int data2sort, int pivot)
{
	int data;

	if (data2sort < 15 && data2sort == node->size_b)
	{
		algo3(node);
		data2sort = 0;
	}
	while (data2sort > 0)
	{
		data = node->pile_b[node->size_b - 1];
		if (check_rest2sort_b(node, data2sort, pivot) == 0)
		{
			node->rest2sort += data2sort;
			return ;
		}
		if (data >= pivot)
		{
			push_on_a(node);
			node->pushed++;
		}
		if (data < pivot)
			sort_on_b3(node, data2sort, pivot);
		data2sort--;
	}
}

void		sort_on_b(t_struct *node, int data2sort, int pivot_top)
{
	int pivot;
	int rest2sort;

	set_nul(node);
	if (pivot_top == 1)
		push_on_a(node);
	pivot = pivot_selector(node->pile_b, data2sort, node->size_b - 1);
	if (data2sort == node->size_b)
		node->call = 0;
	sort_on_b2(node, data2sort, pivot);
	rest2sort = node->rest2sort;
	while (node->rotated-- > 0 && node->call == 1)
		rev_rotate_b(node);
	if (node->pushed >= 2)
		sort_on_a(node, node->pushed);
	if (rest2sort == 0)
		return ;
	if (rest2sort > 0)
		sort_on_b(node, rest2sort, 0);
}
