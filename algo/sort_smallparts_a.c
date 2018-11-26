/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_smallparts_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:11:33 by jfinet            #+#    #+#             */
/*   Updated: 2018/11/26 14:54:43 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

int			sort_smallparts_a(t_struct *node, int data2sort)
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
