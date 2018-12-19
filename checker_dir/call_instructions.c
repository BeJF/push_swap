/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 12:49:15 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/19 14:00:43 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	call_instructions2(char *line, t_struct *node)
{
	if (ft_strcmp("ss", line) == 0 && node->size_a >= 2 && node->size_b >= 2)
	{
		swap_a(node);
		swap_b(node);
		return (0);
	}
	else if (ft_strcmp("rr", line) == 0)
	{
		rotate_a(node);
		rotate_b(node);
		return (0);
	}
	else if (ft_strcmp("rrr", line) == 0)
	{
		rev_rotate_a(node);
		rev_rotate_b(node);
		return (0);
	}
	return (1);
}

int	call_instructions(char *line, t_struct *node)
{
	int ret;

	ret = 0;
	if (ft_strcmp("sa", line) == 0 && node->size_a >= 2)
		swap_a(node);
	else if (ft_strcmp("sb", line) == 0 && node->size_b >= 2)
		swap_b(node);
	else if (ft_strcmp("pa", line) == 0 && node->size_b >= 1)
		push_on_a(node);
	else if (ft_strcmp("pb", line) == 0 && node->size_a >= 1)
		push_on_b(node);
	else if (ft_strcmp("ra", line) == 0)
		rotate_a(node);
	else if (ft_strcmp("rb", line) == 0)
		rotate_b(node);
	else if (ft_strcmp("rra", line) == 0)
		rev_rotate_a(node);
	else if (ft_strcmp("rrb", line) == 0)
		rev_rotate_b(node);
	else
		ret = call_instructions2(line, node);
	return (ret);
}
