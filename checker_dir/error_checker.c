/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 12:50:44 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/12 18:59:02 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_errors_atoi(int data, char *arg)
{
	if (data == 0)
	{
		if (ft_strlen(arg) > 1)
			return (1);
	}
	if (data == -1)
	{
		if (ft_strlen(arg) > 2)
			return (1);
	}
	return (0);
}

int	check_duplicates(t_struct *node)
{
	int *pile_a;
	int size_a;
	int i;
	int z;
	int data;

	i = 0;
	z = 0;
	pile_a = node->pile_a;
	size_a = node->size_a - 1;
	while (z < size_a)
	{
		data = pile_a[z];
		printf("data = %d\n", data);
		while (i <= size_a)
		{
			if (data == pile_a[i] && i != z)
			{
				printf("data = %c\n", data);
				printf("bug de merde\n");
				return (1);
			}
			i++;
		}
		i = 0;
		z++;
	}
	return (0);
}
