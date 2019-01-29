/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/11 00:20:28 by jfinet            #+#    #+#             */
/*   Updated: 2019/01/29 15:05:44 by jfinet           ###   ########.fr       */
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
	if (size_a < 2)
		return ;
	temp = pile_a[size_a - 1];
	pile_a[size_a - 1] = pile_a[size_a - 2];
	pile_a[size_a - 2] = temp;
}

void	swap_b(t_struct *node)
{
	int *pile_b;
	int size_b;
	int temp;

	pile_b = node->pile_b;
	size_b = node->size_b;
	if (size_b < 2)
		return ;
	temp = pile_b[size_b - 1];
	pile_b[size_b - 1] = pile_b[size_b - 2];
	pile_b[size_b - 2] = temp;
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
	if (size_a < 1)
		return ;
	pile_b[size_b] = pile_a[size_a - 1];
	pile_a[size_a - 1] = 0;
	node->size_a--;
	node->size_b++;
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
	if (size_b < 1)
		return ;
	pile_a[size_a] = pile_b[size_b - 1];
	pile_b[size_b - 1] = 0;
	node->size_b--;
	node->size_a++;
}
