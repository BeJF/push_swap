/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 20:12:42 by jfinet            #+#    #+#             */
/*   Updated: 2018/11/26 14:55:36 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "unistd.h"

static int	free_all(t_struct *node)
{
	if (node->pile_a)
		free(node->pile_a);
	if (node->pile_b)
		free(node->pile_b);
	free(node);
	return (0);
}

int			put_error(t_struct *node)
{
	write(2, "Error\n", 6);
	free_all(node);
	return (1);
}

static void	call_algo(t_struct *node)
{
	int	max;

	max = get_max(node->pile_a, node->size_a);
	if (node->size_a <= 3)
		algo5data(node, max, node->size_a);
	else if (node->size_a == 5)
	{
		cond_firstcall(node, max, node->size_a);
		algo5data(node, max, node->size_a);
	}
	else if (node->size_a > 25)
		first_sort(node, node->size_a);
	else if (node->size_a <= 25)
		algo_smalltab(node, node->size_a);
}

int			main(int argc, char **argv)
{
	int			*pile_a;
	int			*pile_b;
	int			pivot;
	t_struct	*node;

	if (!(node = (t_struct*)malloc(sizeof(t_struct))))
		return (1);
	set_nul(node);
	if (argc == 2)
		if (mk_piles_2args(node, argv) == 1)
			return (put_error(node));
	if (argc > 2)
		if (mk_piles(node, argc, argv) == 1)
			return (put_error(node));
	if (check_duplicates(node) == 1)
		return (put_error(node));
	if (checkif_a_sorted(node, node->size_a) == 1)
	{
		free_all(node);
		return (0);
	}
	//print_piles(node);
	call_algo(node);
	//print_piles(node);
	free_all(node);
}
