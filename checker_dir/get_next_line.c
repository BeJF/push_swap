/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/24 15:59:26 by jfinet            #+#    #+#             */
/*   Updated: 2018/10/04 23:33:10 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_line	*mano(t_line *begin, char *str, const int fd)
{
	t_line	*node;
	t_line	*temp;

	if (!(node = (t_line*)malloc(sizeof(t_line))))
		return (NULL);
	node->fd = fd;
	node->str = str;
	node->next = NULL;
	if (begin == NULL)
		return (node);
	temp = begin;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
	return (begin);
}

static char		*get_line(char **str)
{
	char	reader[2];
	char	*temp;
	char	*test;

	test = ft_strdup("");
	while (**str != '\n' && **str != '\0')
	{
		if (!test)
			test = ft_strdup("");
		temp = test;
		reader[0] = **str;
		reader[1] = '\0';
		test = ft_strjoin(test, reader);
		free(temp);
		(*str)++;
	}
	if (**str == '\n')
		(*str)++;
	return (test);
}

static void		free_node(t_line **begin, int fd)
{
	t_line *temp;
	t_line *delete;

	temp = (*begin);
	while (temp)
	{
		if (temp->fd == fd)
		{
			delete = temp;
			if (temp->next != NULL)
				temp = temp->next;
			else
				begin = NULL;
			free(delete);
			return ;
		}
		if (temp->next->fd == fd)
		{
			delete = temp->next;
			temp->next = temp->next->next;
			free(delete);
			return ;
		}
		temp = temp->next;
	}
}

static int		find_fd(int fd, t_line *begin, char **line)
{
	t_line *temp;

	temp = begin;
	if (begin != NULL)
	{
		while (temp)
		{
			if (temp->fd == fd)
			{
				if (*temp->str == '\0')
				{
					free_node(&begin, fd);
					return (0);
				}
				*line = get_line(&temp->str);
				return (1);
			}
			temp = temp->next;
		}
	}
	return (2);
}

int				get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	char			*stock;
	char			*tmpstock;
	static t_line	*begin = NULL;

	if (fd < 0 || line == NULL)
		return (-1);
	if ((ret = find_fd(fd, begin, line)) != 2)
		return (ret);
	stock = NULL;
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		stock = (!stock ? ft_strdup("") : stock);
		tmpstock = stock;
		stock = ft_strjoinup(stock, buf, ret);
		free(tmpstock);
	}
	if (stock == NULL)
		return (0);
	*line = get_line(&stock);
	begin == NULL ? begin = mano(begin, stock, fd) : mano(begin, stock, fd);
	return (1);
}
