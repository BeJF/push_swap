/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 08:18:06 by jfinet            #+#    #+#             */
/*   Updated: 2018/12/07 09:12:06 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int		*make_small_pile(int *pile, int len, int top)
{
	int		*small_pile;

	small_pile = (int*)malloc(sizeof(int) * len);
	len -= 1;
	while (len >= 0)
		small_pile[len--] = pile[top--];
	return (small_pile);
}

static int		*sort_pile(int *pile, int len)
{
	int	i;
	int	temp_value;

	i = 0;
	while (i < len - 1)
	{
		if (pile[i] > pile[i + 1])
		{
			temp_value = pile[i];
			pile[i] = pile[i + 1];
			pile[i + 1] = temp_value;
			i = 0;
		}
		else
			i++;
	}
	return (pile);
}

int				get_median(int *pile, int len, int top)
{
	int	*small_pile;
	int	median;

	small_pile = make_small_pile(pile, len, top);
	sort_pile(small_pile, len);
	median = small_pile[(len - 1) / 2];
	free(small_pile);
	return (median);
}
