/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_piles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:04:05 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/17 14:21:19 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"

void	print_piles(t_struct *node)
{
	int size_a;
	int size_b;
	int size_c;

	size_a = node->size_a;
	size_b = node->size_b;
	size_c = node->size_c;
	printf("=> PILE A\n");
	while (size_a--)
		printf("|%d|\n", node->pile_a[size_a]);
	printf("=> PILE B\n");
	while (size_b--)
		printf("|%d|\n", node->pile_b[size_b]);
	printf("=> PILE C\n");
	while (size_c--)
		printf("|%d|\n", node->pile_c[size_c]);
}
