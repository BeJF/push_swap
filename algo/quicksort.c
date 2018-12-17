/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:31:50 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/17 12:33:08 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void ft_swap_int(int *a, int *b)
{
	int    t;

	t = *a;
	*a = *b;
	*b = t;
	return ;
}

int        ft_quicksort_util(int *tab, int low, int high)
{
	int    pivot;
	int    i;
	int    j;

	i = low - 1;
	pivot = tab[high];
	j = low;
	while (j <= high - 1)
	{
		if (tab[j] <= pivot)
		{
			i++;
			ft_swap_int(&tab[i], &tab[j]);
		}
		j++;
	}
	ft_swap_int(&tab[i + 1], &tab[high]);
	return (i + 1);
}

void    ft_quicksort(int *tab, int low, int high)
{
	int    pivot;

	if (low < high)
	{
		pivot = ft_quicksort_util(tab, low, high);
		ft_quicksort(tab, low, pivot - 1);
		ft_quicksort(tab, pivot + 1, high);
	}
	return ;
}
