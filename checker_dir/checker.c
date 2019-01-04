/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:31:56 by jfinet            #+#    #+#             */
/*   Updated: 2019/01/04 16:43:37 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	read_instructions(t_struct *node)
{
	char	*line;
	int		fd;
	//FILE	*file;

	//file = fopen("piles", "w");
	fd = 0;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		//print_piles(node, file);
		if (call_instructions(line, node) == 1)
		{
			free(line);
			//fclose(file);
			return (1);
		}
		free(line);
	}
	//print_piles(node, file);
	//fclose(file);
	return (0);
}

static int	checkif_a_sorted(t_struct *node, int data2sort)
{
	int *pile_a;
	int top;

	pile_a = node->pile_a - 1;
	top = node->size_a;
	while (data2sort > 1)
	{
		if (pile_a[top] > pile_a[top - 1])
			return (0);
		top--;
		data2sort--;
	}
	return (1);
}

static int	free_all(t_struct *node)
{
	if (node->pile_a)
		free(node->pile_a);
	if (node->pile_b)
		free(node->pile_b);
	free(node);
	return (0);
}

static int	put_error(t_struct *node)
{
	write(2, "Error\n", 6);
	free_all(node);
	return (1);
}

int			main(int argc, char **argv)
{
	int			*pile_a;
	int			*pile_b;
	t_struct	*node;

	if (argc == 1)
		return (1);
	if (!(node = (t_struct*)malloc(sizeof(t_struct))))
		return (1);
	if (argc == 2)
		if (mk_piles_2args(node, argv) == 1)
			return (put_error(node));
	if (argc > 2)
		if (mk_piles(node, argc, argv) == 1)
			return (put_error(node));
	if (check_duplicates(node) == 1)
		return (put_error(node));
	if (read_instructions(node) == 1)
		return (put_error(node));
	if (checkif_a_sorted(node, node->size_a) == 1 && node->size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	return (free_all(node));
}
