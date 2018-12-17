/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 14:31:56 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/17 10:21:33 by jfinet           ###   ########.fr       */
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


static int	read_instructions(t_struct *node)
{
	char	*line;
	int		fd;
	FILE	*file;
	
	//if (node->flag_visu == 1)
	file = fopen("piles", "w");
	fd = 0;
	line = NULL;
	while (get_next_line(fd, &line))
	{
		//if (node->flag_visu == 1)
		print_piles(node, file);
		if (call_instructions(line, node) == 1)
			return (1);
	}
	//if (node->flag_visu == 1)
	//{
	print_piles(node, file);
	fclose(file);
	//}
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
	/*if (argv[1][0] == '-' && argv[1][1] == 'v')
	{
		node->flag_visu = 1;
		argv[1] += 3;
		//printf("pos = %c\n", *argv[1]);
		argc -= 1;
	}*/
	if (argc == 2)
	{
		if (mk_piles_2args(node, argv) == 1)
			return (put_error(node));
	}
	printf("bug1\n");
	if (argc > 2)
		if (mk_piles(node, argc, argv) == 1)
			return (put_error(node));
	printf("bug2\n");
	if (check_duplicates(node) == 1)
		return (put_error(node));
	printf("bug3\n");
	if (read_instructions(node) == 1)
		return (put_error(node));
	if (checkif_a_sorted(node, node->size_a) == 1 && node->size_b == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	//if (node->flag_visu == 1)
	//	system("python3 visu.py");
	return (free_all(node));
}
