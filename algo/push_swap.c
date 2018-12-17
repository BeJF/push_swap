/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 20:12:42 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/17 14:20:39 by jfinet           ###   ########.fr       */
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
	if (argc == 1)
		return (1);
	if (argc == 2)
		if (mk_piles_2args(node, argv) == 1)
			return (put_error(node));
	if (argc > 2)
		if (mk_piles(node, argc, argv) == 1)
			return (put_error(node));
	node->pile_c = (int*)malloc(sizeof(int) * node->size_a);
	node->pile_c = ft_memcpy(node->pile_c, node->pile_a, node->size_a);
	node->size_c = node->size_a;
	ft_quicksort(node->pile_c, 0, node->size_a - 1);	
	print_piles(node);
	if (check_duplicates(node) == 1)
		return (put_error(node));
	if (checkif_a_sorted(node, node->size_a) == 1)
	{
		free_all(node);
		return (0);
	}
	call_algo(node);
	free_all(node);
}
