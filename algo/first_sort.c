/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:08:35 by jfinet            #+#    #+#             */
/*   Updated: 2018/11/20 14:18:48 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int		check_rest2sort_a(t_struct *node, int size2sort, int pivot)
{
	int size_a;

	size_a = node->size_a;
	while (size2sort--)
	{
		if (node->pile_a[size_a - 1] <= pivot)
			return (1);
		size_a--;
	}
	return (0);
}

/*void	place_pivot()
{

}*/

static void	first_sort2(t_struct *node, int data2sort, int pivot)
{
	int data;

	printf("pivot = %d\n", pivot);
	while (data2sort > 0)
	{
		data = node->pile_a[node->size_a - 1];
		if (check_rest2sort_a(node, data2sort, pivot) == 0)
		{
			node->rotated += data2sort;
			if (node->pivot_rotated == 1)
				rev_rotate_b(node);
			print_piles(node);
			return ;
		}
		if (data > pivot)
		{
			if (data2sort > 1)
				rotate_a(node); //pas oblige de rotate si tout le reste est plus grand que pivot
			node->rotated++;
		}
		if (data <= pivot && data2sort != 0)
		{
			if (data != pivot)
			{
				push_on_b(node);
				node->pushed++;
			}
			if (data == pivot)
			{
				push_on_b(node);
				rotate_b(node);
				node->pivot_rotated = 1; //peut etre plus necessaire
			}
		}
		data2sort--;
	}
	if (node->pivot_rotated == 1)
	{
		rev_rotate_b(node);
		//push_on_a(node);
	}
	print_piles(node);
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
