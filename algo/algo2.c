/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/23 13:13:02 by jfinet            #+#    #+#             */
/*   Updated: 2018/10/06 16:03:53 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	part2(t_struct *node)
{
	int max;
	int i;
	int *pile_b;

	max = get_max(node->pile_b, node->size_b);
	i = 0;
	pile_b = node->pile_b;
	while (i < node->size_b)
	{
		if (pile_b[i] == max)
			break ;
		i++;
	}
	if (i < node->size_b / 2)
		while ((node->pile_b[node->size_b - 1] != max))
			rev_rotate_b(node);
	if (i >= node->size_b / 2)
		while ((node->pile_b[node->size_b - 1] != max))
			rotate_b(node);
	push_on_a(node);
	if (node->size_b == 0)
		return ;
	part2(node);
}

void		algo_smalltab(t_struct *node, int data2sort)
{
	int data;
	int min;
	int max;

	min = get_min(node->pile_a, data2sort);
	max = get_max(node->pile_a, data2sort);
	while (data2sort > 0)
	{
		data = node->pile_a[node->size_a - 1];
		if (data > min && data < max)
			push_on_b(node);
		else if (node->size_a > 2 && (data == min || data == max))
			rotate_a(node);
		data2sort--;
	}
	if (node->pile_a[node->size_a - 1] == min)
		swap_a(node);
	part2(node);
	rev_rotate_a(node);
}
