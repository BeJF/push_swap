/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_piles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 13:55:10 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/17 10:55:44 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	count_arg(char **argv)
{
	int nb_data;
	int z;

	nb_data = 0;
	z = 0;
	while (argv[1][z] != '\0')
	{
		if (argv[1][z] >= '0' && argv[1][z] <= '9')
			nb_data++;
		while (argv[1][z] >= '0' && argv[1][z] <= '9')
			z++;
		while (argv[1][z] == ' ' || argv[1][z] == 9
		|| argv[1][z] == '-' || argv[1][z] == '+')
			z++;
	}
	return (nb_data);
}

int	only_nb_checker(char **argv, int arg)
{
	int z;

	z = 0;
	while (argv[arg][z] != '\0')
	{
		if ((argv[arg][z] < '0' || argv[arg][z] > '9')
		&& argv[arg][z] != '-' && argv[arg][z] != '\0'
		&& argv[arg][z] != ' ' && argv[arg][z] != '+')
			return (1);
		if ((argv[arg][z] == '-' || argv[arg][z] == '+')
		&& (argv[arg][z + 1] < '0' || argv[arg][z + 1] > '9'))
			return (1);
		z++;
	}
	return (0);
}

int	arg_to_tab(t_struct *node, char **argv, int nb_data)
{
	char	str[12];
	int		i;

	i = 0;
	while (*argv[1] != '\0')
	{
		while (*argv[1] == ' ' || *argv[1] == 9)
			(argv[1]++);
		while ((*argv[1] >= 48 && *argv[1] <= 57)
		|| *argv[1] == '-' || *argv[1] == '+')
		{
			str[i] = *argv[1];
			i++;
			(argv[1]++);
			if (i == 11)
				return (1);
		}
		str[i] = '\0';
		node->pile_a[nb_data - 1] = ft_atoi(str);
		if (check_errors_atoi(node->pile_a[nb_data - 1], str) == 1)
			return (1);
		nb_data--;
		i = 0;
	}
	return (0);
}

int	mk_piles_2args(t_struct *node, char **argv)
{
	int nb_data;

	node->pile_a = NULL;
	node->pile_b = NULL;
	if (only_nb_checker(argv, 1) == 1)
		return (1);
	nb_data = count_arg(argv);
	node->size_b = 0;
	node->size_a = nb_data;
	node->pile_a = new_tab(nb_data);
	node->pile_b = new_tab(nb_data);
	if (arg_to_tab(node, argv, nb_data) == 1)
		return (1);
	return (0);
}

int	mk_piles(t_struct *node, int argc, char **argv)
{
	int size;

	size = 0;
	node->size_b = 0;
	node->size_a = argc - 1;
	node->pile_a = new_tab(argc);
	node->pile_b = new_tab(argc);
	while (argc > 1)
	{
		if (only_nb_checker(argv, argc - 1) == 1)
			return (1);
		node->pile_a[size] = ft_atoi(argv[argc - 1]);
		if (check_errors_atoi(node->pile_a[size], argv[argc - 1]) == 1)
			return (1);
		size++;
		argc--;
	}
	return (0);
}
