/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo5data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 20:30:48 by jfinet            #+#    #+#             */
/*   Updated: 2018/10/04 23:23:31 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	find_position(t_struct *node, int data)
{
	int pos;
	int *pile_a;

	pos = 0;
	pile_a = node->pile_a;
	while (pos < node->size_a)
	{
		if (pile_a[pos] == data)
			break ;
		pos++;
	}
	return (pos);
}

void		cond_firstcall(t_struct *node, int max, int data2sort)
{
	int max2;
	int pos_max;
	int pos_max2;
	int *pile_a;

	max2 = get_max2(node->pile_a, data2sort, max);
	pos_max = find_position(node, max);
	pos_max2 = find_position(node, max2);
	pile_a = node->pile_a;
	if (pos_max < node->size_a / 2 && pos_max2 == pos_max - 1)
	{
		while (node->pile_a[node->size_a - 1] != max)
			rev_rotate_a(node);
		swap_a(node);
	}
	if (pos_max >= node->size_a / 2 && pos_max2 == pos_max - 1)
	{
		while (node->pile_a[node->size_a - 1] != max)
			rotate_a(node);
		swap_a(node);
	}
	if (pos_max == node->size_a - 1)
		rotate_a(node);
}

void		algo5data(t_struct *node, int max, int data2sort)
{
	int max2;
	int pos_max;
	int pos_max2;

	max2 = get_max2(node->pile_a, data2sort, max);
	pos_max = find_position(node, max);
	pos_max2 = find_position(node, max2);
	while (node->pile_a[pos_max2 - 1] != max)
	{
		if (pos_max2 < pos_max && pos_max2 < node->size_a / 2)
			while ((node->pile_a[node->size_a - 1] != max2))
				rev_rotate_a(node);
		else
			while ((node->pile_a[node->size_a - 1] != max2))
				rotate_a(node);
		pos_max = find_position(node, max);
		pos_max2 = find_position(node, max2);
		if (node->pile_a[pos_max2 - 1] != max)
			swap_a(node);
		pos_max = find_position(node, max);
		pos_max2 = find_position(node, max2);
	}
	if (max2 == get_min(node->pile_a, node->size_a))
		return ;
	algo5data(node, max2, data2sort);
}
