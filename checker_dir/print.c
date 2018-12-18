/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 17:04:49 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/18 17:07:33 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	print_piles(t_struct *node, FILE *file)
{
	int size_a;
	int size_b;

	size_a = node->size_a;
	size_b = node->size_b;
	while (size_a--)
		fprintf(file, "%d ", node->pile_a[size_a]);
	fprintf(file, "\n");
	while (size_b--)
		fprintf(file, "%d ", node->pile_b[size_b]);
	fprintf(file, "\n");
}
