/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 20:35:15 by jfinet            #+#    #+#             */
/*   Updated: 2018/10/04 21:03:23 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	algo3(t_struct *node)
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
	algo3(node);
}
