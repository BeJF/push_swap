/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 22:58:58 by jfinet            #+#    #+#             */
/*   Updated: 2018/06/20 16:15:06 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_list;
	t_list	*tmp;

	if (lst == NULL)
		return (ft_lstnew(NULL, 0));
	tmp = (*f)(lst);
	begin_list = tmp;
	lst = lst->next;
	while (lst)
	{
		tmp->next = (*f)(lst);
		lst = lst->next;
		tmp = tmp->next;
	}
	return (begin_list);
}
