/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 20:13:10 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/28 20:48:49 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	*new_tab(int size)
{
	int *tab;

	if (!(tab = (int*)malloc(sizeof(int) * size)))
		return (NULL);
	while (size--)
		tab[size] = '\0';
	return (tab);
}
