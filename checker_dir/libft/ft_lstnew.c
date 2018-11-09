/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 18:40:47 by jfinet            #+#    #+#             */
/*   Updated: 2018/06/20 15:46:48 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	void	*tab;
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->next = NULL;
		new->content_size = 0;
		return (new);
	}
	if (!(tab = malloc(sizeof(content))))
		return (NULL);
	new->content = ft_memcpy(tab, content, content_size);
	new->content_size = content_size;
	new->next = NULL;
	return (new);
}
