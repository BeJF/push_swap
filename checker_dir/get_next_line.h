/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfinet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/25 12:21:00 by jfinet            #+#    #+#             */
/*   Updated: 2018/09/10 14:15:47 by jfinet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 10

typedef struct		s_line
{
	int				fd;
	char			*str;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);
char				*ft_strdup(const char *s1);
char				*ft_strsub(const char *s1, size_t start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strlen(char *s);
char				*ft_strjoinup(char *s1, char *s2, int i);
void				ft_putstr(char *str);
#endif
