/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 19:02:35 by jfinet            #+#    #+#             */
/*   Updated: 2018/11/20 19:06:44 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"


static int		check_rest2sort_a(t_struct *node, int size2sort, int pivot)
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

static void	sort3data2(t_struct *node)
{
	int *tab;
	int top;
	int swap;

	tab = node->pile_a;
	top = node->size_a - 1;
	swap = 0;
	if (tab[top - 1] > tab[top - 2])
		swap = 1;
	swap_a(node);
	rotate_a(node);
	swap_a(node);
	rev_rotate_a(node);
	if (swap == 1)
		swap_a(node);
}

static void	sort3data(t_struct *node)
{
	int *tab;
	int top;
	int swap;

	tab = node->pile_a;
	top = node->size_a - 1;
	swap = 0;
	if (tab[top - 2] > tab[top - 1] && tab[top - 2] > tab[top])
		swap_a(node);
	else if (tab[top - 1] > tab[top] && tab[top - 1] > tab[top - 2])
	{
		if (tab[top] > tab[top - 2])
			swap = 1;
		rotate_a(node);
		swap_a(node);
		rev_rotate_a(node);
		if (swap == 1)
			swap_a(node);
	}
	else if (tab[top] > tab[top - 1] && tab[top] > tab[top - 2])
		sort3data2(node);
}

static int	sort_smallparts_a(t_struct *node, int data2sort)
{
	int *tab;
	int top;

	tab = node->pile_a;
	top = node->size_a - 1;
	if (checkif_a_sorted(node, data2sort) == 1)
		data2sort = 0;
	if (data2sort == 3)
	{
		sort3data(node);
		data2sort = 0;
	}
	if (data2sort == 2)
	{
		if (node->pile_a[top] > node->pile_a[top - 1])
			swap_a(node);
		data2sort = 0;
	}
	return (data2sort);
}

static void	sort_on_a2(t_struct *node, int data2sort, int pivot)
{
	int data;

	//printf("pivot on a = %d\n", pivot);
	while (data2sort > 0)
	{
		data = node->pile_a[node->size_a - 1];
		if (check_rest2sort_a(node, data2sort, pivot) == 0)
		{
			//node->rotated += data2sort;
			//printf("going to return\n");
			if (node->pivot_rotated == 1)
				rev_rotate_b(node);
			node->rest2sort += data2sort;
			while (node->rotated--)
				rev_rotate_a(node);
			return ;
		}
		if (data > pivot)
		{
			if (data2sort > 2) //revoir les 2 conditions avec nouvelle fct check
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
			if (data != pivot)
			{
				push_on_b(node);
				node->pushed++;
			}
			if (data == pivot)
			{
				push_on_b(node);
				rotate_b(node);
				node->pivot_rotated = 1; //pe plus necessaire
			}
		}
		data2sort--;
	}
	//print_piles(node);
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
	pivot = pivot_selector(node->pile_a, data2sort, node->size_a - 1);
	data2sort = sort_smallparts_a(node, data2sort);
	sort_on_a2(node, data2sort, pivot);
	pushed = node->pushed;
	if (node->pushed == 0)
		return ;
	if (node->rest2sort > 1)
		sort_on_a(node, node->rest2sort);
	sort_on_b(node, pushed, 1);
}
