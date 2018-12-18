/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:04:05 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/18 17:16:56 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"

void	print_piles(t_struct *node)
{
	int size_a;
	int size_b;

	size_a = node->size_a;
	size_b = node->size_b;
	printf("=> PILE A\n");
	while (size_a--)
		printf("|%d|\n", node->pile_a[size_a]);
	printf("=> PILE B\n");
	while (size_b--)
		printf("|%d|\n", node->pile_b[size_b]);
}
