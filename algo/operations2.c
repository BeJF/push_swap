/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 16:01:40 by jfinet            #+#    #+#             */
/*   Updated: 2018/10/06 13:01:47 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	rotate_a(t_struct *node)
{
	int temp;
	int *pile_a;
	int size_a;

	pile_a = node->pile_a;
	size_a = node->size_a;
	temp = pile_a[size_a - 1];
	while (size_a > 1)
	{
		pile_a[size_a - 1] = pile_a[size_a - 2];
		size_a--;
	}
	pile_a[0] = temp;
	write(1, "ra\n", 3);
}

void	rotate_b(t_struct *node)
{
	int temp;
	int *pile_b;
	int size_b;

	pile_b = node->pile_b;
	size_b = node->size_b;
	temp = pile_b[size_b - 1];
	while (size_b > 1)
	{
		pile_b[size_b - 1] = pile_b[size_b - 2];
		size_b--;
	}
	pile_b[0] = temp;
	write(1, "rb\n", 3);
}

void	rev_rotate_b(t_struct *node)
{
	int *pile_b;
	int size_b;
	int temp;
	int i;

	pile_b = node->pile_b;
	size_b = node->size_b;
	i = 0;
	temp = pile_b[0];
	while (i < size_b)
	{
		pile_b[i] = pile_b[i + 1];
		i++;
	}
	pile_b[size_b - 1] = temp;
	write(1, "rrb\n", 4);
}

void	rev_rotate_a(t_struct *node)
{
	int *pile_a;
	int size_a;
	int temp;
	int i;

	pile_a = node->pile_a;
	size_a = node->size_a;
	i = 0;
	temp = pile_a[0];
	while (i < size_a)
	{
		pile_a[i] = pile_a[i + 1];
		i++;
	}
	pile_a[size_a - 1] = temp;
	write(1, "rra\n", 4);
}
