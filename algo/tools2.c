/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 13:41:11 by jfinet            #+#    #+#             */
/*   Updated: 2018/11/26 13:43:50 by jfinet           ###   ########.fr       */
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

int		check_rest2sort_b(t_struct *node, int size2sort, int pivot)
{
	int size_b;

	size_b = node->size_b;
	while (size2sort--)
	{
		if (node->pile_b[size_b - 1] >= pivot)
			return (1);
		size_b--;
	}
	return (0);
}
