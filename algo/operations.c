/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 00:20:28 by jfinet            #+#    #+#             */
/*   Updated: 2018/10/04 23:17:31 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	swap_a(t_struct *node)
{
	int *pile_a;
	int size_a;
	int temp;

	pile_a = node->pile_a;
	size_a = node->size_a;
	temp = pile_a[size_a - 1];
	pile_a[size_a - 1] = pile_a[size_a - 2];
	pile_a[size_a - 2] = temp;
	write(1, "sa\n", 3);
}

void	swap_b(t_struct *node)
{
	int *pile_b;
	int size_b;
	int temp;

	pile_b = node->pile_b;
	size_b = node->size_b;
	temp = pile_b[size_b - 1];
	pile_b[size_b - 1] = pile_b[size_b - 2];
	pile_b[size_b - 2] = temp;
	write(1, "sb\n", 3);
}

void	push_on_b(t_struct *node)
{
	int *pile_a;
	int *pile_b;
	int size_a;
	int size_b;

	pile_a = node->pile_a;
	size_a = node->size_a;
	pile_b = node->pile_b;
	size_b = node->size_b;
	pile_b[size_b] = pile_a[size_a - 1];
	pile_a[size_a - 1] = '\0';
	node->size_a--;
	node->size_b++;
	write(1, "pb\n", 3);
}

void	push_on_a(t_struct *node)
{
	int *pile_a;
	int *pile_b;
	int size_a;
	int size_b;

	pile_a = node->pile_a;
	size_a = node->size_a;
	pile_b = node->pile_b;
	size_b = node->size_b;
	pile_a[size_a] = pile_b[size_b - 1];
	pile_b[size_b - 1] = '\0';
	node->size_b--;
	node->size_a++;
	write(1, "pa\n", 3);
}
